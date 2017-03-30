#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct listnode_ {
    int val;
    struct listnode_ *next;
} listnode;

typedef struct list_ {
    listnode *start;
} list;

void listadd(list* alist, int val){
    listnode *tmp = (listnode*)(malloc(sizeof(listnode)));
    tmp->val = val;
    tmp->next = alist->start;
    alist->start = tmp;
}

void listdelete(list* alist, int val){
    listnode* i = alist->start;
    listnode* prev = i;
    while ((i != NULL) && (i->val != val)) {
        prev = i;
        i = prev->next;
    }
    if (i->val == val){
        prev->next = i->next;
        free(i);
    }
}

void listprint(list* head){
    listnode* i = head->start;
    while (i != NULL){
        printf("%d ", i->val);
        i = i->next;
    }
}

typedef struct hashtable{
    int size;
    list elem;
} hashtable;

int hashfunction(int key, int size){
    return(32 * key + 17) % size;
}

void htadd(hashtable* atable, int key){
    int i = hashfunction(key, atable->size);
    listadd(hashtable[i].elem,key);
}

int main()
{
    list testlist = {NULL};
    listadd(&testlist,1);
    listadd(&testlist,2);
    listadd(&testlist,3);
    listdelete(&testlist,2);
    listprint(&testlist);
    printf("Hello world!\n");
    return 0;
}

// http://learnc.info/adt/linked_list.html
// http://algolist.manual.ru/ds/s_has.php
// https://gist.github.com/tonious/1377667
