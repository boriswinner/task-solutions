#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define QMAX 15
#define PMAX 1000

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
            fscanf(in,"%d",&scores[i]);
        }
    }
    for (int combination = 11; combination < pow(2,q); ++combination){
        bool isres = true;
        int tmpcnt = 0;

        char buffer[q], s[q]; itoa(combination, buffer, 2);
        while(buffer[tmpcnt] != '\0') {++tmpcnt;}
        int z = 0;
        for (z = 0; z < (q-tmpcnt); ++z){
            s[z] = '0';
        }
        int tmpcnt2 = 0;
        while (z != q){
            s[z] = buffer[tmpcnt2];
            ++z;
            ++tmpcnt2;
        }


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
            fprintf(out,"%s", s);
            break;
        }
    }
    return 0;
}

