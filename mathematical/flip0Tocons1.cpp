//to find positions of zeroes flipping which produces maximum number of consecutive ones
#include<iostream>
using namespace std;

void flip0Tocons1(int arr[], int n, int m) {
    int wL = 0, wR = 0;  
    int bestL = 0, bestWindow = 0; 
    int zeroCount = 0;
    while (wR < n) {
        if (zeroCount <= m) {
            if (arr[wR] == 0)
                zeroCount++;
            wR++;
        }
        if (zeroCount > m) {
            if (arr[wL] == 0)
                zeroCount--;
            wL++;
        }
        if (wR-wL > bestWindow) {
            bestWindow = wR-wL;
            bestL = wL;
        }
    }
    cout<<"Indexes of zeroes to be flipped are:";
    for (int i=0; i<bestWindow; i++)
        if (arr[bestL+i] == 0)
            cout<<" "<<bestL+i;
    cout<<endl;
}

int main() {
    int arr[] = {1, 0, 0, 1, 1, 0, 1, 0, 1, 1};
    int m = 2;
    flip0Tocons1(arr, sizeof(arr)/sizeof(arr[0]), m);
    return 0;
}
