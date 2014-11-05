//find the max repeating number in O(n) time and O(1) auxillary space
#include<iostream>
#include<climits>
using namespace std;

int maxRepeating(int* arr, int n) {
    int i, k;
    
    k = INT_MIN;
    for (i=0; i<n; i++)
        if( arr[i]> k)
            k = arr[i];
    k++;//k is max_value+1
        
    for (i=0; i<n; i++)
        arr[arr[i]%k] += k;

    int max = arr[0];
    int result = 0;
    for (i=1; i<n; i++) {
        if (arr[i]>max) {
            max = arr[i];
            result = i;
        }
    }
 
    for (i=0; i<n; i++) //regenerate the original array
        arr[i] = arr[i]%k; 
 
    return (max/k>1)?result:-1;
}

int main() {
    int arr[] = {2, 3, 3, 5, 3, 4, 1, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
    int res = maxRepeating(arr, sizeof(arr)/sizeof(arr[0]));
    if (res == -1)
        cout<<"All elements are unique\n";
    else
        cout<<"Max Repeating element is "<<res<<endl;
    return 0;
}
