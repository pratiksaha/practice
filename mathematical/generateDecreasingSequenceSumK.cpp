//to generate all decreasing sequences of sum equals to x
#include<iostream>
using namespace std;

void printArray(int arr[], int n) {
    for (int i=0; i<n; i++)
        cout<<" "<<arr[i];
    cout<<endl;
}

void generateDecreasingSequenceSumK(int x, int arr[], int curr_sum, int curr_idx) {
    if (curr_sum == x) {
        printArray(arr, curr_idx);
    } else {
        int num = 1;
        while (num<=x-curr_sum && (curr_idx==0 || num<=arr[curr_idx-1])) {
            arr[curr_idx] = num;
            generateDecreasingSequenceSumK(x, arr, curr_sum+num, curr_idx+1);
            num++;
        }
    }
}

void generateDecreasingSequenceSumK(int x) {
    int arr[x];
    generateDecreasingSequenceSumK(x, arr, 0, 0);
}

int main() {
    int x = 5;
    generateDecreasingSequenceSumK(x);
    return 0;
}
