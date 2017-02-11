//to print all combination of size r in an array of size n with repetitions allowed
#include<bits/stdc++.h>
using namespace std;

void combinationsWithRepetitions(int chosen[], int arr[], int index, int r, int start, int end) {
    if (index == r) {
        for (int i = 0; i < r; i++)
            cout<<arr[chosen[i]];
        cout<<endl;
    } else {
        for (int i = start; i <= end; i++) {
            chosen[index] = i;
            combinationsWithRepetitions(chosen, arr, index + 1, r, i, end);
        }
    }
}

void combinationsWithRepetitions(int arr[], int n, int r) {
    int chosen[r+1];
    combinationsWithRepetitions(chosen, arr, 0, r, 0, n-1);
}
 
int main() {
    int arr[] = {1, 2, 3, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    int r = 2;
    combinationsWithRepetitions(arr, n, r);
    return 0;
}
