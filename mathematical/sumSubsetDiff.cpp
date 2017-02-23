//to find sum of difference between last and first element of each subset
#include<bits/stdc++.h>
using namespace std;

int SumFirst(int S[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += S[i] * pow(2, n-i-1);
    return sum;
}

int SumLast(int S[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += S[i] * pow(2, i);
    return sum;
}

int sumSubsetDiff(int S[], int n) {
    return SumLast(S, n) - SumFirst(S, n);
}
 
int main() {
    int n = 4;
    int S[] = {5, 2, 9, 6};
    cout<<sumSubsetDiff(S, n)<<endl;
    return 0;
}
