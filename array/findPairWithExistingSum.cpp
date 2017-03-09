//to find pair whose sum already exists in array
//Using features of C++ Standard (2011) Compile using g++ -std=c++11
#include<bits/stdc++.h>
using namespace std;

void findPairWithExistingSum(int arr[], int n) {
    unordered_set <int> s;
    for (int i=0; i<n; i++)
        s.insert(arr[i]);
    bool found = false;
    for (int i=0; i < n; i++) {
        for (int j=i+1 ; j < n ; j++) {
            if (s.find(arr[i] + arr[j]) != s.end()) {
                cout<<arr[i]<<" "<<arr[j]<<endl;
                found = true;
            }
        }
    }
    if (found == false)
        cout<<"No such pairs\n";
}

int main() {
    int arr[] = {10, 4, 8, 13, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    findPairWithExistingSum(arr,n);
    return 0;
}
