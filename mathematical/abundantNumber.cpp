//to check if a no is abundant
#include<bits/stdc++.h>
using namespace std;

int getSum(int n) {
    int sum = 0;
    for (int i=1; i<=sqrt(n); i++) {
        if (n%i==0) {
            if (n/i == i) {
                sum = sum + i;
            } else {
                sum = sum + i;
                sum = sum + (n / i);
            }
        }
    }
    sum = sum - n;
    return sum;
}

bool abundantNumber(int n) {
    return (getSum(n) > n);
}

int main() {
    int n;
    n = 12;
    cout<<n<<" is"<<(abundantNumber(n)? " " : " not ")<<"an abundant no\n";
    n = 15;
    cout<<n<<" is"<<(abundantNumber(n)? " " : " not ")<<"an abundant no\n";
    return 0;
}
