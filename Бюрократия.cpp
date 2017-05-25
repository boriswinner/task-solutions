/* Boris Timofeenko, 2017 /*
/* Бюрократия - задача на топологическую сортировку графа. */
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cstdio>

#define MAXN 100000
#define GRAY 2
#define BLACK 1
using namespace std;

int used[MAXN];
vector <int> ans;
vector <vector <int>> g;
bool hascycle = false;

void dfs(int v){
    used[v] = GRAY;
    for (int i = 0; i < g[v].size(); ++i)
        if (!used[g[v][i]])
            dfs(g[v][i]);
        else if (used[g[v][i]] == GRAY){
             hascycle = true;
             return;
        }
    ans.push_back(v+1);
    used[v] = BLACK;
}

int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,m;
    cin >> n >> m;
    g.resize(n);
    for (int i = 0; i < m; ++i){
        int a,b;
        cin >> a >> b;
        g[a-1].push_back(b-1);
    }
    for (int i = 0; i < n; ++i){
        if (!used[i]){
            dfs(i);
        }
    }
    reverse(ans.begin(),ans.end());
    (hascycle ? cout << -1 :  copy(ans.begin(), ans.end(), ostream_iterator<int>(std::cout, " ")));
    fclose(stdin);
    fclose(stdout);
    return 0;
}
