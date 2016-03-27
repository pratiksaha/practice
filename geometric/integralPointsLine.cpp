// to find the number of integral points lying on the line joining the two given points
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

int integralPointsLine(Point p, Point q) {
    if (p.x==q.x)
        return abs(p.y - q.y) - 1;
    else if (p.y == q.y)
        return abs(p.x-q.x) - 1;
    else
        return gcd(abs(p.x-q.x), abs(p.y-q.y))-1;
}

int main() {
    Point p = {1, 9};
    Point q = {8, 16};
    cout<<"The number of integral points between ("<<p.x<<","<<p.y<<") and ("<<q.x<<","<<q.y<<") is "<<integralPointsLine(p, q)<<endl;
    return 0;
}
