//to find the largest product number
//Using features of C++ Standard (2011) Compile using g++ -std=c++11
#include<bits/stdc++.h>
using namespace std;

int greatestProductPair(int arr[], int n) {
    unordered_map<int, int> m;
    for (int i = 0 ; i < n; i++)
        m[arr[i]]++;
    sort(arr, arr+n);
    for (int i=n-1; i>1; i--) {
        for (int j=0; j<i && arr[j]<=sqrt(arr[i]); j++) {
            if (arr[i] % arr[j] == 0) {
                int result = arr[i]/arr[j];
                if (result != arr[j] && m[result] > 0)
                    return arr[i];
                else if (result == arr[j] && m[result] > 1)
                    return arr[i];
            }
        }
    }
    return -1;
}

int main() {
    int arr[] = {17, 2, 1, 15, 30};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<greatestProductPair(arr, n)<<endl;
    return 0;
}
