//Union and Intersection of two sorted arrays
#include<iostream>
using namespace std;

void Union(int arr1[], int m, int arr2[], int n) {
    cout<<"Union :";
    int i = 0, j = 0;
    while(i<m && j<n) {
        if(arr1[i]<arr2[j]) {
            cout<<" "<<arr1[i];
            i++;
        } else if(arr1[i]>arr2[j]) {
            cout<<" "<<arr2[j];
            j++;
        } else {
            cout<<" "<<arr1[i];
            i++;
            j++;
        }
    }
    while(i<m) {
        cout<<" "<<arr1[i];
        i++;
    }
    while(j<n) {
        cout<<" "<<arr2[j];
        j++;
    }
    cout<<endl;
}

void Intersection(int arr1[],  int m, int arr2[], int n) {
    cout<<"Intersection :";
    int i = 0, j = 0;
    while(i<m && j<n) {
        if(arr1[i]<arr2[j]) {
            i++;
        } else if(arr1[i]>arr2[j]) {
            j++;
        } else {
            cout<<" "<<arr1[i];
            i++;
            j++;
        }
    }
    cout<<endl;
}

int main() {
    int arr1[] = {1, 2, 4, 5, 6};
    int arr2[] = {2, 3, 5, 7};
    Union(arr1, sizeof(arr1)/sizeof(arr1[0]), arr2, sizeof(arr2)/sizeof(arr2[0]));
    Intersection(arr1, sizeof(arr1)/sizeof(arr1[0]), arr2, sizeof(arr2)/sizeof(arr2[0]));
    return 0;
}
