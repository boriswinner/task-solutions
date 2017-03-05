#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#define inf 1000000001
 
int* arr;
int* lans;
int* rans;
 
int min(int a, int b){
    if (a <= b) return(a); else return(b);
}
 
int main() {
    FILE *in = fopen("input.txt", "r");
    FILE *out = fopen("output.txt", "w");
    int N = 0;
    fscanf(in, "%d", &N);
    arr = malloc(N * sizeof(int));
    lans = malloc(N * sizeof(int));
    rans = malloc(N * sizeof(int));
    for (int i = 0; i < N; ++i){
        fscanf(in, "%d", &arr[i]);
    }
    fclose(in);
 
    /* 1. Поиск бОльшего числа справа */
    for (int i = N-1; i >= 0; --i){
        rans[i] = i;
        int j = i+1;
        while (j < N){
            if (arr[j]<arr[i]){
                j = rans[j];
            }
            if (arr[j] > arr[i]) {
                rans[i] = j;
                break;
            }
            if (arr[j] == arr[i]){
                if (rans[j] == j) rans[i] = i; else rans[i] = rans[j];
                break;
            }
            if (rans[j] == j) break;
        }
    }
 
    /* 2. Поиск бОльшего числа слева */
    for (int i = 0; i <= N-1; ++i){
        lans[i] = i;
        int j = i-1;
        while (j >= 0){
            if (arr[j]<arr[i]){
                j = lans[j];
            }
            if (arr[j] > arr[i]) {
                lans[i] = j;
                break;
            }
            if (arr[j] == arr[i]){
                if (lans[j] == j) lans[i] = i; else lans[i] = lans[j];
                break;
            }
            if (lans[j] == j) break;
        }
    }
 
    /*3. Обработка данных для получения ответа*/
    for (int i = 0; i < N; ++i){
        int r1, r2, res;
        if ((i == rans[i]) || (i == N-1)) r2 = inf;
        if (i < rans[i])  r2 = rans[i] - i - 1;
        if ((i == lans[i]) || (i == 0)) r1 = inf;
        if (i > lans[i])  r1 = i - lans[i] - 1;
        res = 1 + min(r1, r2);
        if (rans[i] == lans[i]) res = 0;
        fprintf(out,"%d ",res);
    }
    fclose(out);
    return 0;
}
