//to copy set bits in a given range [l, r] from y to x
#include<bits/stdc++.h>
using namespace std;

void copySetBits(unsigned &x, unsigned y, unsigned l, unsigned r) {
    if (l < 1 || r > 32)
        return ;
    for (int i=l; i<=r; i++) {
        int mask = 1 << (i-1);
        if (y & mask)
            x = x | mask;
    }
}
 
int main() {
   unsigned x = 10, y = 13, l = 2, r = 3;
   cout<<"x = "<<x<<" y = "<<y<<" l = "<<l<<" r = "<<r<<endl;
   copySetBits(x, y, l, r);
   cout<<"Modified x is "<<x<<endl;
   return 0; 
}
