//find nth term in padovan sequence
#include<bits/stdc++.h>
using namespace std;

int padovanSequence(int n) {
    int pPrevPrev = 1, pPrev = 1, pCurr = 1, pNext = 1;
    for (int i=3; i<=n; i++) {
        pNext = pPrevPrev + pPrev;
        pPrevPrev = pPrev;
        pPrev = pCurr;
        pCurr = pNext;
    }
    return pNext;
}

int main(){
    int n;
    n = 12;
    cout<<n<<"th no in padovan sequence is "<<padovanSequence(n)<<endl;
    return 0;
}
