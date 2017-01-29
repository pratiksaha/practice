//to check if a number has alternate bit pattern
#include<bits/stdc++.h>
using namespace std;

bool alternatePattern(int n) {
    int prev = n % 2;
    n = n/2;
    while (n > 0) {
        int curr = n % 2;
        if (curr == prev)
            return false;
        prev = curr;
        n = n / 2;
    }
    return true;
}
 
int main() {
    int n = 10;
    cout<<n<<(alternatePattern(n)? " does " : " does not ")<<"have alternate pattern\n";
    n = 15;
    cout<<n<<(alternatePattern(n)? " does " : " does not ")<<"have alternate pattern\n";
    return 0;
}
