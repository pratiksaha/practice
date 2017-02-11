//to check if n is perfect square
#include<bits/stdc++.h>
using namespace std;

bool isPerfectSquare(int n) {
    for (int sum=0,i=1; sum<n; i+=2) {
        sum += i;
        if (sum == n)
            return true;
    }
    return false;
}

int main() {
    int n = 35;
    cout<<n<<" is"<<(isPerfectSquare(n)? " " : " not ")<<"a perfect square\n";
    n = 49;
    cout<<n<<" is"<<(isPerfectSquare(n)? " " : " not ")<<"a perfect square\n";
    return 0;
}
