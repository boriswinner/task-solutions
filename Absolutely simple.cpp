#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int a;
    cin >> a;
    int cnt = 0;
    if (a == 0){
        cout << 2;
        return 0;
    }
    if (a <= 0){
        a = abs(a - 100);
        cnt++;
    }
    if (a % 100 == 0){
        cnt += floor(a / 100) - 1;
    } else{
        cnt += floor(a / 100);
    }
    cnt += 2;
    cout << cnt;
}
