//to compute sum of pairwise bit differences
#include<iostream>
using namespace std;
 
int sumPairwiseBitDiff(int arr[], int n) {
    int ans = 0;
    for (int i=0; i<32; i++) {
        int count = 0;
        for (int j = 0; j < n; j++)
            if ((arr[j]&(1<<i)))
                count++;
        ans += (count*(n-count)*2);
    }
    return ans;
}

int main() {
    int arr[] = {1, 3, 5};
    cout<<sumPairwiseBitDiff(arr, sizeof(arr)/sizeof(arr[0]))<<endl;
    return 0;
}
