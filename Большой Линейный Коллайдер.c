#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
   
#define stacksize 200000
   
typedef struct particle{
    int x, u;
} particle;
   
typedef struct stack{
    particle data[stacksize];
    int size;
} stack;
   
void push(stack* astack, int ax, int au){
    astack->data[astack->size].x = ax;
    astack->data[astack->size].u = au;
    astack->size++;
}
   
void pop(stack* astack){
    astack->size--;
}
   
bool empty(stack* astack){
    return(astack->size <= 0);
}
   
particle peek(stack* astack){
    return (astack->data[astack->size - 1]);
}
   
int compare (const void * a, const void * b)
{
    if (*(double*)a > *(double*)b) return 1;
    else if (*(double*)a < *(double*)b) return -1;
    else return 0;
}
   
double coltimes[stacksize];
int scoltimes = 0; //size of colparticles
int infcnt = 0; //Р   Р вЂ™Р’В±Р   Р вЂ™Р’ВµР  Р Р‹Р  РЎвЂњР   Р РЋРІР‚СњР   Р РЋРІР‚СћР   Р  РІР‚В¦Р   Р вЂ™Р’ВµР  Р Р‹Р Р†Р вЂљР Р‹Р   Р  РІР‚В¦Р   Р РЋРІР‚Сћ Р   Р вЂ™Р’В¶Р   Р РЋРІР‚пїЅР   Р  РІР‚ Р  Р Р‹Р РЋРІР‚СљР  Р Р‹Р Р†Р вЂљР’В°Р   Р РЋРІР‚пїЅР   Р вЂ™Р’Вµ Р  Р Р‹Р Р†Р вЂљР Р‹Р   Р вЂ™Р’В°Р  Р Р‹Р  РЎвЂњР  Р Р‹Р Р†Р вЂљРЎв„ўР   Р РЋРІР‚пїЅР  Р Р‹Р Р†Р вЂљ Р  Р Р‹Р Р†Р вЂљРІвЂћвЂ“
int n, m;
int tx, tu;
   
int main() {
    FILE *in = fopen("linear.in","r");
    FILE *out = fopen("linear.out","w");
    fscanf(in,"%d",&n);
    stack particles = {0,0};
    for (int i = 0; i < n; ++i){
        fscanf(in, "%d %d", &tx, &tu);
        if (tu == 1) push(&particles, tx, tu);
        else if (!empty(&particles)) {
            coltimes[scoltimes] = fabs((peek(&particles).x - tx)/2.0);
            coltimes[scoltimes+1] = coltimes[scoltimes];
            scoltimes += 2;
            pop(&particles);
        }
        else infcnt++;
    }
    infcnt += particles.size;
    qsort(&coltimes,scoltimes,sizeof(double),compare);
    fscanf(in,"%d", &m);
    int t[m];
    for (int i = 0; i < m; ++i){
        fscanf(in, "%d", &t[i]);
    }
    int l = 0;
    for (int i = 0; i < m; ++i){
        while ((coltimes[l] <= t[i] ) && (l < scoltimes)){
            l += 2;
            n -= 2;
        }
        fprintf(out,"%d", n);
        if (i < m-1) fprintf(out,"\n");
    }
    /*fprintf(out,"%d ",particles.size);
    fprintf(out,"%d ",infcnt);
    for (int i = 0; i < scoltimes; ++i){
        fprintf(out,"%f ",coltimes[i]);.
    }*/
    fclose(in);
    fclose(out);
    return 0;
}
