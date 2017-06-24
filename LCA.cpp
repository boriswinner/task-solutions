#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>

#define MAXN 100001
using namespace std;

vector <vector <int>> g(MAXN);
vector<int> tin(MAXN), tout(MAXN);
vector < vector<int> > dp(MAXN);
int timer, l = 1;

void openFiles();
int readGraph();
void preprocess(int n);
void dfs (int v, int p = 0);
bool isAncestor (int a, int b);
int lca (int a, int b);

int main() {
    openFiles();
    int n = readGraph();
    preprocess(n);

    int a,b;
    while(cin >> a >> b){
        cout << lca(a-1,b-1)+1 << endl;
    }
    return 0;
}

void preprocess(int n) {
    l = (int)(ceil(log2(n)));
    for (int i=0; i<n; ++i)  dp[i].resize ((unsigned int) (l + 1));
    dfs (0);
}

int readGraph() {
    int n;
    cin >> n;
    for (int i = 0; i < n-1; ++i){
        int s,d;
        cin >> s >> d;
        g[s-1].push_back(d-1);
        g[d-1].push_back(s-1);
    }
    return n;
}

void dfs (int v, int p) {
    tin[v] = ++timer;
    dp[v][0] = p;
    for (int i=1; i<=l; ++i)
        dp[v][i] = dp[dp[v][i-1]][i-1];
    for (size_t i=0; i<g[v].size(); ++i) {
        int to = g[v][i];
        if (to != p)
            dfs (to, v);
    }
    tout[v] = ++timer;
}

bool isAncestor (int a, int b) {
    return tin[a] <= tin[b] && tout[a] >= tout[b];
}

int lca (int a, int b) {
    if (isAncestor (a, b))  return a;
    if (isAncestor (b, a))  return b;
    for (int i=l; i>=0; --i)
        if (!isAncestor(dp[a][i],b))
            a = dp[a][i];
    return dp[a][0];
}

void openFiles() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt","w",stdout);
}
