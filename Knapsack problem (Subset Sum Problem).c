#include <stdio.h>
#include <stdbool.h>
#include <mem.h>

void brute(int arr[], int arr_size, int sum){
    bool solution[arr_size+1][sum + 1];
    for (int i = 1; i <= sum; ++i){
        solution[0][i] = false;
    }
    for (int i = 0; i <= arr_size; ++i){
        solution[i][0] = true;
    }
    for (int i = 1; i <= arr_size; ++i){
        for (int j = 1; j <= sum; ++j){
            solution[i][j] = solution[i-1][j];
            if ((!solution[i][j]) && (j >= arr[i-1])){
                solution[i][j] = solution[i][j] || solution[i-1][j-arr[i-1]];
            }
        }
    }
    /*for (int i = 0; i < arr_size+1; ++i){
        for (int j = 0; j <= sum; ++j){
            printf("%c ",(solution[i][j]) ? '1' : '0');
        }
        printf("\n");
    }*/
    if (!((solution[arr_size][sum]))){
     printf("%d",-1);
        return;
    }
    int tsum = sum; int q = arr_size; int w = sum; bool res[arr_size];
    for (int i = 0; i < arr_size; ++i) res[i] = false;
    while (tsum != 0){
        while(!solution[q][w]) w--;
        if (!solution[q-1][w]){
            res[q-1] = true;
            tsum -= arr[q-1];
            while (w != tsum) w--;
        } else q--;
    }
    for (int i = 0; i < arr_size; ++i) printf("%d ",res[i]);
}

int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,w;
    scanf("%d %d /n", &n, &w);
    int a[n];
    for (int i = 0; i < n; ++i) scanf("%d ", &a[i]);
    brute(a,n,w);
    return 0;
}
