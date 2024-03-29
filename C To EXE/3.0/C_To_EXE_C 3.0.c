#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define INFO_TYPE "INFO"
#define cmd_command_lenght 50
#define cmd_argument_lenght 950
#define cmd_lenght 1000

char code_path[500];
char code_name[50];
char exe_path[500];
char exe_name[50];
char home_path[500];
int code_path_init = 1; // value 1 means that the variable is inited

void format_print(char *message, char *message_type, char *message_sourse);
void print_hello(void);
void print_help(void);
char * input(char *in_message, int lenght);
void split_two(char *str1, char *str2, int lenght1, int lenght2);
void init_path(void);
void update_path(char *path);
void remove_quotation(char *path);
void run(char *exefile, char *argument);
void compile(void);
void open_dir(void);
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
        strcpy(code_path,argv[1]);
        init_path();
        format_print("code path inited\n",INFO_TYPE,mes_sourse);
    }

    while (1){
        printf("\n>>");
        input(cmd,cmd_lenght);
        cmd_match(cmd);
    }

}

void cmd_match(char *cmd){
    char mes_sourse[] = "cmd_match";

    char command[cmd_command_lenght];
    strncpy(command,cmd,cmd_command_lenght-1);
    char argument[cmd_argument_lenght];
    split_two(command,argument,cmd_command_lenght,cmd_argument_lenght);

    if (strcmp(command,"h")==0){
        format_print("run \"print_help\" function\n",INFO_TYPE,mes_sourse);
        print_help();

    } else if ((strcmp(command,"\\")==0) ||
                (strcmp(command,"��")==0))
    {   
        format_print("run \"compile\" function\n",INFO_TYPE,mes_sourse);
        compile();

    } else if ((strncmp(command+1,":\\",2)==0) || 
                (strncmp(command+2,":\\",2)==0)) 
    {
        format_print("run \"update_path\" function\n",INFO_TYPE,mes_sourse);
        update_path(cmd);
    
    } else if (strcmp(command,"r")==0){
        format_print("run \"remove\" function\n",INFO_TYPE,mes_sourse);
        remove(exe_path);
    
    } else if (strcmp(command,"c")==0){
        format_print("run \"cmd\" function\n",INFO_TYPE,mes_sourse);
        system("start cmd");
    
    } else if (strcmp(command,"d")==0){
        format_print("run \"open_dir\" function\n",INFO_TYPE,mes_sourse);
        open_dir();
    
    } else if (strcmp(command,"a")==0){
        //have BUG
        run(exe_path, argument);

    } else if (strcmp(command,"q")==0){
        exit(0);

    } else {
        if (code_path_init){
            run(exe_path,NULL);
        } else {
            format_print("Code path loss, please update path\n","ERR",mes_sourse);
        }
    }
    //} else if (strcmp(command,"")==0){
}

void open_dir(void){
    //explorer "{}"
    char ncmd[cmd_lenght] = {};
    strcat(strcat(strcat(ncmd,"explorer \""),home_path),"\"");
    printf("%s",ncmd);
    system(ncmd);
}

void compile(void){
    //cmd = r"""gcc -o "{}" "{}" """.
    char mes_sourse[] = "compile";
    format_print("Start Compile\n",INFO_TYPE,mes_sourse);

    char ncmd[cmd_lenght] = {};
    strcat(strcat(strcat(strcat(strcat(
        ncmd,"gcc -o \""),exe_path),"\" \""),code_path),"\"");
    system(ncmd);

    format_print("Compile Finish\n",INFO_TYPE,mes_sourse);
}

void run(char *exefile, char *argument){
    char mes_sourse[] = "run";
    char ncmd[cmd_lenght] = {};
    system("cls");
    format_print("running test exe program\n",INFO_TYPE,mes_sourse);

    if (argument){
        // Super Big BUG 
        remove_quotation(argument);
        strcat(strcat(strcat(ncmd,"\""),exefile),"\"");
        strcat(strcat(strcat(ncmd," \""),argument),"\"");
    } else {
        strcat(ncmd,"\"");
        strcat(ncmd,exefile);
        strcat(ncmd,"\"");
    }

    printf("\n\n------ RUNNING TESE ------\n");
    printf("Code: %s\n",code_name);
    printf("EXE: %s\n\n",exe_name);
    printf("----- START -----\n\n");
    //printf("cmd = %s\n",cmd);
    //printf("ncmd = %s\n",ncmd);
    printf("cmdn =%s\n",ncmd);
    system(ncmd);
    printf("\n\n------ END ------\n\n");
    format_print("exe file Stop\n",INFO_TYPE,mes_sourse);
}

void update_path(char *path){
    strcpy(code_path,path);
    init_path();
    code_path_init = 1;
}

void init_path(void){
    // this function is used to build exe name and path.
    // you must update the "code_path" to make it work.
    remove_quotation(code_path);
    int i = 0;
    while (code_path[++i]!='\0') continue;
    while (code_path[--i]!='\\') continue;
    code_path[i] = '\0';
    strcpy(home_path,code_path);
    strcpy(code_name,code_path+i+1);
    code_path[i] = '\\';

    int name_location = i;
    while (code_path[++i]!='.') continue;
    code_path[i] = '\0';
    strcpy(exe_name,code_path+name_location+1);
    code_path[i] = '.';
    strcat(exe_name,".exe");

    code_path[name_location] = '\0';
    strcpy(exe_path,code_path);
    code_path[name_location] = '\\';
    strcat(exe_path,"\\");
    strcat(exe_path,exe_name);
}

void remove_quotation(char *path){
    int i = 0;
    while (code_path[++i]!='\0') continue;
    if ((path[0]=='\"')&&(path[i-1]=='\"')){
        int cont;
        for (cont=0; cont<i; cont++){
            path[cont] = path[cont+1];
        }
        path[cont-1] = path[cont];
    }
}

void split_two(char *str1, char *str2, int lenght1, int lenght2){
    int i=0;
    for (i=0; i<(lenght1+lenght2); i++){
        if (str1[i] == '\0'){
            i = -1;
            break;
        }
        if (str1[i] == ' '){
            str1[i] = '\0';
            break;
        }
    } 
    strcpy(str2,str1+i+1);
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
    printf("\n   C To EXE C V3.0 Help\n\n");
    printf("   [None] ---- run exe file\n");
    printf("   [path] ---- change C code\n");
    printf("   \\ --------- compile C file to exe\n");
    printf("   a(BUG) --------- run exe file include arguments\n");
    printf("   r --------- remove the exe file\n");
    printf("   c --------- open cmd\n");
    printf("   d --------- open code path\n");
    printf("   q --------- quit\n\n");
}

void print_hello(void){
    printf("\n      C To EXE C V3.0\n");
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