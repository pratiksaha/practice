//to find four different elements a,b,c and d of array such that a+b = c+d
//Using features of C++ Standard (2011) Compile using g++ -std=c++11
#include<iostream>
#include<unordered_map>
using namespace std;
 
bool findabcd(int arr[], int n) {
    unordered_map<int, pair<int, int> > hash;
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            int sum = arr[i] + arr[j];
            if (hash.find(sum) == hash.end()) {
                hash[sum] = make_pair(i, j);
            } else {
                pair<int, int> pp = hash[sum];
                cout<<"("<<arr[pp.first]<<", "<<arr[pp.second]<<") and ("<<arr[i]<<", "<<arr[j] << ")\n";
                return true;
            }
        }
    }
    cout<<"No pairs found\n";
    return false;
}

int main() {
    int arr[] = {3, 4, 7, 1, 2, 9, 8};
    findabcd(arr, sizeof(arr)/sizeof(arr[0]));
    return 0;
}
