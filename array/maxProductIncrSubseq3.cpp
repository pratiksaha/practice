//to find maximum product of an increasing subsequence of size 3
#include<bits/stdc++.h>
using namespace std;

long long int maxProductIncrSubseq3(int arr[] , int n) {
    int smaller[n];
    smaller[0] = -1 ;
    set<int>S ;
    for (int i = 0; i < n ; i++) {
        pair<set<int>::iterator, bool> j = S.insert(arr[i]);
        set<int>::iterator itc = j.first;
        itc--;
        if (itc != S.end())
            smaller[i] = *itc;
        else
            smaller[i] = -1;
    }
    int result = INT_MIN;
    int max_right = arr[n-1];
    for (int i=n-2 ; i >= 1; i--) {
        if (arr[i] > max_right)
            max_right = arr[i];
        else if (smaller[i] != -1)
            result = max(smaller[i] * arr[i] * max_right, result);
    }
    return result;
}

int main() {
    int arr[] = {10, 11, 9, 5, 6, 1, 20};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<maxProductIncrSubseq3(arr, n)<<endl;
    return 0;
}
