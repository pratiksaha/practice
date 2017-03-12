//to find the length of longest common extension
#include<bits/stdc++.h>
using namespace std;

struct query {
    int L, R;
};

struct suffix {
    int index;
    int rank[2];
};

int cmp(struct suffix a, struct suffix b) {
    return (a.rank[0] == b.rank[0])? (a.rank[1] < b.rank[1]) : (a.rank[0] < b.rank[0]);
}

int constructSegmentTree(int arr[], int ss, int se, int *st, int si) {
    if (ss == se) {
        st[si] = arr[ss];
        return arr[ss];
    }
    int mid =(ss + se)/2;
    st[si] =  min(constructSegmentTree(arr, ss, mid, st, si*2+1), constructSegmentTree(arr, mid+1, se, st, si*2+2));
    return st[si];
}

int *constructSegmentTree(int arr[], int n) {
    int x = (int)(ceil(log2(n)));
    int max_size = 2*(int)pow(2, x) - 1;
    int *st = new int[max_size];
    constructSegmentTree(arr, 0, n-1, st, 0);
    return st;
}

int RMQ(int *st, int ss, int se, int qs, int qe, int index) {
    if (qs <= ss && qe >= se)
        return st[index];
    if (se < qs || ss > qe)
        return INT_MAX;
    int mid = (ss +se)/2;
    return min(RMQ(st, ss, mid, qs, qe, 2*index+1), RMQ(st, mid+1, se, qs, qe, 2*index+2));
}

int RMQ(int *st, int n, int qs, int qe) {
    if (qs < 0 || qe > n-1 || qs > qe)
        return -1; 
    return RMQ(st, 0, n-1, qs, qe, 0);
}

vector<int> buildSuffixArray(string txt, int n) {
    struct suffix suffixes[n];
    for (int i = 0; i < n; i++) {
        suffixes[i].index = i;
        suffixes[i].rank[0] = txt[i] - 'a';
        suffixes[i].rank[1] = ((i+1) < n) ? (txt[i + 1] - 'a') : -1;
    }
    sort(suffixes, suffixes+n, cmp);
    int ind[n];
    for (int k = 4; k < 2*n; k = k*2) {
        int rank = 0;
        int prev_rank = suffixes[0].rank[0];
        suffixes[0].rank[0] = rank;
        ind[suffixes[0].index] = 0;
        for (int i = 1; i < n; i++) {
            if (suffixes[i].rank[0] == prev_rank && suffixes[i].rank[1] == suffixes[i-1].rank[1]) {
                prev_rank = suffixes[i].rank[0];
                suffixes[i].rank[0] = rank;
            } else {
                prev_rank = suffixes[i].rank[0];
                suffixes[i].rank[0] = ++rank;
            }
            ind[suffixes[i].index] = i;
        }
        for (int i = 0; i < n; i++) {
            int nextindex = suffixes[i].index + k/2;
            suffixes[i].rank[1] = (nextindex < n) ? suffixes[ind[nextindex]].rank[0] : -1;
        }
        sort(suffixes, suffixes+n, cmp);
    }
    vector<int>suffixArr;
    for (int i = 0; i < n; i++)
        suffixArr.push_back(suffixes[i].index);
    return  suffixArr;
}

vector<int> kasai(string txt, vector<int> suffixArr, vector<int> &invSuff) {
    int n = suffixArr.size();
    vector<int> lcp(n, 0);
    for (int i=0; i < n; i++)
        invSuff[suffixArr[i]] = i;
    int k = 0;
    for (int i=0; i<n; i++) {
        if (invSuff[i] == n-1) {
            k = 0;
            continue;
        }
        int j = suffixArr[invSuff[i]+1];
        while (i+k<n && j+k<n && txt[i+k]==txt[j+k])
            k++;
        lcp[invSuff[i]] = k;
        if (k>0)
            k--;
    }
    return lcp;
}

int longestCommonExtensionNaive(string str, int n, int L, int R) {
    int length = 0;
    while (str[L+length] == str[R+length] && R+length < n)
        length++;
    return(length);
}

int longestCommonExtensionRangeMinimimQuery(vector<int> lcp, vector<int>invSuff, int n, int L, int R) {
    if (L == R)
        return (n-L);
    int low = min(invSuff[L], invSuff[R]);
    int high = max(invSuff[L], invSuff[R]);
    int length = lcp[low];
    for (int i=low+1; i<high; i++)
        if (lcp[i] < length)
            length = lcp[i];
    return length;
}

int longestCommonExtensionSegmentTree(int *st, vector<int>lcp, vector<int>invSuff, int n, int L, int R) {
    if (L == R)
        return (n-L);
    else
        return RMQ(st, n, invSuff[R], invSuff[L]-1);
}

void longestCommonExtension(string str, int n, query q[], int m) {
    vector<int> suffixArr = buildSuffixArray(str, str.length());
    vector<int> invSuff(n, 0);
    vector<int> lcp = kasai(str, suffixArr, invSuff);
    int lcpArr[n];
    for (int i=0; i<n; i++)
        lcpArr[i] = lcp[i];
    int *st = constructSegmentTree(lcpArr, n);
    for (int i=0; i<m; i++) {
        int L = q[i].L;
        int R = q[i].R;
        cout<<"longestCommonExtensionNaive("<<L<<","<<R<<") = "<<longestCommonExtensionNaive(str, n, L, R)<<endl;
        cout<<"longestCommonExtensionRangeMinimimQuery("<<L<<","<<R<<") = "<<longestCommonExtensionRangeMinimimQuery(lcp, invSuff, n, L, R)<<endl;
        cout<<"longestCommonExtensionSegmentTree("<<L<<","<<R<<") = "<<longestCommonExtensionSegmentTree(st, lcp, invSuff, n, L, R)<<endl;
    }
}

int main() {
    string str = "abbababba";
    int n = str.length();
    struct query q[] = {{1, 2}, {1, 6}, {0, 5}};
    int m = sizeof(q)/sizeof(q[0]);
    longestCommonExtension(str, n, q, m);
    return (0);
}
