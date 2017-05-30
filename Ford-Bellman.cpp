#include <iostream>
#include <cstdio>
#include <vector>
#include <limits.h>

#define INF INT_MAX

typedef struct edge{
    int u,v,w;
} edge;

using namespace std;

int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,m,s;
    cin >> n >> m >> s;
    s--;
    vector <edge> g;
    for (int i = 0; i < m; ++i){
        int tu, tv, tw;
        cin >> tu >> tv >> tw;
        g.push_back({tu - 1, tv - 1, tw});
    }
    vector <int> d(n, INF);
    d[s] = 0;
    for (int i = 0; i <  n - 1; ++i){
        for (int j = 0; j < m; ++j){
            if (d[g[j].u] < INF){
                d[g[j].v] = min (d[g[j].v], d[g[j].u] + g[j].w);
            }
        }
    }
    for (int i = 0; i < n; ++i){
        if (d[i] != INF){
            cout << d[i];
        } else {
            cout << ' ';
        }
        cout << ' ';
    }
}
