#include <stdio.h>
#include <stdlib.h>

typedef struct list{
    int val;
    struct list* next;
} list;

void listadd(list* prev, int val){
    list* tmp = (list*)(malloc(sizeof(list)));
    tmp->val = val;

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
    hashtable->elem[i] = malloc()
}

int main()
{
    printf("Hello world!\n");
    return 0;
}

// http://learnc.info/adt/linked_list.html
// http://algolist.manual.ru/ds/s_has.php
// https://gist.github.com/tonious/1377667
