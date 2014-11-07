//count number of triangles that can be formed from given array
#include<iostream>
#include<algorithm>
using namespace std;

int possibleTriangles(int arr[], int n) {
    int t[n];
    for(int i =0; i<n; i++)
        t[i] = arr[i];
    sort(t, t+n);
 
    int count = 0;
    for (int i=0; i<n-2; i++) {
        for (int j=i+1; j<n; j++) {
            int k = i+2;
            while ( (k<n) && (arr[i]+arr[j] > arr[k]) ) //Find the rightmost element which is smaller than the sum of two fixed elements
                k++;
            count += k-j-1;
        }
    }
    return count;
}

int main() {
    int arr[] =   {10, 21, 22, 100, 101, 200, 300};
    cout<<"Total number of triangles possible is "<<possibleTriangles(arr, sizeof(arr)/sizeof(arr[0]))<<endl;
    return 0;
}
