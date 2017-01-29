//Bleak Number
#include <bits/stdc++.h>
using namespace std;
 
int countSetBits(int x) {
    unsigned int count = 0;
    while (x) {
        x &= (x-1);
        count++;
    }
    return count;
}
 
int ceilLog2(int x) {
    int count = 0;
    x--;
    while (x > 0) {
        x = x>>1;
        count++;
    }
    return count;
}
 
bool bleakNumber(int n) {
    for (int x=n-ceilLog2(n); x<n; x++)
        if (x + countSetBits(x) == n)
            return false;
   return true;
}
 
int main() {
    int n = 3;
    cout<<n<<" is"<<(bleakNumber(n)? " " : " not ")<<"a bleak no\n";
    n = 4;
    cout<<n<<" is"<<(bleakNumber(n)? " " : " not ")<<"a bleak no\n";
    return 0;
}
