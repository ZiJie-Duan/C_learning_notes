#include "Hash_dict.h"

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
    Hash_dict hdict = (Hash_dict)malloc(Hash_Size *sizeof(Hash_node));
    for (int i=0; i<Hash_Size; i++){
        hdict[i].key = NULL;
    }
    return hdict;
}

void hdict_add(const char *key, void *value, Hash_dict hdict){
    int index = hash_convert(key);

    if (hdict[index].key == NULL){
        //different key
        hdict[index].key = key;
        hdict[index].value = value;
        hdict[index].next = NULL;

    } else {
        //same keys, use linked table
        Hash_node * tmp = &(hdict[index]);
        while(tmp->next != NULL) {tmp = tmp->next; continue;}
        Hash_node *node = malloc(sizeof(Hash_node));
        node->key = key;
        node->value = value;
        node->next = NULL;
        tmp->next = node;
    }
}

void hdict_print(Hash_dict hdict){
    for(int i=0; i<Hash_Size; i++){
        if (hdict[i].key != NULL){
            printf("\nARR: %s : %s", hdict[i].key, hdict[i].value);
            
            if (hdict[i].next != NULL){
                Hash_node *tmp = &hdict[i];
                while(tmp->next != NULL){
                    tmp = tmp->next;
                    printf("\nLINKED: %s : %s", tmp->key, tmp->value);
                }
            }
        }
    }
}

void * hdict_search(const char *key, Hash_dict hdict){
    if (strcmp(key,(hdict[hash_convert(key)]).key) == 0){
        return hdict[hash_convert(key)].value;
    } else {
        Hash_node *tmp = &hdict[hash_convert(key)];
        while(tmp->next != NULL){
            tmp = tmp->next;
            if (strcmp(key,tmp->key) == 0){
                return tmp->value;
            } else {
                return NULL;
            }
        }
    }
}

int test_function_add (int x, int y){
    return x + y;
}

int main (void){
    Hash_dict hdict = hdict_create();
    hdict_add("Peter Duan", "Happy Every Day", hdict);
    hdict_add("Ethan Li", "Good Luck!", hdict);
    hdict_add("Ethan Li", "EXT GOOD Luck!", hdict);
    hdict_print(hdict);
    
    hdict_add("test", &test_function_add, hdict);
    printf("\n\ntest1: %s",(char *)hdict_search("Peter Duan",hdict));
    int (*func) (int, int) = hdict_search("test",hdict);
    printf("\ntest2: %d",func(1,2));
    getchar();
}