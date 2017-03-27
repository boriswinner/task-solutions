#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct list{
    int val;
    struct list *next;
} list;

list* listadd(list* head, int val){
    list *tmp = (list*)(malloc(sizeof(list)));
    tmp->val = val;
    tmp->next = &head;
    return(tmp);
}

void listdelete(list* head, int val){
    list* i = head;
    list* prev = i;
    while ((i->next != NULL) || (i->val != val)){
        prev = i;
        i = prev->next;
    }
    prev->next = i->next;
}

void listprint(list* head){
    list* i = head;
    printf("%d ", i->val);
    printf("%p ", i->next);
    printf("%d \n", (i->next == NULL));
    /* *i = *(i->next);
    printf("%d ", i->val);
    printf("%p ", i->next);
    printf("%d ", (i->next == NULL));*/
    /*while ((i->next) != NULL){
        printf("%d ", i->val);
        i = i->next;
    }*/
}

typedef struct hashtable{
    int size;
    list* elem;
} hashtable;

int hashfunction(int key, int size){
    return(32 * key + 17) % size;
}

void htadd(hashtable* atable, int key){
    int i = hashfunction(key, atable->size);
    //hashtable->elem[i] = malloc()
}

int main()
{
    list *testlist = NULL;
    testlist = listadd(testlist,1);
    testlist = listadd(testlist,2);
    listprint(testlist);
    printf("Hello world!\n");
    return 0;
}

// http://learnc.info/adt/linked_list.html
// http://algolist.manual.ru/ds/s_has.php
// https://gist.github.com/tonious/1377667
