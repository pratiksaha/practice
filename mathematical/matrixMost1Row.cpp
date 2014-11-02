//Find the row with the maximum number of 1s in a boolean matrix where each row is sorted
#include<iostream>
using namespace std;
#define R 4
#define C 4

int firstOne(bool arr[], int low, int high) {
    if(high >= low) {
        int mid = (low+high)/2;
        if ( ( mid == 0 || arr[mid-1] == 0) && arr[mid] == 1)
            return mid;
        else if (arr[mid] == 0)
            return firstOne(arr, (mid + 1), high);
        else
            return firstOne(arr, low, (mid -1));
    }
    return -1;
}

int rowWithMax1s(bool M[R][C]) {
    int max_row_index = 0;
    int left_most_index = firstOne(M[0], 0, C-1) - 1;
    if (left_most_index == -1) //if 1 is not present in first row
        left_most_index = C-1;
 
    for (int i = 1; i < R; i++) {
        while (left_most_index >= 0 && M[i][left_most_index] == 1) { //move left until a 0 is found
           left_most_index-- ; //update left_most_index
           max_row_index = i;  //Update max_row_index
        }
    }
    return max_row_index;
}

int main() {
    bool M[R][C] = {{0, 0, 0, 1},
                    {0, 1, 1, 1},
                    {1, 1, 1, 1},
                    {0, 0, 0, 0}
                   };
    cout<<"Index of row with maximum 1s is "<<rowWithMax1s(M)<<endl;
    return 0;
}
