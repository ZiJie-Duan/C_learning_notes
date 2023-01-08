#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct dict {
    char *key;
    void *value;
    struct dict *next;
};

struct dict * dic_init(void);
int dic_add(struct dict *dic, char *key, void *value);
int dic_del(struct dict *dic, char *key);
void dic_find(struct dict *dic, char *key);
void dic_print(struct dict *dic);

int main(void){
    struct dict *dic1 = dic_init();
    dic_add(dic1,"cat","300");
    dic_add(dic1,"dog","309");
    dic_add(dic1,"cola","38");
    dic_add(dic1,"chocolate","66");

    dic_print(dic1);

    dic_del(dic1,"dog");
    dic_add(dic1,"bird","99");
    dic_print(dic1);
    getchar();
}

struct dict * dic_init(void){
    struct dict *tmp = malloc(sizeof(struct dict));
    tmp->key = "head";
    tmp->value = "head";
    tmp->next = NULL;
    return tmp;
}

int dic_add(struct dict *dic, char *key, void *value){

    while(dic->next != NULL){
        dic = dic->next;
    }
    struct dict *page = malloc(sizeof(struct dict));
    page->key = key;
    page->value = value;
    page->next = NULL;
    dic->next = page;
}

int dic_del(struct dict *dic, char *key){
    struct dict *last;
    struct dict *next;
    struct dict *del_page;
    do{ 
        last = dic;
        dic = dic->next;
        next = dic->next;
        if (strcmp(dic->key,key)==0){
            last->next = next;
            del_page = dic;
            return 0;
        }
    } while(dic->next != NULL);

    if (strcmp(dic->key,key)){
        last->next = next;
        del_page = dic;
        return 0;
    } else {
        return 1;
    }
}

void dic_find(struct dict *dic, char *key){
    do{
        dic = dic->next;
        printf("\n%s : %s", dic->key, dic->value);
    } while(dic->next != NULL);
    printf("\n\n");
}

void dic_print(struct dict *dic){
    do{
        dic = dic->next;
        printf("\n%s : %s", dic->key, dic->value);
    } while(dic->next != NULL);
    printf("\n\n");
}