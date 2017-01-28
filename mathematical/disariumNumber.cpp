//check if a no is disarium
#include<bits/stdc++.h>
using namespace std;

int countDigits(int n) {
    int count_digits = 0;
    int x = n;
    while (x) {
        x = x/10;
        count_digits++;
    }
    return count_digits;
}

bool disariumNumber(int n) {
    int count_digits = countDigits(n);
    int sum = 0;
    int x = n;
    while (x) {
        int r = x%10;
        sum = sum + pow(r, count_digits--);
        x = x/10;
    }
    return (sum == n);
}

int main() {
    int n;
    n = 135;
    cout<<n<<" is"<<(disariumNumber(n)? " " : " not ")<<"a disarium no\n";
    n = 29;
    cout<<n<<" is"<<(disariumNumber(n)? " " : " not ")<<"a disarium no\n";
    return 0;
}
