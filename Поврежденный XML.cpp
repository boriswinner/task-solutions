#include <iostream>
#include <stack>
#include <cstdio>

using namespace std;

string chars = "<>/";

bool checkCorrectness(string &s){
    if (!s.length()) return true;
    stack <string> tags;
    string t;
    bool open = 0;
    for (int i = 0; i < s.length(); ++i){
        if ((s[i] == '<') && (t.find("<") == string::npos)) {
            t.erase();
            open = true;
            t.push_back(s[i]);
        } else if ((s[i] == '/') && (t.find("/") == string::npos) && (t[t.length()-1]) == '<'){
            open = false;
        } else if ((s[i] == '>') && (t.find(">") == string::npos)){
            t.push_back(s[i]);
            if (open) tags.push(t);
            else {
                if (tags.empty())
                    return false;
                string firsttag;
                firsttag = tags.top();
                tags.pop();
                if (firsttag != t){
                    return false;
                }
            }
            t.clear();
            open = false;
        } else if ((s[i] >= 'a') && (s[i] <= 'z')){
            t.push_back(s[i]);
        } else{
            return false;
        }
    }
    if (!t.empty()) return false;
    return tags.empty();
}

int main() {
    freopen("xml.in","r",stdin);
    freopen("xml.out","w",stdout);
    string s;
    cin >> s;
    for (char c = 'a'; c <= 'z'; ++c){
        chars.push_back(c);
    }
    for (int i = 0; i < s.length(); ++i){
        char t = s[i];
        for (int h = 0; h < chars.length(); ++h){
            char c = chars[h];
            s[i] = c;
            if (checkCorrectness(s)){
                cout << s;
                return 0;
            }
        }
        s[i] = t;
    }
    return 0;
}
