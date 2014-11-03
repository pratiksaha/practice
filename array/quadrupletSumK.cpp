//Find quadruplet that sum to K
#include<iostream>
#include<algorithm>
using namespace std;

typedef struct {
    int first, sec, sum;
}pairSum;

int compare (const void *a, const void * b) {
    return ( (*(pairSum *)a).sum - (*(pairSum*)b).sum );
}

bool noCommon(pairSum a, pairSum b) {
    if (a.first == b.first || a.first == b.sec || a.sec == b.first || a.sec == b.sec)
        return false;
    return true;
}

void quadrupletSumKopt(int arr[], int n, int X) {//O(n^2Logn)
    int i, j;
    int size = (n*(n-1))/2;
    pairSum aux[size];
 
    int k = 0;
    for (i=0; i<n-1; i++) {
        for (j=i+1; j<n; j++) {
            aux[k].sum = arr[i] + arr[j];
            aux[k].first = i;
            aux[k].sec = j;
            k++;
        }
    }
    
    qsort (aux, size, sizeof(aux[0]), compare);
    i = 0;
    j = size-1;
    bool found = false;
    while (i<size && j>=0 ) {
        if ( (aux[i].sum + aux[j].sum == X) && noCommon(aux[i], aux[j]) ) {
            cout<<"Quadruplet is "<<arr[aux[i].first]<<" "<<arr[aux[i].sec]<<" "<<arr[aux[j].first]<<" "<<arr[aux[j].sec]<<endl;
            found = true;
            i++;
            j--;
        } else if (aux[i].sum + aux[j].sum < X) {
            i++;
        } else {
            j--;
        }
    }
    if (!found)
        cout<<"No quadruplets found\n";
}

void quadrupletSumK(int A[], int n, int sum) {//O(n^3)
    int l, r, i, j;
    
    int temp[n];
    for(i=0; i<n; i++)
        temp[i] = A[i];
    sort(temp, temp+n);

    bool found = false;
    for (i=0; i<n-3; i++) {
        for (j=i+1; j<n-2; j++) {
            l = j + 1;
            r = n-1;
            while (l < r) {
                if( temp[i] + temp[j] + temp[l] + temp[r] == sum) {
                    cout<<"Quadruplet is "<<temp[i]<<" "<<temp[j]<<" "<<temp[l]<<" "<<temp[r]<<endl;
                    found = true;
                    l++;
                    r--;
                } else if (temp[i] + temp[j] + temp[l] + temp[r] < sum) {
                    l++;
                } else {
                    r--;
                }
            }
        }
    }
    if (!found)
        cout<<"No quadruplets found\n";
}

int main(){
    int arr[] = {10, 20, 30, 40, 1, 2};
    int sum = 91;
    quadrupletSumK(arr, sizeof(arr)/sizeof(arr[0]), sum);
    quadrupletSumKopt(arr, sizeof(arr)/sizeof(arr[0]), sum);
    return 0;
}
