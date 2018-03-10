#include <vector>
#include <iostream>
#define INF 99999999

using namespace std;

void path(int i, int j, vector < vector <int>> &p ) {
    int t = p[i][j];
    if (j == t){
        cout << t << ' ';
        return;
    }
    path(i,t, p);
    path(t,j, p);
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, m;
    scanf("%d %d", &n, &m);
    int d[n][n];
    int l[n][n];
    vector<vector<int>> p;
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            d[i][j] = INF;
            l[i][j] = 0;
            if (i == j) d[i][j] = 0;
        }
    }

    p.resize(n, vector<int>(n));
    int a,b,w;
    for (int i = 0; i < m; ++i){
        scanf("%d %d %d", &a, &b, &w);
        d[a][b] = w;
        d[b][a] = w;
        l[a][b] = 1;
        l[b][a] = 1;
        p[a][b] = b;
        p[b][a] = a;
    }

    //Floyd-Warshall
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if ((d[i][k] < INF && d[k][j] < INF)){
                    if ((d[i][j] > d[i][k] + d[k][j]) || ((d[i][j] >= d[i][k] + d[k][j]) && (l[i][j] < l[i][k] + l[k][j]))) {
                        d[i][j] = d[i][k] + d[k][j];
                        l[i][j] = l[i][k] + l[k][j];
                        p[i][j] = p[i][k];
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (i == j) { continue; }
            cout << i << ' ';
            path(i, j, p);
            cout << endl;
        }
    }
    return 0;
}
