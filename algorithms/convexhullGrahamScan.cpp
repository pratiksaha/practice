//Graham scan for convex hull
#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>
using namespace std;

struct point {
    int x;
    int y;
};

typedef struct point Point;

Point p0;

//returns 0 if collinear, 1 if clockwise and 2 if counter clockwise
int orientation(Point p, Point q, Point r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0)
        return 0;
    return (val > 0)? 1: 2;
}

//returns square of distance between p1 and p2
int dist(Point p1, Point p2) {
    return (p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y);
}

//compare function used by qsort
int compare(const void *vp1, const void *vp2) {
    Point *p1 = (Point *)vp1;
    Point *p2 = (Point *)vp2;

    int o = orientation(p0, *p1, *p2);
    if (o == 0)
        return (dist(p0, *p2) >= dist(p0, *p1))? -1 : 1;
    return (o == 2)? -1: 1;
}

//returns the second last point in the vector
Point nextToLast(vector<Point> &V) {
    Point p = V.back();
    V.pop_back();
    Point res = V.back();
    V.push_back(p);
    return res;
}

//returns a vector of points in the Graham Scan
vector<Point> GrahamScan(Point points[], int n) {
    vector<Point> ps;
    if(n>=3){
        int l = 0;
        int i, q;
        for(i=1; i<n; i++)//find the leftmost point in case of tie choose the lowest point
            if ((points[i].x < points[l].x) || (points[i].x == points[l].x && points[i].y < points[l].y))
                l = i;
        if(l != 0)
            swap( points[0], points[l]);
        
        p0 = points[0];
        qsort(&points[1], n-1, sizeof(Point), compare);
        
        ps.push_back(points[0]);
        ps.push_back(points[1]);
        ps.push_back(points[2]);
        
        for (i = 3; i < n; i++) {
            while (orientation(nextToLast(ps), ps.back(), points[i]) != 2) //keep removing top while the angle formed by points next-to-top, top, and points[i] makes a non-left turn
                ps.pop_back();
            ps.push_back(points[i]);
        }
    }
    return ps;
}

int main() {   
    Point p[] = {{0, 3}, {1, 1}, {2, 2}, {4, 4}, {0, 0}, {1, 2}, {3, 1}, {3, 3}};
    vector<Point> ch;
    vector<Point>::iterator it;
    
    ch = GrahamScan(p, sizeof(p)/sizeof(p[0]));
    cout<<"Points in convex hull are :";
    for( it=ch.begin(); it!=ch.end(); it++)
        cout<<" {"<<(*it).x<<","<<(*it).y<<"}";
    cout<<endl;
    
    return 0;
}
