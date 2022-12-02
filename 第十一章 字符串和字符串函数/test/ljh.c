#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <Windows.h>

int selet_radom(int number);
char * say_hello(char *m1, char *prep, char *verb, char *m2);
int copy_to_board(char * str);

int main(void){
    char *names[] = {
        "小红","小军","小兰","小花"
    };
    char *prep[] = {
        "在地板上","腾空","在树枝上","在厨房里"
    };
    char *verb[] = {
        "踢","撞","咬","摇"
    };
    char *objects[] = {
        "狗屎","尿","粪","书桌"
    };
    char temp[9999];
    while (getchar()!='q'){
        strcpy(temp,say_hello(
            names[selet_radom(4)],
            prep[selet_radom(4)],
            verb[selet_radom(4)],
            objects[selet_radom(4)]
            ));
        copy_to_board(temp);
    }
}

int selet_radom(int number){
    return (int)rand()%(number-1);
}

char * say_hello(char *m1, char *prep, char *verb, char *m2){
    static char tem[99999];
    strcat(strcat(strcat(strcpy(tem,m1),prep),verb),m2);
    printf("%s",tem);
    return tem;
}

int copy_to_board(char * str)
{
 HGLOBAL hMemory;
 LPTSTR lpMemory;
 char * content = str;   // 待写入数据
 int contentSize = strlen(content) + 1;

 if(!OpenClipboard(NULL))    // 打开剪切板，打开后，其他进程无法访问
 {
  puts("剪切板打开失败");
  return 1;
 }

 if(!EmptyClipboard())       // 清空剪切板，写入之前，必须先清空剪切板
 {
  puts("清空剪切板失败");
  CloseClipboard();
  return 1;
 }

 if((hMemory = GlobalAlloc(GMEM_MOVEABLE, contentSize)) == NULL)    // 对剪切板分配内存
 {
  puts("内存赋值错误!!!");
  CloseClipboard();
  return 1;
 }

 if((lpMemory = (LPTSTR)GlobalLock(hMemory)) == NULL)             // 将内存区域锁定
 {
  puts("锁定内存错误!!!");
  CloseClipboard();
  return 1;
 }

 memcpy_s(lpMemory, contentSize, content, contentSize);   // 将数据复制进入内存区域

 GlobalUnlock(hMemory);                   // 解除内存锁定

 if(SetClipboardData(CF_TEXT, hMemory) == NULL)
 {
  puts("设置剪切板数据失败!!!");
  CloseClipboard();
  return 1;
 }
 CloseClipboard();

}

