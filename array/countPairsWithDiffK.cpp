//given A[] of N nos and another no S, count pairs in A whose diff is exactly S
//Using features of C++ Standard (2001) Compile using g++ -std=c++11
#include<iostream>
#include<climits>
#include<algorithm>
#include<unordered_map>
using namespace std;

int countPairsWithDiffK(int arr[], int n, int k) {
    int i;
    int temp[n];
    for(i=0; i<n; i++)
        temp[i] = arr[i];
    sort(temp, temp+n);  // Sort array elements
    int count = 0;
    for (i = 0; i<n-1; i++)
        if ( !binary_search(temp+i+1, temp+n, temp[i] + k))
            count++;
 
    return count;
}

int countPairsWithDiffKHash(int arr[], int n, int k) {
    unordered_map<int, int> table;
    int i;
    for (i=0; i<n; i++)
        table.insert(make_pair(arr[i], 1));
    int count = 0;
    for (i=0; i<n; i++) {
        int x = arr[i];
        if ( x-k >= 0 && table.find(x-k) != table.end() )
            count++;
        if ( x+k < INT_MAX && table.find(x+k) != table.end() )
            count++;
        table.erase(x);
    }
    return count;
}

int main() {
    int arr[] =  {1, 5, 3, 4, 2};
    int k = 3;
    cout<<"Count of pairs with given diff is "<<countPairsWithDiffK(arr, sizeof(arr)/sizeof(arr[0]), k)<<endl;
    cout<<"Count of pairs with given diff is "<<countPairsWithDiffKHash(arr, sizeof(arr)/sizeof(arr[0]), k)<<endl;
    return 0;
}
