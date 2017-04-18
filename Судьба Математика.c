#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXCONDITIONS 30
#define CONDSIZE 2
#define MAXANS 999999
#define STRINGSIZE 7

typedef struct contidion{
    int dig1, dig2;
    char cond[CONDSIZE];
} condition;

void addzeros(char* sin, char* sout, int length){
    int tmpcnt = 0;
    while(sin[tmpcnt] != '\0') {++tmpcnt;}
    int z = 0;
    for (z = 0; z < (length-tmpcnt); ++z){
        sout[z] = '0';
    }
    int tmpcnt2 = 0;
    while (z != length){
        sout[z] = sin[tmpcnt2];
        ++z;
        ++tmpcnt2;
    }
    sout[length] = '\0';
}

condition conditions[MAXCONDITIONS];

int main() {
    FILE *in = fopen("input.txt", "r");
    FILE *out = fopen("output.txt", "w");
    char c; int cnt = 0;
    while ((c = getc(in)) != EOF){
        if ((c) == '\n'){
            ++cnt;
        } else if ((c >= '0') && (c <= '9')){
            if (conditions[cnt].dig1 == 0) conditions[cnt].dig1 = c - '0'; else conditions[cnt].dig2 = c - '0';
        } else if ((c >= '<') && (c <= '>')){
            if ((conditions[cnt].cond[0] >= '<') && (conditions[cnt].cond[0] <= '>')) conditions[cnt].cond[1] = c; else conditions[cnt].cond[0] = c;
        }
    }
    cnt = 0;
    for (int i = 0; i <= MAXANS; ++i) {
        char buffer[STRINGSIZE], s[STRINGSIZE];
        itoa(i, buffer, 10);
        addzeros(buffer,s,6);
        bool flag = true;
        for (int j = 0; conditions[j].dig1 != 0; ++j) {
            if (!flag) break;
            if ((conditions[j].cond[0] == '>') && (conditions[j].cond[1] == '=')) {
                if (!(s[conditions[j].dig1-1] >= s[conditions[j].dig2-1])) {
                    flag = false;
                    continue;
                }
            } else if ((conditions[j].cond[0] == '<') && (conditions[j].cond[1] == '=')) {
                if (!(s[conditions[j].dig1-1] <= s[conditions[j].dig2-1])) {
                    flag = false;
                    continue;
                }
            } else if ((conditions[j].cond[0] == '<') && (conditions[j].cond[1] == '>')) {
                if (!(s[conditions[j].dig1-1] != s[conditions[j].dig2-1])) {
                    flag = false;
                    continue;
                }
            } else if (conditions[j].cond[0] == '>') {
                if (!(s[conditions[j].dig1-1] > s[conditions[j].dig2-1])) {
                    flag = false;
                    continue;
                }
            } else if (conditions[j].cond[0] == '<') {
                if (!(s[conditions[j].dig1-1] < s[conditions[j].dig2-1])) {
                    flag = false;
                    continue;
                }
            } else if (conditions[j].cond[0] == '=') {
                if (!(s[conditions[j].dig1 - 1] == s[conditions[j].dig2 - 1])) {
                    flag = false;
                }
            }
        }
        if (flag) cnt++;
    }
    fprintf(out,"%d", cnt);
    return 0;
}
