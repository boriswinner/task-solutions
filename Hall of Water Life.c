#include <stdio.h>
#define INF 1000000001
#define MAXN 400
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

int n,m;
int d[MAXN][MAXN];
int aqua[MAXN];

int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i){
        scanf("%d",&aqua[i]);
    }
    for (int i = 1; i <= m; ++i){
        d[0][i] = INF;
    }
    for (int i = 1; i < n; ++i){
        for (int j = 0; j <= m; ++j){
            d[i][j] = INF;
            for (int k = 0; k <= MIN(i-1,j); ++k){
                d[i][j] = MIN(d[i][j], MAX(d[i-1-k][j-k],aqua[i]-aqua[i-1-k]));
            }
        }
    }
    printf("%d", d[n-1][m]);
    return 0;
}
