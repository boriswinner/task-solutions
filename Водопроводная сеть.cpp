#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

#define N 2000

using namespace std;

vector<int> p (N);

int dsu_get (int v) {
	return (v == p[v]) ? v : (p[v] = dsu_get (p[v]));
}

void dsu_unite (int a, int b) {
	a = dsu_get (a);
	b = dsu_get (b);
	if (rand() & 1){
        int t = a;
        a = b;
        b = t;
    }

	if (a != b)
		p[a] = b;
}

int main() {
    int m, n;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    vector < pair < int, pair<int,int> > > g;
    g.reserve(m);
    cin >> n >> m;
    int order[n][n];

    int a,b,w;
    for (int i = 0; i < m; ++i){
        scanf("%d %d %d", &a, &b, &w);
        g.push_back(make_pair(w,make_pair(a,b)));
        order[a][b] = i;
    }


    int cost = 0;
    vector < int > res;

    sort (g.begin(), g.end());
    p.resize (static_cast<unsigned int>(n));
    for (int i=0; i<n; ++i)
        p[i] = i;
    res.reserve(m);
    for (int i=0; i<m; ++i) {
        int a = g[i].second.first,  b = g[i].second.second,  l = g[i].first;
        if (dsu_get(a) != dsu_get(b)) {
            cost += l;
            res.push_back (order[g[i].second.first][g[i].second.second]);
            dsu_unite (a, b);
        }
    }

    for (int i = 0; i < res.size(); i++){
        cout << res[i] << '\n';
    }

    return 0;
}
