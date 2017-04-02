#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#define HASHSIZE 9369319
#define SEQSIZE 1000000

typedef struct listnode_ {
    int val;
    struct listnode_ *next;
} listnode;

typedef struct list_ {
    listnode *start;
} list;

void listadd(list* alist, int val){
    listnode* i = alist->start;
    while (i != NULL) {
        if (i->val == val)
            return;
        i = i-> next;
    }
    listnode *tmp = (listnode*)(malloc(sizeof(listnode)));
    tmp->val = val;
    tmp->next = alist->start;
    alist->start = tmp;
}

void listdelete(list* alist, int val){
    if (alist->start == NULL) return;
    listnode* i = alist->start;
    if (i->val == val) {
        alist->start = i->next;
        return;
    }
    listnode* prev = i;
    while (i != NULL) {
        if (i->val == val){
            prev->next = i->next;
        }
        prev = i;
        i = prev->next;
    }
}

void listget(list* head, int* arr, int* cnt){
    listnode* i = head->start;
    while (i != NULL){
        (*cnt)++;
        arr[*cnt] = (i->val);
        i = i->next;
    }
}

typedef struct hashtable{
    list elem[HASHSIZE];
} hashtable;

int hashfunction(int key, int size){
    return(31 * key + 17) % size;
}

void htadd(hashtable* atable, int key){
    int i = hashfunction(key, HASHSIZE);
    listadd(&(*atable).elem[i], key);
}

void htremove(hashtable* atable, int key){
    int i = hashfunction(key, HASHSIZE);
    listdelete(&(*atable).elem[i], key);
}

void hashprint(hashtable* atable, int* arr, int* cnt){
    for (int i = 0; i < HASHSIZE; ++i){
        listget(&(atable->elem[i]), arr, cnt);
    }
}

int cmpfunc (const void * a, const void * b) {
    return ( *(int*)a - *(int*)b );
}

int sortedarr[SEQSIZE];
int isortedarr = -1, a;
hashtable ht;

int main()
{
    FILE *in = fopen("input.txt", "r");
    FILE *out = fopen("output.txt", "w");
    while ( (fscanf(in, "%d", &a) != EOF) && (a != 0) ){
        (a > 0) ? htadd(&ht, a) : htremove(&ht, -a);
    }
    hashprint(&ht, &sortedarr[0], &isortedarr);
    qsort(sortedarr, isortedarr+1, sizeof(int), cmpfunc);
    for (int i = 0; i <= isortedarr; ++i){
        fprintf(out, "%d ", sortedarr[i]);
    }
    return 0;
}
