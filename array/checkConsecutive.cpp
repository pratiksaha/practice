//to check if array consists of consecutive numbers
#include<iostream>
#include<cstdlib>
using namespace std;
 
int getMin(int arr[], int n) {
    int min = arr[0];
    for (int i=1; i<n; i++)
        if (arr[i] < min)
            min = arr[i];
    return min;
}
 
int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i=1; i<n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

bool checkConsecutive(int arr[], int n) {
    if (n< 1)
        return false;
    
    int l = getMin(arr, n);
    int g = getMax(arr, n);
    int i, j;
    if (g-l+1 == n) {
        for(i=0; i<n; i++) {
            if (arr[i] < 0)
                j = -arr[i] - l;
            else
                j = arr[i] - l;          
            if (arr[j] > 0)
                arr[j] = -arr[j];
            else
                return false;
        }
        return true;
    } else {
        return false;
    }
}
 
int main() {
    int arr[] = {1, 4, 5, 3, 2, 6};
    if( checkConsecutive(arr, sizeof(arr)/sizeof(arr[0])))
        cout<<"Array elements are consecutive\n";
    else
        cout<<"Array elements are not consecutive\n";
    return 0;
}
