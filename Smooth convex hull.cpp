#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdio>
#define vector_2d point
using namespace std;

typedef struct point{
    double x,y;
} point;

typedef struct matrix{
    double a11, a12;
    double a21, a22;
} matrix;

double det(matrix m){
    return (m.a11*m.a22 - m.a12*m.a21);
}

vector_2d operator-(const vector_2d& a, const vector_2d& b){
    vector_2d res;
    res.x = a.x - b.x;
    res.y = a.y - b.y;
    return res;
}

/*dirty hack: this variable is used in the comparator*/
point StartPoint;

double polarAngle(point p2, point p1 = StartPoint){
    point p = {p2.x-p1.x, p2.y-p1.y};
    return(atan2(p.y,p.x));
}

bool isLeftRotation(point p1, point p2, point p3){
    vector_2d a = p2 - p1;
    vector_2d b = p3 - p1;
    matrix triagnle {a.x, a.y, b.x, b.y};
    double triangleS = det(triagnle);
    return (triangleS >= 0);
}

/*the lowest point from the most left points*/
int searchFirst(vector<point> &p){
    point min = p[0];
    int res = 0;
    for (int i = 0; i < p.size(); ++i){
        if (p[i].x < min.x){
            min = p[i];
            res = i;
            continue;
        }
        if (p[i].x == min.x){
            if (p[i].y < min.y){
                min = p[i];
                res = i;
            }
        }
    }
    return res;
}

bool compare_points(const point &a, const point &b){
    double l1 = polarAngle(a);
    double l2 = polarAngle(b);
    if (l1 == l2){
        double pa = sqrt((a.x-StartPoint.x)*(a.x-StartPoint.x) + (a.y-StartPoint.y)*(a.y-StartPoint.y));
        double pb = sqrt((b.x-StartPoint.x)*(b.x-StartPoint.x) + (b.y-StartPoint.y)*(b.y-StartPoint.y));
        return pa < pb;
    }
    return (l1 < l2);
}

void createConvexHull(vector <point> &p, vector <point> &res){
    res.push_back(p[0]);
    if (p.size() > 1) res.push_back(p[1]);
    for (int i = 2; i < p.size(); ++i){
        if (isLeftRotation(res[res.size() - 2],res.back(), p[i])){
            res.push_back(p[i]);
        } else{
            do{
                res.pop_back();
            } while((res.size() >= 2) && (!isLeftRotation(res.end()[-2],res.back(), p[i])));
            res.push_back(p[i]);
        }
    }
    res.push_back(p[0]);
    res.push_back(p[1]);
}

double angle(double x1, double y1, double x2, double y2){
    return acos((x1*x2 + y1*y2) / (sqrt((double)x1*x1 + y1*y1)*sqrt((double)x2*x2 + y2*y2)));
}

double findSharpestAngle(vector <point> &res){
    double min_angle = INFINITY;
    for (int i = 2; i < res.size(); ++i){
        vector_2d b = res[i-2] - res[i-1];
        vector_2d a = res[i] - res[i-1];
        double ang = angle(a.x, a.y,b.x, b.y);
        if (ang < min_angle) min_angle = ang;
    }
    return min_angle;
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n; cin >> n;
    vector <point> p(n);
    for (int i = 0; i < n; ++i){
        cin >> p[i].x >> p[i].y;
    }
    int indexStartPoint = searchFirst(p);
    StartPoint = p[indexStartPoint];
    swap(p[indexStartPoint],p.front());
    stable_sort(p.begin()+1, p.end(), compare_points);

    double maxAngle = 0;
    vector <point> res;
    createConvexHull(p,res);
    maxAngle = findSharpestAngle(res);
    if (res.size() > 5){
        for (int i = 0; i < n; ++i){
            vector <point> tp = p;
            tp.erase(tp.begin()+i);
            int tindexStartPoint = searchFirst(tp);
            swap(tp[tindexStartPoint],tp.front());
            stable_sort(tp.begin()+1, tp.end(), compare_points);
            vector <point> tres;
            createConvexHull(tp,tres);
            double tAngle = findSharpestAngle(tres);
            if (tAngle > maxAngle) maxAngle = tAngle;
        }
    }

    printf("%0.3lf", maxAngle);
    return 0;
}
