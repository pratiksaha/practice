//area of a polygon using shoelace formula
#include <bits/stdc++.h>
using namespace std;

double areaPolygon(double X[], double Y[], int n) {
    double area = 0.0;
    for (int i=0, j=n-1; i<n; i++) {
        area += (X[j] + X[i]) * (Y[j] - Y[i]);
        j = i;
    }
    return abs(area / 2.0);
}

int main() {
    double X[] = {0, 2, 4};
    double Y[] = {1, 3, 7};
    int n = sizeof(X)/sizeof(X[0]);
    cout<<"Area of the polygon is "<<areaPolygon(X, Y, n)<<endl;
    return 0;
}
