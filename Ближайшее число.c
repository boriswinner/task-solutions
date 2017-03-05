#include <stdio.h>
#include <malloc.h>

long int* arr;
long int* ans;//number of answer
int main() {
    FILE *in = fopen("input.txt", "r");
    FILE *out = fopen("output.txt", "w");
    long int N = 0;
    fscanf(in, "%ld", &N);
    arr = malloc(N * sizeof(long int));
    ans = malloc(N * sizeof(long int));
    for (long int i = 0; i < N; ++i){
        fscanf(in, "%ld", &arr[i]);
    }
    fclose(in);
    for (long int i = N-1; i >= 0; --i){
        ans[i] = i;
        long int j = i+1;
        while (j < N){
            if (arr[j] < arr[i]){
                j = ans[j];
            }
            if (arr[j] > arr[i]) {
                ans[i] = j;
                break;
            }
            if (arr[j] == arr[i]){
                ans[i] = ans[j];
                break;
            }
            if (ans[j] == j) break;
        }
    }
    for (long int i = 0; i < N; ++i){
        fprintf(out,"%ld ",arr[ans[i]]);
    }
    fclose(out);
    return 0;
}
