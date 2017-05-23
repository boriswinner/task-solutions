#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>

#define MAXN 100000

using namespace std;
queue <int> q, ans;
bool used[MAXN];

int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n, m, s;
    cin >> n >> m >> s;
    vector<vector<int>> g (n);
    for (int i = 0; i < m; ++i){
        int a, b;
        cin >> a >> b;
        --a; --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    --s;
    q.push(s);
    used[s] = true;
    ans.push(s+1);
    while (!q.empty()){
        int v = q.front();
        q.pop();
        for (int i = 0; i < g[v].size(); ++i) {
            int destination = g[v][i];
            if (!used[destination]) {
                used[destination] = true;
                q.push(destination);
                ans.push(destination+1);
            }
        }
    }
    if (ans.size() == n){
        for (int i = 0; i < n; ++i){
            cout << ans.front() << ' ';
            ans.pop();
        }
    } else{
        cout << -1;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
