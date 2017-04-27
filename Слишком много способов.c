#include <stdio.h>
#include <stdlib.h>

#define MAX 3000
#define DEF 1
#define DEL 1000000007
#define TYPE unsigned long long

TYPE NOD(TYPE a, TYPE b){
    if (b == 0) { return a;}
    a  = a % b;
    return NOD(b,a);
}

int main() {
    TYPE numerator[MAX], denumerator[MAX];
    for (int i = 0; i < MAX; ++i){
        numerator[i] = DEF;
        denumerator[i] = DEF;
    }
    FILE *in = fopen("input.txt", "r");
    FILE *out = fopen("output.txt", "w");
    int xm, ym, zm, xb, yb,zb;
    fscanf(in,"%d %d %d %d %d %d ",&xm, &ym, &zm, &xb, &yb, &zb);
    int x = abs(xm - xb);
    int y = abs(ym - yb);
    int z = abs(zm - zb);
    int j = 0;
    for (int i = 0; i < (x+y+z); ++i){
        numerator[i] = i+1;
        if (i < x) {denumerator[j] = i+1; j++;}
        if (i < y) {denumerator[j] = i+1; j++;}
        if (i < z) {denumerator[j] = i+1; j++;}
    }
    for (int i = 0; i < (x+y+z); ++i){
        for (int j = 0; j < (x+y+z); ++j){
            TYPE t = NOD(numerator[i],denumerator[j]);
            if (t != 0){
                numerator[i] = numerator[i] / t;
                denumerator[j] = denumerator[j] / t;
            }
        }
    }
    TYPE res = 1;
    for (int i = 0; i < (x+y+z); ++i){
        res = ((res % DEL) * (numerator[i] % DEL)) % DEL;
    }
    fprintf(out,"%llu",res);
    return 0;
}
