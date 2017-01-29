//count Triangles in a Rectangle
#include<bits/stdc++.h>
using namespace std;
#define MAX 2005

int bit[MAX][MAX];

void update(int x, int y) {
    int y1;
    while (x < MAX) {
        y1 = y;
        while ( y1 < MAX ) {
            bit[x][y1]++;
            y1 += ( y1 & -y1 );
        }
        x += x & -x;
    }
}

int query(int x, int y) {
    int res = 0, y1;
    while (x > 0) {
        y1 = y;
        while (y1 > 0) {
            res += bit[x][y1];
            y1 -= y1 & -y1;
        }
        x -= x & -x;
    }
    return res;
}

int pointsInRectangle(int x1, int y1, int x2, int y2) {
    return query(x2, y2) - query(x1 - 1, y2) -query(x2, y1 - 1) + query(x1 - 1, y1 - 1);
}

int countTrianglesInRectangle(int n) {
    return (n * (n - 1) * (n - 2)) / 6;
}

int main() {
    update(2, 2);
    update(3, 5);
    update(4, 2);
    update(4, 5);
    update(5, 4);
    cout<<"No. of triangles in the rectangle (1, 1) & (6, 6) are : "<<countTrianglesInRectangle(pointsInRectangle(1, 1, 6, 6))<<endl;
    update(3, 3);
    cout<<"No. of triangles in the rectangle (1, 1) & (6, 6) are : "<<countTrianglesInRectangle(pointsInRectangle(1, 1, 6, 6))<<endl;
    return 0;
}
