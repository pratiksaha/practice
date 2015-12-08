//to check if any 2 lines interesect in a set
//TODO FIX CODE
//--std=c++11
#include<bits/stdc++.h>
using namespace std;

struct point {
    int x, y;
};

typedef point Point;

typedef struct {
    Point left, right;
}Line;

enum end_type {left_point, right_point};

struct pointCompareX {
    bool operator() (const Point& p, const Point& q) const {
        if (p.x == q.x)
            return (p.y <= q.y);
        else
            return (p.x <= q.x);
    }
};

struct pointCompareY {
    bool operator() (const Point& p, const Point& q) const {
        if (p.y == q.y)
            return (p.x <= q.x);
        else
            return (p.y <= q.y);
    }
};

void printLines(Line lines[], int n) {
    cout<<"Lines :";
    for (int i=0; i<n; i++)
        cout<<" {("<<lines[i].left.x<<","<<lines[i].left.y<<")-("<<lines[i].right.x<<","<<lines[i].right.y<<")}";
    cout<<endl;
}

bool onSegment(Point p, Point q, Point r) {
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) && q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
        return true;
    else
        return false;
}

int orientation(Point p1, Point p2, Point p3) {
    int val = (p2.y - p1.y)*(p3.x - p2.x) - (p2.x - p1.x)*(p3.y - p2.y);
    return ((val==0)?0:(val>0?1:2));
}

bool checkIntersect(Point p1, Point q1, Point p2, Point q2) {
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

int checkLineIntersectionSet(Line lines[], int n) {
    map<Point, int, pointCompareX> allPoints;
    map<Point, Line> lookup;
    for (int i=0; i<n; i++) {
        if (allPoints.find(lines[i].left) == allPoints.end())
            allPoints.insert(make_pair(lines[i].left, left_point));
        else
            return i;
        if (allPoints.find(lines[i].right) == allPoints.end())
            allPoints.insert(make_pair(lines[i].right, right_point));
        else
            return i;
        lookup.insert(make_pair(lines[i].left, lines[i]));
        lookup.insert(make_pair(lines[i].right, lines[i]));
    }
    set<Point, pointCompareY> active;
    for (map<Point, int, pointCompareX>::iterator it = allPoints.begin(); it != allPoints.end(); it++) {
        if (it->second == left_point) {
            active.insert(it->first);
            set<Point, pointCompareY>::iterator curr, p, n;
            curr = active.find(it->first);
            p = prev(curr);
            n = next(curr);
            map<Point, Line>::iterator l1, l2, l3;
            l1 = lookup.find(*curr);
            if (p != active.end() ) {
                l2 = lookup.find(*p);
                if (l1 != lookup.end() && l2 != lookup.end() && checkIntersect(l1->second.left, l1->second.right, l2->second.left, l2->second.right))
                    return true;
            }
            if (n != active.end()) {
                l3 = lookup.find(*n);
                if (l1 != lookup.end() && l3 != lookup.end() && checkIntersect(l1->second.left, l1->second.right, l3->second.left, l3->second.right))
                    return true;
            }
            
        }
        if (it->second == right_point) {
            set<Point, pointCompareY>::iterator curr, p, n;
            curr = active.find(it->first);
            p = prev(curr);
            n = next(curr);
            map<Point, Line>::iterator l2, l3;
            l2 = lookup.find(*p);
            l3 = lookup.find(*n);
            if (l2 != lookup.end() && l3 != lookup.end() && checkIntersect(l2->second.left, l2->second.right, l3->second.left, l3->second.right))
                return true;
            active.erase(curr);
        }
    }
    
    return 0;
}

int main() {
    Line lines[5] = {{{4,1},{4,4}}, {{8,2},{7,3}}, {{1,1},{10,5}}, {{6,6},{10,6}}, {{7,2},{9,2}}};
    int n = sizeof(lines)/sizeof(lines[0]);
    printLines(lines, n);
    cout<<checkLineIntersectionSet(lines, n)<<endl;
    //checkLineIntersectionSet(lines, n)?cout<<"True\n":"False\n";
    return 0;
}
