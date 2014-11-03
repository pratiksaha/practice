//print elements with count more than n/k occurences
#include<iostream>
#include<climits>
using namespace std;

typedef struct {
    int ele, cnt; 
}elemCount;

void occurences(int arr[], int n, int k) {
    if (k<2)
        return;
    int i, j, l;
    elemCount temp[k-1];
    for (int i=0; i<k-1; i++) {
        temp[i].ele = INT_MIN;
        temp[i].cnt = 0;
    }

    for (i=0; i<n; i++) {
        for (j=0; j<k-1; j++) {
            if (temp[j].ele == arr[i]) {
                 temp[j].cnt += 1;
                 break;
            }
        }
        if (j == k-1) {
            for (l=0; l<k-1; l++) {
                if (temp[l].cnt == 0) {
                    temp[l].ele = arr[i];
                    temp[l].cnt = 1;
                    break;
                }
            }
            if (l == k-1) {
                for (l=0; l<k; l++) {
                    temp[l].cnt -= 1;
                }
            }
        }
    }
    for (i=0; i<k-1; i++) {
        int ac = 0;
        for (j=0; j<n; j++)
            if (arr[j] == temp[i].ele)
                ac++;
        if (ac>n/k)
            cout<<"Number:"<<temp[i].ele<<"-->Count:"<<ac<<endl;
    }
}
 
int main() {
    cout<<"First Test\n";
    int arr1[] = {4, 5, 6, 7, 8, 4, 4};
    int size = sizeof(arr1)/sizeof(arr1[0]);
    int k = 3;
    occurences(arr1, size, k);
 
    cout<<"Second Test\n";
    int arr2[] = {4, 2, 2, 7};
    size = sizeof(arr2)/sizeof(arr2[0]);
    k = 3;
    occurences(arr2, size, k);
 
    cout<<"Third Test\n";
    int arr3[] = {2, 7, 2};
    size = sizeof(arr3)/sizeof(arr3[0]);
    k = 2;
    occurences(arr3, size, k);
 
    cout<<"Fourth Test\n";
    int arr4[] = {2, 3, 3, 2};
    size = sizeof(arr4)/sizeof(arr4[0]);
    k = 3;
    occurences(arr4, size, k);
 
    return 0;
}
