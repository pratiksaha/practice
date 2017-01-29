//Count Triangles among Lines
#include<bits/stdc++.h>
using namespace std;
#define MAXy 1000005
#define MAXn 10005

class point {
public:
    int x, y;
    point(int a, int b) {
        x = a, y = b;
    }
};

int bit[MAXy];
vector<pair<point, int> > events;

bool cmp(pair<point, int> &a, pair<point, int> &b) {
    if ( a.first.x != b.first.x ) {
        return a.first.x < b.first.x;
    } else {
        if (a.second == 3 && b.second == 3)
            return true;
        else if (a.second == 1 && b.second == 3)
            return true;
        else if (a.second == 3 && b.second == 1)
            return false;
        else if (a.second == 2 && b.second == 3)
            return false;
        else
            return true;
    }
}

void update(int idx, int val) {
    while (idx < MAXn) {
        bit[idx] += val;
        idx += idx & (-idx);
    }
}

int query(int idx) {
    int res = 0;
    while (idx > 0) {
        res += bit[idx];
        idx -= idx & (-idx);
    }
    return res;
}
 
void insertLine(point a, point b) {
    if (a.y == b.y) {
        int beg = min(a.x, b.x);
        int end = max(a.x, b.x);
        events.push_back(make_pair(point(beg, a.y), 1));
        events.push_back(make_pair(point(end, a.y), 2));
    } else {
        int up = max(b.y, a.y);
        int low = min(b.y, a.y);
        events.push_back(make_pair(point(a.x, up), 3));
        events.push_back(make_pair(point(a.x, low), 3));
    }
}
 
int findIntersectionPoints() {
    int intersection_pts = 0;
    for (int i = 0; i < events.size(); i++) {
        if (events[i].second == 1) {
            update(events[i].first.y, 1);
        } else if (events[i].second == 2) {
            update(events[i].first.y, -1);
        } else {
            int low = events[i++].first.y;
            int up = events[i].first.y;
            intersection_pts += query(up) - query(low);
        }
    }
    return intersection_pts;
}
 
int countTrianglesInLines() {
    int pts = findIntersectionPoints();
    if ( pts >= 3 )
        return (pts*(pts-1)*(pts-2))/6;
    else
        return 0;
}

int main() {
    insertLine(point(2, 1), point(2, 9));
    insertLine(point(1, 7), point(6, 7));
    insertLine(point(5, 2), point(5, 8));
    insertLine(point(3, 4), point(6, 4));
    insertLine(point(4, 3), point(4, 5));
    insertLine(point(7, 6), point(9, 6));
    insertLine(point(8, 2), point(8, 5));
    sort(events.begin(), events.end(), cmp);
    cout<<"Number of triangles are : "<<countTrianglesInLines()<<endl;
    return 0;
}
