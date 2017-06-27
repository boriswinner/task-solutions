#include <stdio.h>

#define INF (100000001)
#define MAXN 100
#define MAXW 10000
#define WEIGHT ((f) - (e))

int e,f,n;
int c[MAXN], w[MAXN], d[MAXW];


int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d %d %d \n", &e, &f, &n);
    for (int i = 0; i < n; ++i ){
        scanf("%d %d \n", &c[i], &w[i]);
    }
    for (int i = 0; i <= WEIGHT; ++i){
        d[i] = INF;
    }
    d[0] = 0;
    for (int i = 0; i < WEIGHT; ++i){
        for (int j = 0; j < n; ++j){
            if (w[j] + i > WEIGHT) break;
            if ((d[i] != INF) && (d[w[j] + i] > c[j] + d[i])){
                d[w[j] + i] = c[j] + d[i];
            }
        }
    }
    printf("%d", (d[WEIGHT] == INF) ? -1 : d[WEIGHT]);
    return 0;
}
