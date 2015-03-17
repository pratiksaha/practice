//to check if a given instance of 8 puzzle is solvable or not
#include<iostream>
#include<cstdlib>
using namespace std;
 
int countSplit(int arr[], int temp[], int left, int mid, int right) {
    int i, j, k;
    int inv_count = 0;
    i = left; //left subarray
    j = mid; //right subarray
    k = left; //resultant merged subarray
    while ((i <= mid-1) && (j <= right)) { //special handling for 0 since it should not be counted in inversions for this problem
        if (arr[i] == 0) {
            temp[k++] = arr[i++];
            continue;
        }
        if (arr[j] == 0) {
            temp[k++] = arr[j++];
            continue;
        }
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            inv_count += (mid - i);
        }
    }
    while (i <= mid - 1)//copy any remaining elements of left subarray to temp
        temp[k++] = arr[i++];
    while (j <= right)//copy any remaining elements of right subarray to temp
        temp[k++] = arr[j++];
    for (i=left; i <= right; i++)//Copy back the merged elements to original array
        arr[i] = temp[i];
    return inv_count;
}

int countInv(int arr[], int temp[], int left, int right) {
    int mid, inv_count = 0;
    if (right > left) {
        mid = (right + left)/2;
        inv_count += countInv(arr, temp, left, mid); //count inversions in the left subarray
        inv_count += countInv(arr, temp, mid+1, right); //count inversions in the right subarray
        inv_count += countSplit(arr, temp, left, mid+1, right);//count split inversions
    }
    return inv_count;
}

int countInversions(int arr[], int n) {
    int *temp = (int *)malloc(sizeof(int)*n);
    return countInv(arr, temp, 0, n-1);
}

bool checkSolvable8Puzzle(int puzzle[3][3]) {
    int invCount = countInversions((int *)puzzle, 9);
    return (invCount%2 == 0); //puzzle is solvable if invCount is even
}

void printPuzzle(int puzzle[3][3]) {
    cout<<"Puzzle :\n";
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            cout<<" "<<puzzle[i][j];
        }
        cout<<endl;
    }
}
int main() {
    int puzzle1[3][3] ={{1, 8, 2},
                        {0, 4, 3},
                        {7, 6, 5}};
    int puzzle2[3][3] ={{8, 1, 2},
                        {0, 4, 3},
                        {7, 6, 5}};
    printPuzzle(puzzle1);
    checkSolvable8Puzzle(puzzle1)?cout<<"Solvable\n\n":cout << "Not Solvable\n\n";
    printPuzzle(puzzle2);
    checkSolvable8Puzzle(puzzle2)?cout<<"Solvable\n\n":cout << "Not Solvable\n\n";
    return 0;
}
