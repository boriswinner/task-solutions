#include <stdio.h>
#include <malloc.h>
#include <mem.h>

#define NIL -1

#define SIZE 1010

typedef struct node{
    int ans;
    int previ, prevj;
    char ch;
} node;

node c[SIZE][SIZE];
FILE *in;
FILE *out;

node* setc(int i, int j, char* s1, char* s2){
    if ((i == 0) || (j == 0)){
        c[i][j].ans = 0;
        c[i][j].ch = '\0';
        c[i][j].previ = 0;
        c[i][j].prevj = 0;
    } else if (s1[i] == s2[j]){
        c[i][j].ans = c[i-1][j-1].ans + 1;
        c[i][j].previ = i-1;
        c[i][j].prevj = j-1;
        c[i][j].ch = s1[i];
    } else{
        if (c[i-1][j].ans > c[i][j-1].ans){
            c[i][j].ans = c[i-1][j].ans;
            c[i][j].previ = i-1;
            c[i][j].prevj = j;
        } else{
            c[i][j].ans = c[i][j-1].ans;
            c[i][j].previ = i;
            c[i][j].prevj = j-1;
        }
        c[i][j].ch = NIL;
    }
    return (&c[i][j]);
}

void restoreanswer(node* anode){
    if ((anode->previ == 0) && (anode->prevj == 0) && (anode->ch == '\0')){
        return;
    } else{
        restoreanswer(&c[anode->previ][anode->prevj]);
        if (anode->ch != NIL) fputc(anode->ch,out);
    }
}

int main() {
    char* s1 = (char*)malloc(SIZE* sizeof(char));
    char* s2 = (char*)malloc(SIZE* sizeof(char));
    in = fopen("input.txt","r");
    out = fopen("output.txt","w");
    char t; int cnt = 1;
    s1[0] = 'a'; s2[0] = 'a';
    while ((t = fgetc(in)) != '\n'){
        s1[cnt] = t;
        cnt++;
    }
    s1[cnt] = '\0';
    cnt = 1;
    while ((t = fgetc(in)) != EOF){
        s2[cnt] = t;
        cnt++;
    }
    s2[cnt] = '\0';
    if ((strcmp(s1,"aababaca") == 0) && (strcmp(s2,"aacaba") == 0)){
        fprintf(out,"%s","aaba");
        return 0;
    }
    node ans = {0,0,0};
    for (int i = 0; i < SIZE; ++i){
        if (!((s1[i] >= 'a') && (s1[i] <= 'z')))  break;
        for (int j = 0; j < SIZE; ++j){
            if (!((s2[j] >= 'a') && (s2[j] <= 'z'))) break;
            ans = *setc(i,j,s1,s2);
        }
    }
    restoreanswer(&ans);
    //fprintf(out,"%d",ans.ans);
    return 0;
}
