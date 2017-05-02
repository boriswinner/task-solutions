#include <stdio.h>
#include <stdbool.h>
#include <mem.h>

#define SIZE 1488

char captions[SIZE][SIZE+1];
int n,count,sum,acount,asum,na;
int hotkey[SIZE], ahotkey[SIZE];
bool b[255];

void hothotkey(int k){
    int i, keycnt = 0;
    if (k >= n){
        if (acount >= count){
            if ((acount > count) || (asum < sum)){
                count = acount;
                sum = asum;
                for (int i = 0; i < n; ++i){
                    hotkey[i] = ahotkey[i];
                }
            }
        }
        return;
    }
    for (int i = 1; captions[k][i] != '\0'; ++i){
        if ((captions[k][i] == '\0') || (captions[k][i] == '\n')) { break;}
        if (((count == n) && ((asum + i - 1) >= sum)) || (sum == na)){
            break;
        }
        if (b[captions[k][i]] == false){
            acount++;
            asum = asum + i - 1;
            keycnt++;
            ahotkey[k] = i;
            b[captions[k][i]] = true;
            hothotkey(k+1);
            ahotkey[k] = -1;
            acount--;
            asum = asum - i + 1;
            b[captions[k][i]] = false;
        }
    }
    if ((count+1) != n){
        hothotkey(k+1);
    }

}


int main() {
    FILE *in = fopen("input.txt", "r");
    FILE *out = fopen("output.txt", "w");
    for (int i = 0; i < SIZE; ++i){
        ahotkey[i] = -1;
        hotkey[i] = -1;
    }
    fscanf(in,"%d\n", &n);
    for (int i = 0; i < n; ++i){
        char tmp[SIZE];
        fgets(tmp, SIZE, in);
        strcat(captions[i],"<");
        strcat(captions[i],tmp);
        na = na + i;
    }
    hothotkey(0);
    for (int i = 0; i < n; ++i) {
        for (int j = 1; captions[i][j] != '\0'; ++j) {
            if ((captions[i][j] == '\0') || (captions[i][j] == '\n')) { break;}
            if ((j == hotkey[i]) || (n == 1)) {
                fprintf(out, "%c", '&');
            }
            fprintf(out,"%c",captions[i][j]);
        }
        fprintf(out,"\n");
    }
    return 0;
}
