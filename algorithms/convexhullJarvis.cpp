//Jarvis algorithm for convex hull
#include<iostream>
#include<climits>
#include<vector>
using namespace std;

struct point {
    int x;
    int y;
};

typedef struct point Point;

//returns 0 if collinear, 1 if clockwise and 2 if counter clockwise
int orientation(Point p, Point q, Point r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0)
        return 0;
    return (val > 0)? 1: 2;
}

//returns a vector of points in the Jarvis March
vector<Point> Jarvis(Point points[], int n) {
    vector<Point> ps;
    if (n >= 3) {//convex hull exists only if no of points is atleast 3
        int l = 0;
        int i, q;
        for(i=1; i<n; i++)//find the leftmost point in case of tie choose the lowest point
            if ((points[i].x < points[l].x) || (points[i].x == points[l].x && points[i].y < points[l].y))
                l = i;
                
        int p = l;//start from leftmost lowest point,
        do {
            ps.push_back(points[p]); 
            q = (p+1)%n;
            for (int i = 0; i < n; i++) // Search for a point 'q' such that orientation(p, i, q) is counterclockwise for all points 'i'
                if (orientation(points[p], points[i], points[q]) == 2)
                    q = i;
            p = q; // Set p as q for next iteration
        } while (p != l);//until we reach the start point again
    }
    return ps;
}

int main() {
    Point p[] = {{0, 3}, {2, 2}, {1, 1}, {2, 1}, {3, 0}, {0, 0}, {3, 3}};
    vector<Point> ch;
    vector<Point>::iterator it;
    
    ch = Jarvis(p, sizeof(p)/sizeof(p[0]));
    cout<<"Points in convex hull are :";
    for( it=ch.begin(); it!=ch.end(); it++)
        cout<<" {"<<(*it).x<<","<<(*it).y<<"}";
    cout<<endl;
    
    return 0;
}
