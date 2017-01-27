//to count number of triangles that can be formed with given points
#include <bits/stdc++.h>
using namespace std;

struct point {
   int x, y;
};

typedef point Point;

int determinant(int x1, int y1, int x2, int y2, int x3, int y3) {
   return x1*(y2 - y3) - y1*(x2 - x3) + 1*(x2*y3 - y2*x3);
}

int countTriangles(Point arr[], int n) {
    int result = 0;
    for (int i=0; i<n; i++)
        for (int j=i+1; j<n; j++)
            for (int k=j+1; k<n; k++)
                if (determinant(arr[i].x, arr[i].y, arr[j].x, arr[j].y, arr[k].x, arr[k].y)) //Cramer's rule
                    result++;
    return result;
}

int main() {
    Point arr[] = {{0, 0}, {1, 1}, {2, 0}, {2, 2}};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"No of triangles that can be formed is "<<countTriangles(arr, n)<<endl;
    return 0;
}
