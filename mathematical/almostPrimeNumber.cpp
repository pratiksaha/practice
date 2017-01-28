//to print first n numbers that are k-primes
#include<bits/stdc++.h>
using namespace std;

int countPrimeFactors(int n) {
    int count = 0;
    while (n%2 == 0) {
        n = n/2;
        count++;
    }
    for (int i=3; i<=sqrt(n); i+=2) {
        while (n%i == 0) {
            n = n/i;
            count++;
        }
    }
    if (n > 2)
        count++;
    return count;
}

void almostPrimeNumber(int k, int n) {
    cout<<"First "<<n<<" "<<k<<"-almost prime nos are :";
    for (int i=1, num=2; i<=n; num++) {
        if (countPrimeFactors(num) == k) {
            cout<<" "<<num;
            i++;
        }
    }
    cout<<endl;
}

int main() {
    almostPrimeNumber(2, 10);
    return 0;
}
