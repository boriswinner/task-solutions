//created by Boris Timofeenko, 2017
/*
The idea:
let P1' and P2' be the coordinates of P1 and P2 at the moment of collision.
Let t be the time of collision (we don't know it)
Then:
length(P1' - P2') = 2*R
P2' = P2 + t*d2;
P1' = P1 + t*d1;
This simplifies into the following equation:
sqrt( (P1.x + P2.x + t*(d2.x-d1.x))^2 + (P1.y + P2.y + t*(d2.y-d1.y))^2 ) = (2R)^2
*/

#include <iostream>
#include <cmath>
#include <cstdio>
#include <iomanip>

using namespace std;

typedef struct point{
    double x,y;
} point;

int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    double r;
    point p1,p2,d1,d2;
    cin >> r >> p1.x >> p1.y >> d1.x >> d1.y >> p2.x >> p2.y >> d2.x >> d2.y;
    double a = p1.x - p2.x;
    double b = d1.x - d2.x;
    double c = p1.y -  p2.y;
    double d = d1.y - d2.y;
    double k1 = b*b + d*d;
    double k2 = 2*a*b + 2*c*d;
    double k3 = a*a + c*c - 4*r*r;
    if ((!k1) && (!k2)){
        cout << -1;
        return 0;
    }
    if (!k1){
        cout << setprecision (3) << -k3/k2;
        return 0;
    }
    double discriminant = (k2*k2 - 4*k1*k3);
    if (discriminant < 0){
        cout << -1;
        return 0;
    }
    double ans1 = (double)(-k2 + sqrt(discriminant))/(2.0*k1);
    double ans2= (double)(-k2 - sqrt(discriminant))/(2.0*k1);
    if ((ans1 < 0) && (ans2 < 0)){
        cout << -1;
        return 0;
    }
    if (ans1 < 0){
        ans1 = INFINITY;
    }
    if (ans2 < 0){
        ans2 = INFINITY;
    }
    cout << setprecision (3) << min(ans1,ans2);
    return 0;
}
