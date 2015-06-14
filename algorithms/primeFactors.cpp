//to print all prime factors
#include<iostream>
#include<cmath>
using namespace std;

void primeFactors(int n, bool distinct=false) {
    int prev = 0;
    if (distinct)
        cout<<"Distinct Prime Factors :";
    else
        cout<<"All Prime Factors :";
    while (n%2 == 0) {
        if (distinct) {
            if (prev != 2) {
                cout<<" 2";
                prev = 2;
            }
        } else {
            cout<<" 2";
        }
        n = n/2;
    }
    for (int i=3; i<=sqrt(n); i = i+2) {
        while (n%i == 0) {
            if (distinct) {
                if (prev != i) {
                    cout<<" "<<i;
                    prev = i;
                }        
            } else {
                cout<<" "<<i;
            }
            n = n/i;
        }
    }
    if (n>2  && (!distinct || n!=prev))
        cout<<" "<<n;
    cout<<endl;
}

int main() {
    int n = 50;
    primeFactors(n);
    primeFactors(n, true);
    return 0;
}
