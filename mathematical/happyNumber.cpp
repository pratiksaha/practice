//check if a no is happy
#include<bits/stdc++.h>
using namespace std;

int numSquareSum(int n) {
    int squareSum = 0;
    while (n) {
        squareSum += (n % 10) * (n % 10);
        n /= 10;
    }
    return squareSum;
}

bool happyNumber(int n) {
    int slow, fast;
    slow = fast = n;
    do {
        slow = numSquareSum(slow);
        fast = numSquareSum(numSquareSum(fast));
    } while (slow != fast);
    return (slow == 1);
}

int main() {
    int n;
    n = 13;
    cout<<n<<" is"<<(happyNumber(n)? " " : " not ")<<"a happy no\n";
    n = 29;
    cout<<n<<" is"<<(happyNumber(n)? " " : " not ")<<"a happy no\n";
    return 0;
}
