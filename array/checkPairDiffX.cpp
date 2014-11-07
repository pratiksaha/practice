//given A[] of N nos and another no S, determines whether or not there exist two elements in A whose diff is exactly S
//Using features of C++ Standard (2011) Compile using g++ -std=c++11
#include<iostream>
#include<algorithm>
#include<unordered_map>
using namespace std;

void checkPairDiffX(int A[], int N, int S) {
    int i, temp[N];
    for(i=0; i<N; i++)
        temp[i] = A[i];
    sort(temp, temp+N);
    
    int l = 0;
    int r = 1;
    while(l<N && r<N) {
        if( l!=r && temp[r] - temp[l] == S) {
            cout<<"Pair with given diff "<<S<<" is ("<<temp[r]<<","<<temp[l]<<")\n";
            l++;
            r--;
         } else if (temp[r] - temp[l] < S) {
            r++;
         } else {
            l++;
         }
    }   
}

void checkPairDiffXHash(int A[], int N, int S) {
    unordered_map<int, int> table;
    int i, temp;
    for(i=0; i<N; i++) {
        temp = S + A[i];
        if(table.find(temp) != table.end())
            cout<<"Pair with given diff "<<S<<" is ("<<A[i]<<","<<temp<<")\n";
        table.insert(make_pair(A[i], 1));
    }
}

int main() {
    int a[] = {100, 8, 30, 40, 1};
    int diff = 60;
    checkPairDiffX(a, sizeof(a)/sizeof(a[0]), diff);
    checkPairDiffXHash(a, sizeof(a)/sizeof(a[0]), diff);
    return 0;
}
