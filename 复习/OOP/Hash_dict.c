#include "Hash_dict.h"
#include <stdio.h>
#include <stdlib.h>

extern const int Hash_Size;

int hash_convert(const char * string){
    unsigned int total = 0;
    while(*string != '\0'){
        total += (int)*string;
        string ++;
    }
    return total % Hash_Size;
}

Hash_dict hdict_create(void){
    Hash_dict hdict = malloc(Hash_Size *sizeof(Hash_dict));
    return hdict;
}

void hash_linked_add(const char *key, void *value, int index, Hash_dict hdict){
    Hash_node * tmp = &(hdict[index]);
    while(tmp->next != NULL) continue;
    Hash_node node = {.key=key, .value=value, .next=NULL};
    tmp->next = &node;
}

void hdict_add(const char *key, void *value, Hash_dict hdict){
    int index = hash_convert(key);

    if (hdict[index].key){
        hdict[index].key = key;
        hdict[index].value = value;
        hdict[index].next = NULL;
    } else {
        hash_linked_add(key,value,index,hdict);
    }
}

void hdict_print(Hash_dict hdict){
    for(int i=0; i<Hash_Size; i++){
        if (hdict[i].key != NULL){
            
            printf("%s : %s", hdict[i].key, hdict[i].value);
            Hash_node *tmp = hdict[i].next;

            while(hdict[i].next != NULL){
                tmp = tmp->next;
                printf("%s : %s", hdict[i].key, hdict[i].value);
            }
        }
    }
}

int main (void){
    Hash_dict hdict = hdict_create();
    hdict_add("hello word", "hahahahaha", hdict);
    hdict_print(hdict);
    getchar();
}