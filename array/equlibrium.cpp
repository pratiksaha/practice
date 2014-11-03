//find the equilibrium index of an array which is an index such that the sum of elements at lower indices is equal to the sum of elements at higher indices
#include<iostream>
using namespace std;
 
int equilibrium(int arr[], int n) {
    int sum = 0; //sum of whole array
    int leftsum = 0; //leftsum
    int i;
    for (i=0; i<n; i++)
        sum += arr[i];

    for (i=0; i<n; i++) {
        sum -= arr[i]; //sum is now right sum for index i
        if(leftsum == sum)
            return i;
 
        leftsum += arr[i];
    }
    return -1;
}
 
int main() {
    int arr[] = {-7, 1, 5, 2, -4, 3, 0};
    cout<<"First equilibrium index is "<<equilibrium(arr, sizeof(arr)/sizeof(arr[0]))<<endl;
    return 0;
}
