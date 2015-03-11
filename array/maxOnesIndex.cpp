//to find index of 0 to be replaced with 1 to get longest continuous sequence of 1s in a binary array
#include<iostream>
using namespace std;

int maxOnesIndex(int *arr, int N) {
    int max_count = 0;
    int max_index;
    int prev_zero = -1;
    int prev_prev_zero = -1;
    for (int curr=0; curr<N; ++curr) { 
        if (arr[curr] == 0) { // calculate the diff b/w curr and prev_prev_zero if curr is 0 and update result if count of 1s around prev_zero is more    
            if (curr - prev_prev_zero > max_count) {
                max_count = curr - prev_prev_zero;
                max_index = prev_zero;
            }
            prev_prev_zero = prev_zero;
            prev_zero = curr;
        }
    }
    if (N-prev_prev_zero > max_count) //check for the last encountered zero
       max_index = prev_zero;
    return max_index;
}

int main() {
    int arr[] = {1, 1, 0, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1};
    cout<<"Index of 0 to be replaced is "<<maxOnesIndex(arr, sizeof(arr)/sizeof(arr[0]))<<endl;
    return 0;
}
