//find pair of elements with min sum
#include<iostream>
#include<cmath>
#include<climits>
#include<algorithm>
using namespace std;

void minAbsSumPair(int arr[], int n) {
    if(n < 2) {
        cout<<"Invalid Input\n";
        return;
    }
    int temp[n];
    int i;
    for(i=0; i<n; i++)
        temp[i] = arr[i];
        
    sort(temp, temp+n);
        
    int min_sum = INT_MAX;
    int l = 0;
    int r = n-1;
    int min_l = l;
    int min_r = n-1;
 
    while(l < r) {
        int sum = temp[l] + temp[r];
        if(abs(sum) < abs(min_sum)) {
            min_sum = sum;
            min_l = l;
            min_r = r;
        }
        if(sum < 0)
            l++;
        else
            r--;
    }
    cout<<"The two elements whose abs sum is minimum are "<<temp[min_l]<<" & "<<temp[min_r]<<endl;
}
 
int main() {
    int arr[] = {1, 60, -10, 70, -80, 85};
    minAbsSumPair(arr, sizeof(arr)/sizeof(arr[0]));
    return 0;
}
