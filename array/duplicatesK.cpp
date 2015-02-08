//check for duplicates within k distance
//Using features of C++ Standard (2011) Compile using g++ -std=c++11
#include<iostream>
#include<unordered_map>
using namespace std;

bool checkDuplicatesK(int arr[], int n, int k) {
    unordered_multimap<int, int> table;
    unordered_multimap<int, int>::iterator it;
    for(int i=0; i<n; i++) {
        if (table.find(arr[i]) != table.end()) { //if duplicate found
            return true;
        }
        table.insert(make_pair(arr[i], 1));
        if (i>=k) {
            it = table.find(arr[i-k]); //fetch any onr iterator to the rquired element
            table.erase(it); //remove any one
        }
    }
    return false;  
}

int main() {
    int arr1[] = {10, 5, 3, 4, 3, 5, 6};
    int arr2[] = {1, 2, 3, 4, 1, 2, 3, 4};
    int arr3[] = {1, 2, 3, 1, 4, 5};
    int arr4[] = {1, 2, 3, 4, 5};
    int arr5[] = {1, 2, 3, 4, 4};
    cout<<checkDuplicatesK(arr1, sizeof(arr1)/sizeof(arr1[0]), 3)<<endl;
    cout<<checkDuplicatesK(arr2, sizeof(arr2)/sizeof(arr2[0]), 3)<<endl;
    cout<<checkDuplicatesK(arr3, sizeof(arr3)/sizeof(arr3[0]), 3)<<endl;
    cout<<checkDuplicatesK(arr4, sizeof(arr4)/sizeof(arr4[0]), 3)<<endl;
    cout<<checkDuplicatesK(arr5, sizeof(arr5)/sizeof(arr5[0]), 3)<<endl;
    return 0;
}
