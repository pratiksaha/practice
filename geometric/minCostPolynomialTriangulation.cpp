//A DP based sol to find min cost of convex polygon triangulation
#include<iostream>
#include<cmath>
#include<cfloat>
#include<algorithm>
using namespace std;

struct point{
    int x, y;
};

typedef struct point Point;

double dist(Point p1, Point p2) {
    return sqrt( (p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y) );
}

double cost(Point points[], int i, int j, int k) {
    Point p1 = points[i];
    Point p2 = points[j];
    Point p3 = points[k];
    return dist(p1,p2)+dist(p2,p3)+dist(p3,p1);
}

double minCostPolyTriang(Point points[], int n) {
    if (n<3)
        return 0;

    double table[n][n]; //table[i][j] = cost of triangulation of points from i to j

    for (int gap=0; gap<n; gap++) {
        for (int i=0, j=gap; j<n; i++, j++) {
            if (j < i+2) {
                table[i][j] = 0.0;
            } else {
                table[i][j] = DBL_MAX;
                for (int k=i+1; k<j; k++) {
                    double val = table[i][k]+table[k][j]+cost(points,i,j,k);
                    if (table[i][j] > val)
                        table[i][j] = val;
                }
            }
        }
    }
    return  table[0][n-1];
}

int main() {
    Point points[] = {{0, 0}, {1, 0}, {2, 1}, {1, 2}, {0, 2}};
    cout<<"Minimum Cost for Polynomial Triangulation :"<<minCostPolyTriang(points, sizeof(points)/sizeof(points[0]))<<endl;;
    return 0;
}
