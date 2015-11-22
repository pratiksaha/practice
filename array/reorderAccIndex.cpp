//to sort an array according to given indexes
#include<iostream>
using namespace std;

void reorderAccIndex(int arr[], int index[], int n) {
    for (int i=0; i<n; i++) {
        while (index[i] != i) {
            int  oldTargetI = index[index[i]];
            int oldTargetE = arr[index[i]];
            arr[index[i]] = arr[i];
            index[index[i]] = index[i];
            index[i] = oldTargetI;
            arr[i] = oldTargetE;
        }
    }
}

int main() {
    int arr[] = {50, 40, 70, 60, 90};
    int index[] = {3,  0,  4,  1,  2};
    int n = sizeof(arr)/sizeof(arr[0]);
    reorderAccIndex(arr, index, n); 
    cout<<"Reordered array is:";
    for (int i=0; i<n; i++)
        cout<<" "<<arr[i];
    cout<<endl;
    cout<<"Modified Index array is";
    for (int i=0; i<n; i++)
        cout<<" "<<index[i];
    cout<<endl;
    return 0;
}
