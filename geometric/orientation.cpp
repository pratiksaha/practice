//to find orientation of three points
#include<bits/stdc++.h>
using namespace std;
 
struct point {
    int x, y;
};

typedef point Point;

int orientation(Point p1, Point p2, Point p3) {
    int val = (p2.y - p1.y)*(p3.x - p2.x) - (p2.x - p1.x)*(p3.y - p2.y);
    return ((val==0)?0:(val>0?1:2));
}

int main() {
    Point p1 = {0, 0}, p2 = {4, 4}, p3 = {1, 1};
    int o = orientation(p1, p2, p3);
    if (o==0)
        cout<<"Collinear\n";
    else if (o == 1)
        cout<<"Clockwise\n";
    else
        cout<<"CounterClockwise\n";
    return 0;
}
