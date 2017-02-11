//to find maximum number of 0's between immediate 1's in binary representation of a number
#include<bits/stdc++.h>
using namespace std;

int maxZerosBetweenImmediateOnes(int n) {
    if (n==0 || (n&(n-1)) == 0)
        return -1;
    int setBit = 1, prev = 0, i;
    for (i=1; i<=sizeof(int)*8; i++) {
         prev++;
         if ((n & setBit) == setBit) {
              setBit = setBit << 1;
              break;
         }
         setBit = setBit << 1;
    }
    int max0 = INT_MIN, cur = prev;
    for (int j=i+1; j<=sizeof(int)*8; j++) {
        cur++;
        if ((n & setBit) == setBit) {
            if (max0 < (cur - prev - 1))
                max0 = cur - prev - 1;
            prev = cur;
        }
        setBit = setBit << 1;
    }
    return max0;
}

int main() {
   int n = 549;
   cout<<"maximum number of 0's between immediate 1's in binary representation of "<<n<<" is "<<maxZerosBetweenImmediateOnes(n)<<endl;
   return 0;
}
