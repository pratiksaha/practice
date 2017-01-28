//check if a no is deficient
#include<bits/stdc++.h>
using namespace std;

int divisorsSum(int n) {
    int sum = 0;
    for (int i=1; i<=sqrt(n); i++) {
        if (n%i==0) {
            if (n/i == i){
                sum = sum + i;
            } else {
                sum = sum + i;
                sum = sum + (n / i);
            }
        }
    }
    return sum;
}

bool deficientNumber(int n) {
    return (divisorsSum(n) < (2 * n));
}

int main() {
    int n;
    n = 12;
    cout<<n<<" is"<<(deficientNumber(n)? " " : " not ")<<"a deficient no\n";
    n = 15;
    cout<<n<<" is"<<(deficientNumber(n)? " " : " not ")<<"a deficient no\n";
    return 0;
}
