#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#define size 100000
 
typedef struct deque{
    int* values;
    int* indexes;
    int l, r;
} deque;
 
void push_back(deque* adeque, int val, int i){
    adeque->r++;
    adeque->indexes[adeque->r] = i;
    adeque->values[adeque->r] = val;
}
 
int pop_front(deque* adeque){
    adeque->l++;
    return(adeque->values[adeque->l-1]);
}
 
int pop_back(deque* adeque){
    adeque->r--;
    return(adeque->values[adeque->r+1]);
}
 
int ihead(deque* adeque){
    return(adeque->indexes[adeque->l]);
}
 
int end(deque* adeque){
    return(adeque->values[adeque->r]);
}
 
bool empty(deque* adeque){
    return(adeque->l > adeque-> r);
}
 
int main() {
    deque maximals = {malloc(size * sizeof(int)), malloc(size * sizeof(int)), 0, -1};
    FILE *in = fopen("input.txt", "r");
    FILE *out = fopen("output.txt", "w");
    int* arr = malloc(size * sizeof(int));
    int n;
    fscanf(in,"%d",&n);
 
    for (int i = 0; i < n; ++i){
        fscanf(in,"%d",&arr[i]);
    }
 
    int m;
    fscanf(in,"%d\n",&m);
    char c;
    push_back(&maximals,arr[0], 0);
    int l = 0,r = 0;
    for (int i = 0; i < m; ++i){
        fscanf(in,"%c",&c);
        switch (c){
            case 'L':{
                if (ihead(&maximals) == l)
                    pop_front(&maximals);
                l++;
            } break;
            case 'R':{
                r++;
                while ((end(&maximals) < arr[r]) && (!empty(&maximals)))
                    pop_back(&maximals);
                push_back(&maximals,arr[r], r);
            } break;
        }
        fprintf(out,"%d ",maximals.values[maximals.l]);
    }
    fclose(in);
    fclose(out);
    return 0;
}
