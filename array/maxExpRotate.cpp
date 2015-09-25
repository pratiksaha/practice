//to find max value of SUM(i*arr[i])
#include <iostream>
using namespace std;

int maxExpRotate(int arr[], int n) {
    int arrSum = 0;
    int currVal = 0;
    for (int i=0; i<n; i++) {
        arrSum += arr[i];
        currVal += i*arr[i];
    }
    int maxVal = currVal;
    for (int j=1; j<n; j++) { //try all rotations one by one
        currVal = currVal + arrSum-n*arr[n-j];
        if (currVal > maxVal)
            maxVal = currVal;
    }
    return maxVal;
}

int main(void) {
    int arr[] = {10, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout<<"Max value of SUM(i*arr[i]) is "<<maxExpRotate(arr, sizeof(arr)/sizeof(arr[0]))<<endl;
    return 0;
}
