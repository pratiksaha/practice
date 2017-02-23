//to find sum of divisors of all the divisors of a number
//Using features of C++ Standard (2011) Compile using g++ -std=c++11
#include<bits/stdc++.h>
using namespace std;
 
int sumOfDivisorsOfDivisors(int n) {
    unordered_map<int, int> mp;
    for (int j=2; j<=sqrt(n); j++) {
        int count = 0;
        while (n%j == 0) {
            n /= j;
            count++;
        }
        if (count)
            mp[j] = count;
    }
    if (n != 1)
        mp[n] = 1;
    int ans = 1;
    for (unordered_map<int, int>::iterator it = mp.begin(); it != mp.end(); it++) {
        int pw = 1;
        int sum = 0;
        for (int i=it->second+1; i>=1; i--) {
            sum += (i*pw);
            pw *= it->first;
        }
        ans *= sum;
    }
    return ans;
}
 
int main() {
    int n = 10;
    cout<<"sum of divisors of all the divisors of "<<n<<" is "<<sumOfDivisorsOfDivisors(n)<<endl;
    return 0;
}
