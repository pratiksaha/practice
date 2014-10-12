#include<iostream>
#include<cstdlib>
using namespace std;

int countSplit(int arr[], int temp[], int left, int mid, int right) {
    int i, j, k;
    int inv_count = 0;
  
    i = left; //left subarray
    j = mid;  //right subarray
    k = left; //resultant merged subarray
    while ((i <= mid-1) && (j <= right)) {
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

int main()
{
  int arr[] = {1, 20, 6, 4, 5};
  cout<<"Number of inversions are "<<countInversions(arr, sizeof(arr)/sizeof(arr[0]))<<endl;
  return 0;
}
