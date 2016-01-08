//to find XOR of XOR's of all subsets
#include<bits/stdc++.h>
using namespace std;

int xorOfSubsetXOR(int set[], int n) {
    return (n == 1) ? set[0] : 0;
}

int main() {
    int set[] = {5, 2, 3};
    cout<<"XOR of XOR's of all subsets is "<<xorOfSubsetXOR(set, sizeof(set)/sizeof(set[0]))<<endl;
    return 0;
}
