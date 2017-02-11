//to find if there exist three elements in Geometric Progression or not in a sorted array
#include<bits/stdc++.h>
using namespace std;

void findGeometricTriplets(int arr[], int n) {
    for (int j = 1; j < n - 1; j++) {
        int i = j - 1, k = j + 1;
        while (i >= 0 && k <= n - 1) {
            while (arr[j] % arr[i] == 0 && arr[k] % arr[j] == 0 && arr[j] / arr[i] == arr[k] / arr[j]) {
                cout<<arr[i]<<" "<<arr[j]<<" "<<arr[k]<<endl;
                k++;
                i--;
            }
            if(arr[j] % arr[i] == 0 && arr[k] % arr[j] == 0) {
                if(arr[j] / arr[i] < arr[k] / arr[j])
                    i--;
                else
                    k++;
            } else if (arr[j] % arr[i] == 0) {
                k++;
            } else {
                i--;
            }
        }
    }
}
 
int main() {
    int arr[] = {1, 2, 4, 16};
    int n = sizeof(arr) / sizeof(arr[0]);
    findGeometricTriplets(arr, n);
    return 0;
}
