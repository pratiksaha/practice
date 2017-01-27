//to find number of points lie inside or on the cirumference of circle for Q queries.
#include<bits/stdc++.h>
using namespace std;

void preCompute(int p[], int x[], int y[], int n) {
    for (int i=0; i<n; i++)
        p[i] = x[i]*x[i] + y[i]*y[i];
    sort(p, p + n);
}

int countPointsInCircle(int p[], int n, int rad) {
    int start = 0, end = n-1;
    while ((end - start)>1) {
        int mid = (start+end)/2;
        double tp = sqrt(p[mid]);
        if (tp > (rad*1.0))
            end = mid - 1;
        else
            start = mid;
    }
    double tp1 = sqrt(p[start]);
    double tp2 = sqrt(p[end]);
    if (tp1 > (rad*1.0))
        return 0;
    else if (tp2 <= (rad*1.0))
        return end+1;
    else
        return start+1;
}

int main() {
    int x[] = { 1, 2, 3, -1, 4 };
    int y[] = { 1, 2, 3, -1, 4 };
    int n = sizeof(x)/sizeof(x[0]);
    int p[n];
    preCompute(p, x, y, n);
    cout<<"number of points in a circle of radius 3 is "<<countPointsInCircle(p, n, 3)<<endl;
    cout<<"number of points in a circle of radius 32 is "<<countPointsInCircle(p, n, 32)<<endl;
    return 0;
}
