//to print circular primes
#include <bits/stdc++.h>
using namespace std;

void SieveOfSundaram(bool marked[], int nNew) {
    for (int i=1; i<=nNew; i++)
        for (int j=i; (i + j + 2*i*j) <= nNew; j++)
            marked[i + j + 2*i*j] = true;
}

int countDigits(int n)
{
    int digit = 0;
    while (n /= 10)
        digit++;
    return digit;
}

int rotate(int n) {
    int rem = n % 10;
    rem *= pow(10, countDigits(n));
    n /= 10;
    n += rem;
    return n;
}

void circularPrimeNumber(int n) {
    cout<<"Circular Prime Nos upto "<<n<<" are :";
    int nNew = (n-2)/2;
    bool marked[nNew + 1];
    memset(marked, false, sizeof(marked));
    SieveOfSundaram(marked, nNew);
    cout<<" 2 " ;
    for (int i=1; i<=nNew; i++) {
        if (marked[i])
            continue;
        int num = 2 * i + 1;
        num = rotate(num);
        while (num != 2*i + 1) {
            if (num % 2 == 0)
                break;
            if (marked[(num - 1)/2] == false)
                num = rotate(num);
            else
                break;
        }
        if (num == (2*i + 1))
            cout<<" "<<num;
    }
    cout<<endl;
}

int main(void) {
    circularPrimeNumber(100);
    return 0;
}
