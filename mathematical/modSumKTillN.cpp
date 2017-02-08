//to find sum of modulo K of first N natural nos
#include<bits/stdc++.h>
using namespace std;

int modSumKTillN(int N, int K) {
    int ans = 0;
    int y = N / K;   
    int x = N % K;
    ans = (K * (K - 1)/2) * y + (x * (x + 1))/2;
    return ans;
}
 
int main() {
  int N = 10, K = 2;
  cout<<"Sum modulo "<<K<<" till N is "<<modSumKTillN(N, K)<<endl;
  return 0;
} 
