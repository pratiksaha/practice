//find sorted subsequence of size 3
#include<iostream>
using namespace std;

void sortedSubsequence3(int arr[], int n) {
    int max = n-1;
    int min = 0;
    int i;

    int *smaller = new int[n]; //store index of a smaller element on left side, -1 otherwise
    smaller[0] = -1;
    for (i=1; i<n; i++) {
        if (arr[i] <= arr[min]) {
            min = i;
            smaller[i] = -1;
        } else {
            smaller[i] = min;
        }
    }
    
    int *greater = new int[n];//store index of a greater element on right side, -1 otherwise
    greater[n-1] = -1;
    for (i=n-2; i>=0; i--) {
        if (arr[i] >= arr[max]) {
            max = i;
            greater[i] = -1;
        } else {
            greater[i] = max;
        }  
    }
    
    bool Found = false;
    for (i=0; i<n; i++) {
        if (smaller[i] != -1 && greater[i] != -1) {
            cout<<arr[smaller[i]]<<" "<<arr[i]<<" "<<arr[greater[i]]<<endl;
            Found = true;
        }
    }
    if (!Found)
        cout<<"No such triplet found\n";
 
    delete [] smaller;
    delete [] greater;
}

int main() {
    int arr[] = {12, 9, 10, 5, 6, 2, 30};
    sortedSubsequence3(arr, sizeof(arr)/sizeof(arr[0]));
    return 0;
}
