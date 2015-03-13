//to find the subsequence of length 3 having maximum product with the numbers of the subsequence being in ascending order
#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>
using namespace std;

void fillLargestSmallerLeft(int *in, int *out, int n) { //find the largest smaller element on left of given element
    vector<int> v;
    vector<int>::iterator it;
    int min = INT_MAX, max = INT_MIN;
    for (int i=0; i<n; i++) {
        int curr = in[i];
        if (curr < min) {
            min = curr;
            out[i] = 0;
            v.insert(v.begin(), curr);
        } else if (curr > max) {
            max = curr;
            out[i] = v.back();
            v.insert(v.end(), curr);
        } else {
            it = upper_bound(v.begin(), v.end(), curr);  //log(n)
            out[i] = *(it-1);
            v.insert(it, curr);
        }
    }
}

void fillLargestGreaterRight(int *in, int *out, int n) { //find the largest greater element on right of each element
    int largest = in[n-1];
    out[n-1] = 0;
    for (int i=n-2; i>=0; i--) {
        if (in[i+1] > largest)
            largest = in[i+1];
        out[i] = largest;
    }
}

void max3ProdIncrSubSeq(int *arr, int n) { //O(nlogn) + O(n) + O(n) = O(nlogn)
    int *lsl = new int[n];
    int *lgr = new int[n];
    fillLargestSmallerLeft(arr, lsl, n);  //O(nlogn)
    fillLargestGreaterRight(arr, lgr, n); //O(n)
    int x=0, y=0, z=0;
    int max_so_far = INT_MIN;
    int ind = 0;
    for (int i=1; i<n-1; i++) { //O(n)
        if (lsl[i] < arr[i] && arr[i] < lgr[i]) {
            int curr = lsl[i]*arr[i]*lgr[i];
            if (curr > max_so_far) {
                max_so_far = curr;
                ind = i;
            }
        }
    }
    cout<<"For Input Array :";
    for (int i=0; i<n; i++)
        cout<<" "<<arr[i];
    cout<<" Incr SubSeq with max prod : "<<lsl[ind]<<" "<<arr[ind]<<" "<<lgr[ind]<<endl;
    delete []lsl;
    delete []lgr;
}

int main() {
    int arr1[] = {6, 7, 8, 1, 2, 3, 9, 10};
    int arr2[] = {1, 5, 10, 8, 9};
    max3ProdIncrSubSeq(arr1, sizeof(arr1)/sizeof(arr1[0]));
    max3ProdIncrSubSeq(arr2, sizeof(arr2)/sizeof(arr2[0]));
    return 0;
}
