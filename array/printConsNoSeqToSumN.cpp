//to print sequences of all consecutive numbers with sum equal to N
#include<bits/stdc++.h>
using namespace std;

void printConsNoSeqToSumN(int N) {
    int start = 1, end = 1;
    int sum = 1;
    while (start <= N/2) {
        if (sum < N) {
            end += 1;
            sum += end;
        } else if (sum > N) {
            sum -= start;
            start += 1;
        } else if (sum == N) {
            for (int i = start; i <= end; ++i)
                cout<<" "<<i;
            cout<<endl;
            sum -= start;
            start += 1;
        }
    }
}

int main() {
    printConsNoSeqToSumN(125);
    return 0;
}
