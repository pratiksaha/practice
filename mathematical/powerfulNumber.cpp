//check if a number is powerful
#include<bits/stdc++.h>
using namespace std;

bool powerfulNumber(int n) {
    while (n%2 == 0) { //first divide the number repeatedly by 2
        int power = 0;
        while (n % 2 == 0) {
            n /= 2;
            power++;
        }
        if (power == 1) //only 2^1 divides n (not higher powers)
            return false;
    }
    for (int factor=3;  factor<=sqrt(n); factor += 2) {
        int power = 0;
        while (n % factor == 0) { //find highest power of factor that divides n
            n = n/factor;
            power++;
        }
        if (power == 1) //only factor^1 divides n (not higher powers)
            return false;
    }
    return (n == 1); //n must be 1 now if it is not a prime and prime numbers are not powerful
}

int main() {
    int n;
    n = 20;
    cout<<n<<" is"<<(powerfulNumber(n)? " " : " not ")<<"a powerful no\n";
    n = 27;
    cout<<n<<" is"<<(powerfulNumber(n)? " " : " not ")<<"a powerful no\n";
    return 0;
}

