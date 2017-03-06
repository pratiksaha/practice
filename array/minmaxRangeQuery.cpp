//to find minimum and maximum in range query
#include<bits/stdc++.h>
using namespace std;

struct node {
   int minimum;
   int maximum;
};

struct node minmaxRangeQuery(struct node *st, int ss, int se, int qs, int qe, int index) {
    struct node tmp,left,right;
    if (qs <= ss && qe >= se)
        return st[index];
    if (se < qs || ss > qe) {
        tmp.minimum = INT_MAX;
        tmp.maximum = INT_MIN;
        return tmp;
    }
    int mid = (ss + se)/2;
    left = minmaxRangeQuery(st, ss, mid, qs, qe, 2*index+1);
    right = minmaxRangeQuery(st, mid+1, se, qs, qe, 2*index+2);
    tmp.minimum = min(left.minimum, right.minimum);
    tmp.maximum = max(left.maximum, right.maximum);
    return tmp;
}

struct node minmaxRangeQuery(struct node *st, int n, int qs, int qe) {
    struct node tmp;
    if (qs < 0 || qe > n-1 || qs > qe) {
        tmp.minimum = INT_MIN;
        tmp.minimum = INT_MAX;
        return tmp;
    }
    return minmaxRangeQuery(st, 0, n-1, qs, qe, 0);
}
 
void constructSegmentTree(int arr[], int ss, int se, struct node *st, int si) {
    if (ss == se) {
        st[si].minimum = arr[ss];
        st[si].maximum = arr[ss];
        return;
    }
    int mid = (ss + se)/2;
    constructSegmentTree(arr, ss, mid, st, si*2+1);
    constructSegmentTree(arr, mid+1, se, st, si*2+2);
    st[si].minimum = min(st[si*2+1].minimum, st[si*2+2].minimum);
    st[si].maximum = max(st[si*2+1].maximum, st[si*2+2].maximum);
}

struct node *constructSegmentTree(int arr[], int n) {
    int x = (int)(ceil(log2(n)));
    int max_size = 2*(int)pow(2, x) - 1;
    struct node *st = new struct node[max_size];
    constructSegmentTree(arr, 0, n-1, st, 0);
    return st;
}
 
int main() {
    int arr[] = {1, 8, 5, 9, 6, 14, 2, 4, 3, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
    struct node *st = constructSegmentTree(arr, n);
    int qs = 0;
    int qe = 8;
    struct node result=minmaxRangeQuery(st, n, qs, qe);
    cout<<"Within range [ "<<qs<<" , "<<qe<<" ] min = "<<result.minimum<<" & max = "<<result.maximum<<endl;
    return 0;
}
