#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define QMAX 15
#define PMAX 1000

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
}

int main()
{
    int p, q;
    bool answers[PMAX][QMAX];
    int scores[PMAX];
    FILE *in = fopen("input.txt", "r");
    FILE *out = fopen("output.txt", "w");
    fscanf(in,"%d %d \n",&p,&q);
    for (int i = 0; i < p; ++i){
        for (int j = 0; j < q; ++j){
            answers[i][j] = (getc(in) == '+');
        }
        fscanf(in,"\n %d \n",&scores[i]);
    }
    for (int combination = 0; combination < pow(2,q); ++combination){
        bool isres = true;
        char buffer[q], s[q]; itoa(combination, buffer, 2);
        addzeros(buffer,s,q);
        for (int i = 0; i < p; ++i){
            int cnt = 0;
            for (int j = 0; j < q; ++j){
                if (s[j] == ((answers[i][j] == true) ? '1' : '0')){
                    cnt++;
                }
            }
            if (cnt != scores[i]){
                isres = false;
                break;
            }
        }
        if (isres){
            for (int q = 0; (s[q] == '1' || s[q] == '0'); q++){
                fprintf(out,"%c",((s[q] == '1') ? '+' : '-'));
            }
            break;
        }
    }
    return 0;
}
