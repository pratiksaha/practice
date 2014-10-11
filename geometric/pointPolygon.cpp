//Check if a point lies in a given polygon
#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;
 
struct Point
{
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
 
//Returns true if the point p lies inside the polygon[] with n vertices
bool isInside(struct Point polygon[], int n, struct Point p)
{ 
    if (n < 3) //There must be at least 3 vertices in polygon[]
        return false;
 
    struct Point extreme = {INT_MAX, p.y}; //Create a point for line segment from p to infinite
    
    int count = 0, i = 0;
    do {// Count intersections of the above line with sides of polygon
        int next = (i+1)%n;
        // Check if the line segment from 'p' to 'extreme' intersects with the line segment from 'polygon[i]' to 'polygon[next]'
        if (checkIntersect(polygon[i], polygon[next], p, extreme)) {
            // If the point 'p' is colinear with line segment 'i-next', then check if it lies on segment. If it lies, return true, otherwise false
            if (orientation(polygon[i], p, polygon[next]) == 0)
                return onSegment(polygon[i], p, polygon[next]);
            count++;
        }
        i = next;
    } while (i != 0);
  
    return count&1; // Return true if count is odd, false otherwise
}
 
// Driver program to test above functions
int main()
{
    struct Point p1, p2, p3, p4, p;
    int n;
    
    p1.x = 0;
    p1.y = 0;
    p2.x = 10;
    p2.y = 0;
    p3.x = 10;
    p3.y = 10;
    p4.x = 0;
    p4.y = 10;
    struct Point polygon1[] = {p1, p2, p3, p4};
    n = sizeof(polygon1)/sizeof(polygon1[0]);
    
    p.x = 20;
    p.y = 20;
    cout<<(isInside(polygon1, n, p)?"Yes":"No")<<endl;
    
    p.x = 5;
    p.y = 5;
    cout<<(isInside(polygon1, n, p)?"Yes":"No")<<endl;
    
    p.x = -1;
    p.y = 10;
    cout<<(isInside(polygon1, n, p)?"Yes":"No")<<endl;
    
    p1.x = 0;
    p1.y = 0;
    p2.x = 5;
    p2.y = 5;
    p3.x = 5;
    p3.y = 0;
    struct Point polygon2[] = {p1, p2, p3};
    n = sizeof(polygon2)/sizeof(polygon2[0]);
    
    p.x = 3;
    p.y = 3;
    cout<<(isInside(polygon2, n, p)?"Yes":"No")<<endl;
    
    p.x = 5;
    p.y = 1;
    cout<<(isInside(polygon2, n, p)?"Yes":"No")<<endl;
    
    p.x = 8;
    p.y = 1;
    cout<<(isInside(polygon2, n, p)?"Yes":"No")<<endl;
 
    return 0;
}
