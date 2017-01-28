//to print palindromic primes
#include<bits/stdc++.h>
using namespace std;

int oneDigit(int num) {
    return (num >= 0 && num < 10);
}
 
bool isPalindrome(int num, int* dupNum) {
    if (oneDigit(num))
        return (num == (*dupNum) % 10);
    if (!isPalindrome(num/10, dupNum))
        return false;
    *dupNum /= 10;
    return (num % 10 == (*dupNum) % 10);
}
 
int isPalindrome(int num) {
    if (num < 0)
       num = -num;
    int *dupNum = new int(num);
    return isPalindrome(num, dupNum);
}
 
void palindromicPrime(int n) {
    bool prime[n+1];
    memset(prime, true, sizeof(prime));
    cout<<"Palindromic Primes upto "<<n<<" :";
    for (int p=2; p*p<=n; p++)
        if (prime[p] == true)
            for (int i=p*2; i<=n; i += p)
                prime[i] = false;
    for (int p=2; p<=n; p++)
       if (prime[p] && isPalindrome(p))
          cout<<" "<<p;
    cout<<endl;
}
 
int main() {
    palindromicPrime(200);
    return 0;
}
