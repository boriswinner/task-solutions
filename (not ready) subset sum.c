#include <stdio.h>
#include <stdbool.h>
#include <mem.h>

#define ARRSIZE(x)  (sizeof(x) / sizeof((x)[0]))

int brute(int arr[], size_t arr_size, int sum){
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
    for (int i = 0; i < arr_size+1; ++i){
        for (int j = 0; j <= sum; ++j){
            printf("%c ",(solution[i][j] == true) ? '1' : '0');
        }
        printf("\n");
    }
    int tsum = sum; int q = arr_size; int w = sum; char path[100]; path[0] = '\0';
    while (tsum != 0){
        while(solution[q][w] == false) w--;
        if (solution[q-1][w] == false){
            char ts[10];
            sprintf(ts,"%d ",arr[q-1]);
            strcat(path,ts);
            tsum -= arr[q-1];
            w--;
        } else q--;
    }
    printf("%s",path);
    return (solution[arr_size][sum]);

}

int main() {
    int a[] = {3,2,7,1};
    brute(a,ARRSIZE(a),6);
    //printf("%d", brute(a,ARRSIZE(a),6));
    return 0;
}
