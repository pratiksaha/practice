//to group multiple occurrences of individual array elements
//Using features of C++ Standard (2011) Compile using g++ -std=c++11
#include<iostream>
#include<unordered_map>
using namespace std;

void groupElements(int arr[], int n) {
    unordered_map<int, int> hash;
    unordered_map<int, int>::iterator it;
    for (int i=0; i<n; i++) {
        it = hash.find(arr[i]);
        if (it != hash.end()) {
            it->second = it->second+1;
        } else {
            hash.insert(make_pair(arr[i], 1));
        }
    }
    cout<<"Grouped Elements :";
    for (int i=0; i<n; i++) {
        it = hash.find(arr[i]);
        if (it != hash.end()) {
            for (int j=0; j<it->second; j++)
                cout<<" "<<it->first;
            hash.erase(arr[i]);
        }
    }
    cout<<endl;
}

int main() {
    int arr[] = {4, 6, 9, 2, 3, 4, 9, 6, 10, 4};
    groupElements(arr, sizeof(arr)/sizeof(arr[0]));
    return 0;
}
