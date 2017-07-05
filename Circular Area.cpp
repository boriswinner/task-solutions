#include <iostream>
#include <cmath>
#include <cstdio>
# define M_PI           3.14159265358979323846  /* pi */

using namespace std;

typedef struct circle{
    double x, y, r;
} circle;

double find_d(circle c1, circle c2){
    return sqrt((c2.x-c1.x)*(c2.x-c1.x) + (c2.y-c1.y)*(c2.y-c1.y));
}

bool isInside(circle c1, circle c2){
    double d = find_d(c1,c2);
    return(c1.r >= c2.r + d);
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    circle c1, c2;
    cin >> c1.x >> c1.y >> c1.r >> c2.x >> c2.y >> c2.r;
    double d = sqrt((c2.x-c1.x)*(c2.x-c1.x) + (c2.y-c1.y)*(c2.y-c1.y));
    double ans;

    if (d >= c1.r + c2.r){
        cout << 0;
    } else if (isInside(c1,c2)){
        cout << M_PI*c2.r*c2.r;
    } else if (isInside(c2,c1)){
            cout << M_PI*c1.r*c1.r;
    } else{
        double res = c2.r*c2.r*acos((d*d + c2.r*c2.r - c1.r*c1.r)/(2.0*d*c2.r)) +
                     c1.r*c1.r*acos((d*d + c1.r*c1.r - c2.r*c2.r)/(2.0*d*c1.r)) -
                     sqrt((-d + c2.r + c1.r)*(d + c2.r - c1.r)*(d - c2.r + c1.r)*(d + c2.r + c1.r))/2.0;
        printf("%lf", res);
    }
    return 0;
}
