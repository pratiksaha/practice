//Program to check if two given line segments intersect
#include <iostream>
using namespace std;
 
struct Point {
    int x;
    int y;
};
 
// Given three colinear points p, q, r, the function checks if point q lies on line segment 'pr'
bool onSegment(struct Point p, struct Point q, struct Point r)
{
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) && q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
        return true;
    return false;
}
 
// To find orientation of ordered triplet (p, q, r).
// Returns 0 if p, q and r are colinear 1 if Clockwise 2 if Counterclockwise
int orientation(struct Point p, struct Point q, struct Point r)
{
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y); 
    if (val == 0)
        return 0;
    return (val > 0)? 1: 2;
}
 
//Returns true if line segment 'p1q1' and 'p2q2' intersect.
bool checkIntersect(struct Point p1, struct Point q1, struct Point p2, struct Point q2) {
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);
    
    if (o1 != o2 && o3 != o4) // General case
        return true;    
    if (o1 == 0 && onSegment(p1, p2, q1)) //p1, q1 and p2 are colinear and p2 lies on segment p1q1 
        return true;    
    if (o2 == 0 && onSegment(p1, q2, q1)) //p1, q1 and p2 are colinear and q2 lies on segment p1q1
        return true;
    if (o3 == 0 && onSegment(p2, p1, q2)) //p2, q2 and p1 are colinear and p1 lies on segment p2q2
        return true;
    if (o4 == 0 && onSegment(p2, q1, q2)) //p2, q2 and q1 are colinear and q1 lies on segment p2q2
        return true;
    return false;
}

int main()
{
    struct Point p1, q1, p2, q2;
    
    p1.x = 1;
    p1.y = 1;
    q1.x = 10;
    q1.y = 1;
    p2.x = 1;
    p2.y = 2;
    q2.x = 10;
    q2.y = 2;
    cout<<(checkIntersect(p1, q1, p2, q2)?"Yes":"No")<<endl;
    
    p1.x = 10;
    p1.y = 0;
    q1.x = 0;
    q1.y = 10;
    p2.x = 0;
    p2.y = 0;
    q2.x = 10;
    q2.y = 10;
    cout<<(checkIntersect(p1, q1, p2, q2)?"Yes":"No")<<endl;
    
    p1.x = -5;
    p1.y = -5;
    q1.x = 0;
    q1.y = 0;
    p2.x = 1;
    p2.y = 1;
    q2.x = 10;
    q2.y = 10;
    cout<<(checkIntersect(p1, q1, p2, q2)?"Yes":"No")<<endl;
 
    return 0;
}
