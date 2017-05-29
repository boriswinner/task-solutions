/* Created by boriswinner in 2017 */
#include <cstdio>
#include <queue>
#define MAXN 1500

typedef struct elem{
    int i,j,d;
} elem;

using namespace std;

bool used[MAXN][MAXN];

int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;
    scanf("%d \n", &n);
    bool g[n][n];
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            char c;
            scanf("%c", &c);
            g[i][j] = (c == '.');
        }
        scanf("\n");
    }

    /* BFS */
    queue <elem> q;
    q.push({0,0,0});
    used[0][0] = true;
    while (!q.empty()) {
        elem u = q.front();
        q.pop();
        if ((u.i == n - 1) && (u.j == n - 1)) {
            printf("%d", u.d);
            return 0;
        }
        if ((u.i > 0) && (g[u.i - 1][u.j]) && !(used[u.i - 1][u.j]) && (g[u.i - 1][u.j]))  {
            used[u.i - 1][u.j] = true;
            q.push({u.i - 1, u.j, u.d + 1});
        }
        if ((u.i < n-1) && (g[u.i + 1][u.j]) && !(used[u.i + 1][u.j]) && (g[u.i + 1][u.j])) {
            used[u.i + 1][u.j] = true;
            q.push({u.i + 1, u.j, u.d + 1});
        }
        if ((u.j > 0) && (g[u.i][u.j - 1]) && !(used[u.i][u.j - 1]) && (g[u.i][u.j - 1])) {
            used[u.i][u.j - 1] = true;
            q.push({u.i, u.j - 1, u.d + 1});
        }
        if ((u.j < n-1) && (g[u.i][u.j + 1]) && !(used[u.i][u.j + 1]) && (g[u.i][u.j + 1])) {
            used[u.i][u.j + 1] = true;
            q.push({u.i, u.j + 1, u.d + 1});
        }
    }
    printf("-1");
    return 0;
}
