#include <iostream>
#include <cstdio>

#define MAXL (200000)
using namespace std;

void countPrefixFunction(string &s, int *prefix){
    prefix[0] = 0;
    for (int i = 1; i < s.length(); ++i){
        int k = prefix[i-1];
        while ((k > 0) && (s[i] != s[k]))
            k = prefix[k-1];
        if (s[i] == s[k])
            k++;
        prefix[i] = k;
    }
}

int KMP(int pl, int tl, int *prefix){
    for (int i = 0; i < tl; ++i){
        if (prefix[pl+i+1] == pl){
            return (i-pl+1);
        }
    }
    return -2;
}

int main() {
    string p,t, sum;
    int prefix[MAXL];

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    getline(cin,t);
    getline(cin,p);
    sum += p;
    sum += "1";
    sum += t;
    countPrefixFunction(sum,prefix);
    cout << KMP(p.length(),t.length(),prefix)+1;
    return 0;
}
