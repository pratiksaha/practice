//to count numbers with difference between odd and even digit sums as 1
#include<iostream>
#include<cstring>
using namespace std;

unsigned long long int lookup[50][1000][1000][2];

unsigned long long int  countDigitDiffOne(int digits, int esum, int osum, bool isOdd, int n) {
    if (digits == n)
        return (esum - osum == 1);
    if (lookup[digits][esum][osum][isOdd] != -1)
        return lookup[digits][esum][osum][isOdd];
    unsigned long long int ans = 0;
    if (isOdd)
        for (int i=0; i<=9; i++)
            ans += countDigitDiffOne(digits+1, esum, osum+i, false, n);
    else
      for (int i = 0; i <= 9; i++)
          ans += countDigitDiffOne(digits+1, esum+i, osum, true, n);
    return lookup[digits][esum][osum][isOdd] = ans;
}

unsigned long long int countDigitDiffOne(int n) {
    int digits = 0;
    memset(lookup, -1, sizeof(lookup));
    unsigned long long int ans = 0;
    int esum = 0, osum = 0;
    for (int i = 1; i <= 9; i++)
          ans += countDigitDiffOne(digits+1, esum + i, osum, true, n);
    return ans;
}

int main() {
    int n = 3;
    cout<<"Count of "<<n<<" digit numbers with difference between odd and even digit sums as 1 is "<<countDigitDiffOne(n)<<endl;
    return 0;
}
