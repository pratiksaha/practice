//Find triplet that sum to K
#include<iostream>
#include<algorithm>
using namespace std;

void tripletSumK(int A[], int n, int sum) {
    int i, l, r;
    
    int temp[n];
    for(i=0; i<n; i++)
        temp[i] = A[i];
    sort(temp, temp+n);
 
    bool found = false;
    for (i=0; i<n-2; i++) {
        l = i + 1;
        r = n-1;
        while (l < r) {
            if( temp[i]+temp[l]+temp[r] == sum) {
                cout<<"Triplet is "<<temp[i]<<" "<<temp[l]<<" "<<temp[r]<<endl;
                found = true;
                l++;
                r--;
            } else if (temp[i]+ temp[l]+temp[r] < sum) {
                l++;
            } else {
                r--;
            }
        }
    }
    if (!found)
        cout<<"No triplets found\n";
}

int main() {
    int A[] = {1, 2, 45, 4, 10, 8};
    int sum = 13;
    tripletSumK(A, sizeof(A)/sizeof(A[0]), sum);
    return 0;
}
