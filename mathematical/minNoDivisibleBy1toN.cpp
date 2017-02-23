//to find min no divisible by all numbers 1 to n
#include<bits/stdc++.h>
using namespace std;

long long minNoDivisibleBy1toN(long long n) {
    long long ans = 1;    
    for (long long i = 1; i <= n; i++)
        ans = (ans * i)/(__gcd(ans, i));
    return ans;
}
 
int main()  {
    long long n = 20;
    cout<<"min no divisible by all numbers 1 to "<<n<<" is "<<minNoDivisibleBy1toN(n)<<endl;
    return 0;
}
