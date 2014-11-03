//Max sum such that no two elements are adjacent
#include<iostream>
using namespace std; 

int maxSumUnadjacent(int arr[], int n) {
    int incl = arr[0];
    int excl = 0;
    int excl_new;
    int i;
 
    for (i=1; i<n; i++) {
        excl_new = (incl>excl)?incl:excl;
        incl = excl + arr[i];
        excl = excl_new;
    }

    return ((incl>excl)?incl:excl);
}

int main() {
    int arr[] = {5, 5, 10, 100, 10, 5};
    cout<<"Max sum such that no two elements are adjacent = "<<maxSumUnadjacent(arr, sizeof(arr)/sizeof(arr[0]))<<endl;
    return 0;
}
