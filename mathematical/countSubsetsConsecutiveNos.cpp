//to find number of subset containing consecutive numbers
#include<bits/stdc++.h>
using namespace std;
 
int countSubsetsConsecutiveNos(int arr[], int n) {
    sort(arr, arr + n);
    int count = 1;
    for (int i = 0; i < n-1; i++)
        if (arr[i] + 1 != arr[i+1])
            count++;
    return count;
}

int main() {
    int arr[] = {100, 56, 5, 6, 102, 58, 101, 57, 7, 103, 59};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<countSubsetsConsecutiveNos(arr,n)<<endl;
    return 0;
}
