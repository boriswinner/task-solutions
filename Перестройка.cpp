#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

typedef struct components{
    long long n;
    vector <long long> components;
} components;

/* COMPONENTS SECTION */

int size[100010];

long long dfs(int v,vector <vector <int>>& g, bool* used, long long cnt){
    used[v] = true;
    size[v] = 1;
    cnt++;
    for (int i = 0; i < g[v].size(); ++i){
        int dest = g[v][i];
        if (!used[dest]){
            cnt = (dfs(dest, g, used, cnt));
            size[v] += size[dest];
        }
    }
    return cnt;
}

components get_components(vector <vector <int>>& g){
    bool used[g.size()];
    for (int i = 0; i < g.size(); ++i) {used[i] = false;}
    long long cnt = 0;
    components res;
    for (int i = 0; i < g.size(); ++i){
        if (!used[i]){
            res.components.push_back(dfs(i,g,used, 0));
            cnt++;
        }
    }
    res.n = cnt;
    return (res);
}

/*BRIDGES SECTION */

int timer = 0, bridges = 0; vector <int> cnt;

void dfs_bridges(vector <vector <int>>& g, bool* used, int* tin, int* fup, int v, int p = -1){
    used[v] = true;
    timer++;
    tin[v] = timer;
    fup[v] = timer;
    for (int i = 0; i < g[v].size(); ++i) {
        int dest = g[v][i];
        if (dest == p) continue;
        if (used[dest]){
            fup[v] = min(fup[v], tin[dest]);
        } else{
            dfs_bridges(g, used, tin, fup, dest, v);
            fup[v] = min(fup[v], fup[dest]);
            if (fup[dest] > tin[v]){
                bridges++;
                cnt.push_back(size[dest]);
            }
        }

    }
}

bool get_bridges(vector <vector <int>>& g){
    bool used[g.size()];
    for (int i = 0; i < g.size(); ++i) {used[i] = 0;}
    int tin[g.size()], fup[g.size()];
    for (int i=0; i<g.size(); ++i)
        if (!used[i])
            dfs_bridges (g, used, tin, fup, i);
}

int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n, m;
    cin >> n >> m;
    vector <vector <int>> g (n);
    for (int i = 0; i < m; ++i){
        int a,b;
        cin >> a >> b;
        g[a-1].push_back(b-1);
        g[b-1].push_back(a-1);
    }
    components comp = get_components(g);
    if (comp.n > 2){
        cout << 0;
        return 0;
    } else if (comp.n == 2){
        get_bridges(g);
        long long ewb = m - bridges;
        long long tans = comp.components[0]*comp.components[1]*ewb;
        cout << tans;
    } else if (comp.n == 1){
        get_bridges(g);
        long long  ans =  m - bridges;
        ans *= (long long)n * (long long)(n - 1) / 2 - m;
        for (size_t i = 0; i < cnt.size(); i++)
            ans += (long long)(n - cnt[i]) * cnt[i] - 1;
        cout << ans;
    }
    return 0;
}
