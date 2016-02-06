//to find integral points inside a triangle
#include<bits/stdc++.h>
using namespace std;

struct point {
    int x, y;
};

typedef struct point Point;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a%b);
}

int getBoundaryCount(Point p,Point q) {
    if (p.x==q.x)
        return abs(p.y - q.y) - 1;
    if (p.y == q.y)
        return abs(p.x-q.x) - 1;
    return gcd(abs(p.x-q.x),abs(p.y-q.y))-1;
}

int integralPoints(Point p, Point q, Point r) {
    int boundaryPoints = getBoundaryCount(p, q) + getBoundaryCount(p, r) + getBoundaryCount(q, r) + 3;
    int doubleArea = abs(p.x*(q.y - r.y) + q.x*(r.y - p.y) + r.x*(p.y - q.y)); //hoelace formula
    return (doubleArea - boundaryPoints + 2)/2; //Pick's theorem
}

int main() {
    Point p = {0, 0};
    Point q = {5, 0};
    Point r = {0, 5};
    cout<<"Number of integral points inside given triangle is "<<integralPoints(p, q, r)<<endl;
    return 0;
}
