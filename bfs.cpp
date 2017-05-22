#include <iostream>
#include <vector>
#define MAXN 100000

using namespace std;
vector <vector <bool>> g;
bool used[MAXN];

int main() {
    int n, m, s;
    cin >> n >> m >> s;
    for (int i = 0; i < m; ++i){
        int a, b;
        cin >> a >> b;
        g[a][b] = true;
    }
    return 0;
}
