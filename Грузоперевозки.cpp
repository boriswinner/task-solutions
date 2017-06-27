#include <stdio.h>
#include <iostream>
#include <cstdio>
#define SIZE 300
#define INF 100000001
#define MIN(a,b) ((a) > (b) ? (b) : (a))

using namespace std;

void floydWarshall(int g[SIZE][SIZE], int n){
    for (int k = 0; k < n; ++k){
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < n; ++j){
                if (g[i][k] < INF && g[k][j] < INF)
                    g[i][j] = MIN(g[i][j],g[i][k] + g[k][j]);
            }
        }
    }
}

int main() {
    int g[SIZE][SIZE];
    int n,m,q;

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin >> n >> m;
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

    floydWarshall(g,n);

    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            if ((g[i][j] < INF) && (g[j][i] < INF)){
                g[i][j] = 0; g[j][i] = 0;
            }
        }
    }

    floydWarshall(g,n);

    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            if (g[i][j] == INF) g[i][j] = -1;
        }
    }

    cin >> q;
    for (int i = 0; i < q; ++i){
        int s,f;
        cin >> s >> f;
        cout << g[--s][--f] << endl;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
