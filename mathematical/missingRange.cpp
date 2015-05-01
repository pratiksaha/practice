//print missing ranges
#include<iostream>
#include<cstring>
using namespace std;

void missingRange(int arr[], int n, int limit) {
    bool seen[limit];
    memset(seen, false, sizeof(limit));
    for (int i=0; i<n; i++)
        if (arr[i]<limit)
            seen[arr[i]] = true;
    int i = 0;
    while (i<limit) {
        if (seen[i] == false) { //find if there are more missing elements after if i is missing
            int j = i+1;
            while (j<limit && seen[j]==false)
                j++;
            (i+1 == j)? cout<<" "<<i: cout<<" "<<i<<"-"<<j-1;
            i = j;
        } else {
            i++;
        }
    }
}

int main() {
    int arr[] = {88, 105, 3, 2, 200, 0, 10};
    int limit = 100;
    cout<<"Missing nos under "<<limit<<" in thr array :";
    missingRange(arr, sizeof(arr)/sizeof(arr[0]), limit);
    cout<<endl;
    return 0;
}
