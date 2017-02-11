//to find the element removing which makes the omplete array GP
#include<bits/stdc++.h>
using namespace std;
#define EPS 1e-6

bool fEqual(double a, double b) {
    return (abs(a - b) < EPS);
}
 
bool isGP(double arr[], int N, int ignore) {
    double last = -1;
    double ratio = -1;
 
    for (int i = 0; i < N; i++) {
        if (i != ignore) {
            if (last != -1)
                if (ratio == -1)
                    ratio = (double)arr[i] / last;
                else if (!fEqual(ratio, (double)arr[i] / last))
                    return false;
            last = arr[i];
        }
    }
    return true;
}

int makeGPbyRemovingOneElement(double arr[], int N) {
    if (isGP(arr, N, 0))
        return 0;
    if (isGP(arr, N, 1))
        return 1;
    if (isGP(arr, N, N-1))
        return (N-1);
    double ratio = (double)arr[1]/arr[0];
    for (int i = 2; i < N; i++)
        if (!fEqual(ratio, (double)arr[i]/arr[i-1]))
            return (isGP(arr+i-2, N-i+2, 2))? i : -1;
    return -1;
}
 
int main() {
    double arr[] = {2, 4, 8, 30, 16};
    int N = sizeof(arr) / sizeof(arr[0]);
    int index = makeGPbyRemovingOneElement(arr, N);
    if (index == -1)
        cout<<"Not possible\n";
    else
        cout<<"Remove "<<arr[index]<< " to get geometric progression\n";
    return 0;
}
