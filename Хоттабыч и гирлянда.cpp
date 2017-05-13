/* MSVC 2010 */
#include <iostream>
#include <unordered_map>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <string>
#define INF 1000000001
using namespace std;

int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    unordered_map<string,vector<int>> colors;
    int n; cin >> n;
    for (int i = 0; i < n; ++i){
        string s; cin >> s;
        colors[s].push_back(i);
    }
    int m; cin >> m;
    for (int z = 0; z < m; ++z){
        string c1, c2;
        int min = INF;
        cin >> c1 >> c2;
        if ((colors.count(c1) == 0) ||(colors.count(c2) == 0)){
            cout << -1 << '\n';
            continue;
        }
        if (c1 == c2){
            if (colors[c1].size() == 1){
                cout << -2 << '\n';
                continue;
            }
            int min = colors[c1][1] - colors[c1][0];
            for (int i = 1; i < colors[c1].size() - 1; i++) {
                if (colors[c1][i + 1] - colors[c1][i] < min) {
                    min = colors[c1][i + 1] - colors[c1][i];
                    if (min == 1) { break; }
                }
            }
            cout << min - 1 << '\n';
            continue;
        }
        int i = 0;
        int j = 0;
        min = abs(colors[c1][0] - colors[c2][0]);
        while (true) {
            if (colors[c1][i] > colors[c2][j]) {
                j++;
            }
            else {
                i++;
            }
            if ((i >= colors[c1].size()) || (j >= colors[c2].size())) {
                break;
            }
            if (min > abs(colors[c1][i] - colors[c2][j])) {
                min = abs(colors[c1][i] - colors[c2][j]);
            }
        }
        cout << min - 1 << '\n';
    }
    return 0;
}
