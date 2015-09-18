//to count numbers with sum of n digits as sum
#include<iostream>
#include<cstring>
using namespace std;

unsigned long long int lookup[101][50001];

unsigned long long int count(int n, int sum) {
    if (n == 0)
       return sum == 0;
    if (lookup[n][sum] != -1)
       return lookup[n][sum];
    unsigned long long int ans = 0;
    for (int i=0; i<10; i++)
        if (sum-i >= 0)
            ans += count(n-1, sum-i);
    return lookup[n][sum] = ans;
}

unsigned long long int countDigitSum(int n, int sum) {
    memset(lookup, -1, sizeof(lookup));
    unsigned long long int ans = 0;
    for (int i = 1; i <= 9; i++)
      if (sum-i >= 0)
         ans += count(n-1, sum-i);
    return ans;
}

int main() {
    int n = 3, sum = 5;
    cout<<"Count of "<<n<<" digit numbers with sum of digits as "<<sum<<" is "<<countDigitSum(n, sum)<<endl;
    return 0;
}
