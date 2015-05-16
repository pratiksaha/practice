//segment tree and its applications
#include<iostream>
#include<cmath>
#include<climits>
using namespace std;

void update(int *st, int ss, int se, int i, int diff, int index) {
    if (i>=ss && i<=se) {
        st[index] = st[index] + diff; //update the value of the node and its children if the input index is in range of this node
        if (se != ss) {
            int mid = (ss+se)/2;
            update(st, ss, mid, i, diff, 2*index + 1);
            update(st, mid+1, se, i, diff, 2*index + 2);
        }
    }
}

void update(int arr[], int *st, int n, int i, int new_val) {
    if (i<0 || i>n-1) {
        cout<<"Invalid Input\n";
    } else {
        int diff = new_val-arr[i];
        arr[i] = new_val;
        update(st, 0, n-1, i, diff, 0);
    }
}

int rangeSum(int *st, int ss, int se, int qs, int qe, int index) {
    if (se<qs || ss>qe) { //segment of this node is outside the given range
        return 0;
    } else if (qe>=se && qs<=ss) { //segment of this node is a part of given range
        return st[index];
    } else {
        int mid = (ss+se)/2;
        return rangeSum(st, ss, mid, qs, qe, 2*index+1) + rangeSum(st, mid+1, se, qs, qe, 2*index+2);
    }
}

int rangeSum(int *st, int n, int qs, int qe) {
    if (qs<0 || qe>n-1 || qs>qe) {
        cout<<"Invalid Input\n";
        return -1;
    } else {
        return rangeSum(st, 0, n-1, qs, qe, 0);
    }
}

int rangeMin(int *st, int ss, int se, int qs, int qe, int index) {
    if (se < qs || ss > qe) { //segment of this node is outside the given range
        return INT_MAX;
    } else if (qe >= se && qs<=ss) { //return the min of the segment if segment of this node is a part of given range
        return st[index];
    } else { //if a part of this segment overlaps with the given range
        int mid = (ss+se)/2;
        return min(rangeMin(st, ss, mid, qs, qe, 2*index+1), rangeMin(st, mid+1, se, qs, qe, 2*index+2));
    }
}

int rangeMin(int *st, int n, int qs, int qe) {
    if (qs<0 || qe>n-1 || qs>qe) {
        cout<<"Invalid Input\n";
        return -1;
    } else {
        return rangeMin(st, 0, n-1, qs, qe, 0);
    }
}

int segmentTreeSum(int arr[], int *st, int ss, int se, int si) {
    if (ss==se) {
        st[si] = arr[ss];
        return arr[ss];
    } else {
        int mid = (se+ss)/2;
        st[si] = segmentTreeSum(arr, st, ss, mid, si*2+1) + segmentTreeSum(arr, st, mid+1, se, si*2+2);
        return st[si];
    }
}

int segmentTreeMin(int arr[], int *st, int ss, int se, int si) {
    if (ss==se) {
        st[si] = arr[ss];
        return arr[ss];
    } else {
        int mid = (se+ss)/2;
        st[si] = min(segmentTreeMin(arr, st, ss, mid, si*2+1), segmentTreeMin(arr, st, mid+1, se, si*2+2));
        return st[si];
    }
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
    int height = (int)(ceil(log2(n)));
    int max_size = 2*(int)pow(2, height)-1;
    int *stSum = new int[max_size];
    int *stMin = new int[max_size];
    segmentTreeSum(arr, stSum, 0, n-1, 0);
    segmentTreeMin(arr, stMin, 0, n-1, 0);
    cout<<"Sum of values in range [1,3] is "<<rangeSum(stSum, n, 1, 3)<<endl;
    cout<<"Minimum of values in range [0,5] is "<<rangeMin(stMin, n, 0, 5)<<endl;
    update(arr, stSum, n, 1, 10);
    cout<<"Updated sum of values in range (1,3) is "<<rangeSum(stSum, n, 1, 3)<<endl;
    delete [] stSum;
    delete [] stMin;
    return 0;
}
