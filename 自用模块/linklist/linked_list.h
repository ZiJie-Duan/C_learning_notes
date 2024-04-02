#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct Node {
    void * data;
    struct Node * next;
} NODE;

typedef struct Linked_List {
    NODE * head;
    NODE * tail;
} LINKED_LIST;

LINKED_LIST * initLinkList(void);


NODE * link_search_by_index(LINKED_LIST *list, int index);
NODE * link_search_by_data(LINKED_LIST *list, void * data);
int addNode(LINKED_LIST *list, void * data); //head to tail orderd
int insertNode(LINKED_LIST *list, void * data, int index); //insert by index
void * popNode(LINKED_LIST *list, int index); //defult tail to head, or pop by index
int delNode(LINKED_LIST *list, void *data); //del node by data

#endif