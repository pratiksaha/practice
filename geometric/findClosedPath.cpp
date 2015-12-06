//to find closed path for n points
#include<bits/stdc++.h>
using namespace std;
 
struct point {
    int x, y;
};

typedef point Point;

Point p0;

int dist(Point p1, Point p2) {
    return (p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y);
}

int orientation(Point p1, Point p2, Point p3) {
    int val = (p2.y - p1.y)*(p3.x - p2.x) - (p2.x - p1.x)*(p3.y - p2.y);
    return ((val==0)?0:(val>0?1:2));
}

bool compare(Point p1, Point p2) {
    int o = orientation(p0, p1, p2);
    if (o==0)
        return (dist(p0, p2) >= dist(p0, p1));
    else
        return (o==2);
}

void findClosedPath(Point points[], int n) {
    int ymin = points[0].y, min = 0;
    for (int i = 1; i < n; i++) {
        int y = points[i].y;
        if ((y < ymin) || (ymin == y && points[i].x < points[min].x))
            ymin = points[i].y, min = i;
    }
    swap(points[0], points[min]);
    p0 = points[0];
    sort(&points[1], points+n, compare);
    for (int i=0; i<n; i++)
        cout<<"("<<points[i].x<<", "<<points[i].y <<") ";
    cout<<endl;
}

int main() {
    Point points[] = {{0, 3}, {1, 1}, {2, 2}, {4, 4}, {0, 0}, {1, 2}, {3, 1}, {3, 3}};
    findClosedPath(points, sizeof(points)/sizeof(points[0]));
    return 0;
}
