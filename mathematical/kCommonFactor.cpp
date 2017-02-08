//kth common factor
#include<bits/stdc++.h>
using namespace std;
 
int kCommonFactor(int x, int y, int k) {
    int small = min(x, y);
    int count = 1;
    for (int i=2; i<=small; i++) {
        if (x % i==0 && y % i == 0)
            count++;
        if (count == k)
            return i;
   }
   return -1;
}
 
int main() {
   int x = 4, y = 24, k = 3;
   cout<<k<<"th common factor of "<<x<<" & "<<y<<" is "<<kCommonFactor(x, y, k)<<endl;
   return 0;
}
