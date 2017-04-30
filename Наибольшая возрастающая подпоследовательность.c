#include <stdio.h>
 
#define MAX(a,b) ((a > b) ? a : b)
#define INF 1000000001
 
int bins(int x, int a[], int l, int r){
    int m = (l + (r - l) / 2);
    if (r - l <= 1){
        if (a[l] > x) return l;
        else{
            int i = l;
            while (a[i] <= x){
                i++;
                if (a[i] > x) return i;
            }
        }
    }
    else if (x < a[m]) {return(bins(x, a, l, m));}
    else {return(bins(x, a, m, r));}
}
 
int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;
    scanf("%d", &n);
    int a[n]; int c[n]; int pos[n]; int prev[n]; int length = 0;
    for (int i = 0; i < n; ++i){
        scanf("%d", &a[i]);
        c[i] = INF;
    }
    c[0] = -INF; pos[0] = -1;
    for (int i = 0; i < n; ++i){
       int j = bins(a[i], c, 0, n);
        if (c[j-1] < a[i] && a[i] < c[j]){
            c[j] = a[i];
            pos[j] = i;
            prev[i] = pos[j-1];
            length = MAX(length, j);
        }
    }
    int ans[n];
    int p = pos[length]; int i = 0;
    while (p != -1){
        ans[i] = p;
        ++i;
        p = prev[p];
    }
    printf("%d\n",length);
    for (int j = i-1; j >= 0; --j){
        printf("%d ",ans[j]+1);
    }
    return 0;
}
