//to print Equidigital Nos till n
#include<bits/stdc++.h>
using namespace std;
#define MAX 10000

vector <int> primes;

void sieveSundaram() {
    bool marked[MAX/2 + 100] = {0};
    for (int i=1; i<=(sqrt(MAX)-1)/2; i++)
        for (int j=(i*(i+1))<<1; j<=MAX/2; j=j+2*i+1)
            marked[j] = true;
    primes.push_back(2);
    for (int i=1; i<=MAX/2; i++)
        if (marked[i] == false)
            primes.push_back(2*i + 1);
}

bool equidigitalNumber(int n) {
    if (n == 1)
        return true;
    int original_no = n;
    int sumDigits = 0;
    while (original_no > 0) {
        sumDigits++;
        original_no = original_no/10;
    }
    int pDigit = 0 , count_exp = 0, p;
    for (int i = 0; primes[i] <= n/2; i++) {
        while (n % primes[i] == 0) {
            p = primes[i];
            n = n/p;
            count_exp++;
        }
        while (p > 0) {
            pDigit++;
            p = p / 10;
        }
        while (count_exp > 1) {
            pDigit++;
            count_exp = count_exp / 10;
        }
    }
    if (n != 1) {
        while (n > 0) {
            pDigit++;
            n = n/10;
        }
    }
    return (pDigit == sumDigits);
}
 
int main(){
    sieveSundaram();
    cout<<"Printing Equidigital Numbers upto 50 :";
    for (int i=1; i<500; i++)
        if (equidigitalNumber(i))
            cout<<" "<<i;
    cout<<endl;
    return 0;
}
