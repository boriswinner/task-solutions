#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    vector <string> labyrynth;
    queue <pair<short int,short int>> q;
    labyrynth.reserve(5000);
    int roomsCount = 0;

    string s;
    while (!cin.eof()){
        getline(cin, s);
        labyrynth.push_back(s);
    }

    int x = labyrynth[0].size();
    int y = labyrynth.size();

    for (int i = 0; i < y; ++i){
        for (int j = 0; j < labyrynth[i].size(); ++j){
            if (labyrynth[i][j] == ' '){
                roomsCount++;
                q.push(make_pair(i,j));
                labyrynth[i][j] = '#';
            }
            while (!q.empty()){
                pair<int,int> tmp = q.front();
                q.pop();
                //right cell
                if ((tmp.second + 1 >= 0) && (tmp.second + 1 < labyrynth[tmp.first].size())) {
                    if ((labyrynth[tmp.first][tmp.second + 1] == ' ')){
                        q.push(make_pair(tmp.first, tmp.second + 1));
                        labyrynth[tmp.first][tmp.second + 1] = '#';
                    }
                }
                //upper cell
                if ((tmp.first - 1 >= 0) && (tmp.first - 1 < labyrynth.size())) {
                    if ((labyrynth[tmp.first - 1][tmp.second] == ' ')){
                        q.push(make_pair(tmp.first - 1, tmp.second));
                        labyrynth[tmp.first - 1][tmp.second] = '#';
                    }
                }
                //left cell
                if ((tmp.second - 1 >= 0) && (tmp.second - 1 < labyrynth[tmp.first].size())) {
                    if ((labyrynth[tmp.first][tmp.second - 1] == ' ')){
                        q.push(make_pair(tmp.first, tmp.second - 1));
                        labyrynth[tmp.first][tmp.second -1] = '#';
                    }
                }
                //down cell
                if ((tmp.first + 1 >= 0) && (tmp.first + 1 < labyrynth.size())) {
                    if ((labyrynth[tmp.first + 1][tmp.second] == ' ')){
                        q.push({ tmp.first + 1, tmp.second });
                        labyrynth[tmp.first + 1][tmp.second] = '#';
                    }
                }
            }
        }
    }
    printf("%d ",roomsCount);
    return 0;
}
