//given A[] of N nos and another no S, determines whether or not there exist two elements in A whose sum is exactly S
//Using features of C++ Standard (2001) Compile using g++ -std=c++11
#include<iostream>
#include<unordered_map>
using namespace std;

int compare (const void * a, const void * b) {
    return ( *(int*)a - *(int*)b );
}

void checkPairSumX(int A[], int N, int S) {
    int i, temp[N];
    for(i=0; i<N; i++)
        temp[i] = A[i];
    qsort(temp, N, sizeof(int), compare);
    int l = 0;
    int r = N-1;
    while(l < r) {
        if(temp[l] + temp[r] == S) {
            cout<<"Pair with given sum "<<S<<" is ("<<temp[l]<<","<<temp[r]<<")\n";
            l++;
            r--;
         } else if (temp[l] + temp[r] < S) {
            l++;
         } else {
            r--;
         }
    }   
}

void checkPairSumXHash(int A[], int N, int S) {
    unordered_map<int, int> table;
    int i, temp;
    for(i=0; i<N; i++) {
        temp = S - A[i];
        if(temp>=0 && table.find(temp) != table.end())
            cout<<"Pair with given sum "<<S<<" is ("<<A[i]<<","<<temp<<")\n";
        table.insert(make_pair(A[i], 1));
    }
}

int main() {
    int a[] = {1, 4, 45, 6, 10, 8};
    int sum = 16;
    checkPairSumX(a, sizeof(a)/sizeof(a[0]), sum);
    checkPairSumXHash(a, sizeof(a)/sizeof(a[0]), sum);
    return 0;
}
