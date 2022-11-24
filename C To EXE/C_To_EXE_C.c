#include <stdio.h>
#include <string.h>

#define INFO_TYPE "INFO"
#define cmd_command_lenght 10
#define cmd_argument_lenght 10
#define cmd_lenght 20

char code_path[500];
char code_name[50];
char exe_path[500];
char exe_name[50];
int code_path_init = 1; // value 1 means that the variable is inited

void format_print(char *message, char *message_type, char *message_sourse);
void print_hello(void);
void print_help(void);
char * input(char *in_message, int lenght);
void cmd_match(char *cmd);

int main(int argc , char* argv[]){

    char mes_sourse[] = "main";
    char cmd[cmd_lenght]; 
    print_hello();

    format_print("program init...\n",INFO_TYPE,mes_sourse);
    if ((argc < 2) || (argv[1] == NULL)){
        code_path_init = 0;
        format_print("code path missed\n","WARN",mes_sourse);
    } else {
        format_print("code path inited\n",INFO_TYPE,mes_sourse);
    }

    while (1){
        printf("\n>>");
        input(cmd,cmd_lenght);
        cmd_match(cmd);
    }

}

void cmd_match(char *cmd){
    int i;
    for (i=0; ;i++){
        if (cmd[i] == '\0'){
            i = -1;
            break;
        }
        if (cmd[i] == ' '){
            cmd[i] = '\0';
            break;
        }
    } 
    char cmd_command[cmd_command_lenght];
    char cmd_argument[cmd_argument_lenght];
    strcpy(cmd_command,cmd);
    cmd[i+cmd_argument_lenght] = '\0';
    strcpy(cmd_argument,cmd+i+1);

    if (strcmp(cmd_command,"h")==0){
        print_help();
    } else {
        printf("\nok\n");
    }
    //} else if (strcmp(cmd_command,"")){
}

char * input(char *in_message, int lenght){
    int i = 0;
    char temp;
    while(((temp = getchar()) !='\n')&&(i < lenght-1)){
        in_message[i] = temp;
        i ++;
    }
    if (temp != '\n'){
        while(getchar()!='\n') {continue;}
    }
    temp = '\0';
    in_message[i] = temp;
}

void print_help(void){
    printf("\n   C To EXE C V2.0 Help\n\n");
    printf("   [None] ---- run exe file\n");
    printf("   [path] ---- change C code\n");
    printf("   \\ --------- compile C file to exe\n");
    printf("   k --------- kill the exe program\n");
    printf("   r --------- remove the exe file\n");
    printf("   c --------- open cmd\n");
    printf("   p --------- open code path\n");
    printf("   q --------- quit\n\n");
}

void print_hello(void){
    printf("\n      C To EXE C V2.0\n");
    printf("   Compilation Assistant\n\n");
}

void format_print(char *message, char *message_type, char *message_sourse){
    if (strcmp(message_type,"ERR")==0){
        printf("\n[%s](%s): %s",message_type,message_sourse,message);
        printf("[%s](%s): %s",message_type,message_sourse,"Press Enter To Continue...");
        getchar();
    } else if (strcmp(message_type,"WARN")==0){
        printf("[%s](%s): %s",message_type,message_sourse,message);
    } else {
        printf("[%s](%s): %s",message_type,message_sourse,message);
    }
}