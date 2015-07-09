//to print frequencies
#include<iostream>
#include<cmath>
using namespace std;

void findCount(int *arr, int n) {
    int i;
    cout<<"For array :";
    for (i=0; i<n; i++)
        cout<<" "<<arr[i];
    cout<<endl;
    i = 0;
    while (i<n) {
        if (arr[i]<=0) {
            i++;
            continue;
        }
        int idx = arr[i]-1;
        if (arr[idx] > 0) {
            arr[i] = arr[idx];
            arr[idx] = -1;
        } else {
            arr[idx]--;
            arr[i] = 0;
            i++;
        }
    }
    cout<<"Counts of all elements :\n";
    for (i=0; i<n; i++)
        cout<<i+1<<" => "<<abs(arr[i])<<endl;
}

int main() {
    int arr1[] = {1};
    findCount(arr1, sizeof(arr1)/ sizeof(arr1[0]));
    int arr3[] = {4, 4, 4, 4};
    findCount(arr3, sizeof(arr3)/ sizeof(arr3[0]));
    int arr2[] = {1, 3, 5, 7, 9, 1, 3, 5, 7, 9, 1};
    findCount(arr2, sizeof(arr2)/ sizeof(arr2[0]));
    int arr4[] = {3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3};
    findCount(arr4, sizeof(arr4)/ sizeof(arr4[0]));
    int arr5[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    findCount(arr5, sizeof(arr5)/ sizeof(arr5[0]));
    int arr6[] = {11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    findCount(arr6, sizeof(arr6)/ sizeof(arr6[0]));
    int arr7[] = {2, 3, 3, 2, 5};
    findCount(arr7, sizeof(arr7)/ sizeof(arr7[0]));
    return 0;
}
