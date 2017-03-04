//to find minimum sum of two numbers formed from digits of the array
#include<bits/stdc++.h>
using namespace std;

int minSumTwoNos(int arr[], int n) {
    sort(arr, arr+n);
    int a = 0, b = 0;
    for (int i = 0; i < n; i++) {
        if (i & 1)
            a = a*10 + arr[i];
        else
            b = b*10 + arr[i];
    }
    return a + b;
}
 
int main() {
    int arr[] = {6, 8, 4, 5, 2, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Min Sum of 2 nos formed is "<<minSumTwoNos(arr, n)<<endl;
    return 0;
}
