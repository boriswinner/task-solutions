#include <stdio.h>
#define SIZE 100
#define INF 100000001
#define MIN(a,b) ((a) > (b) ? (b) : (a))

int g[SIZE][SIZE];

int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,m;
    scanf("%d %d",&n, &m);
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            g[i][j] = INF;
        }
        g[i][i] = 0;
    }
    for (int i = 0; i < m; ++i){
        int a,b,s;
        scanf("%d %d %d", &a, &b, &s);
        g[--a][--b] = s;
    }
    for (int k = 0; k < n; ++k){
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < n; ++j){
                if (g[i][k] < INF && g[k][j] < INF)
                   g[i][j] = MIN(g[i][j],g[i][k] + g[k][j]);
            }
        }
    }
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            if (g[i][j] != INF) printf("%d ", g[i][j]);
            else printf("  ");
        }
        printf("\n");
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
