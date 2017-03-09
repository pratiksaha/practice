//to rearrange an array such that sum of product of alternate element is minimum
#include<bits/stdc++.h>
using namespace std;

void printArray(int arr[], int n) {
    for (int i=0; i<n; i++)
        cout<<" "<<arr[i];
    cout<<endl;
}

int rearrangeToMinSumOfAlternateProduct(int arr[], int n) {
    vector<int> evenArr;
    vector<int> oddArr;
    sort(arr, arr+n );
    for (int i = 0; i < n; i++)
        if (i < n/2)
            oddArr.push_back(arr[i]);
        else
            evenArr.push_back(arr[i]);
    sort(evenArr.begin(), evenArr.end(), greater<int>());
    int i = 0, sum = 0;
    for (int j=0; j<evenArr.size(); j++) {
        arr[i++] = evenArr[j];
        arr[i++] = oddArr[j];
        sum += evenArr[j] * oddArr[j];
    }
    return sum;
}

int main() {
    int arr[] = { 1, 5, 8, 9, 6, 7, 3, 4, 2, 0 };
    int n = sizeof(arr)/sizeof(arr[0]);
    printArray(arr, n);
    cout<<"Minimum required sum = "<<rearrangeToMinSumOfAlternateProduct(arr, n)<<endl;
    printArray(arr, n);
    return 0;
}
