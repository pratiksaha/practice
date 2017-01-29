//to find bitwise and of all numbers from x to y
#include<bits/stdc++.h>
using namespace std;

int msbPos(long long int  n) {
    int msb_p = -1;
    while (n) {
        n = n>>1;
        msb_p++;
    }
    return msb_p;
}
 
long long int  bitwiseAndXandY(long long int x, long long int y) {
    long long int res = 0;
    while (x && y) {
        int msb_p1 = msbPos(x);
        int msb_p2 = msbPos(y);
        if (msb_p1 != msb_p2)
            break;
        long long int msb_val =  (1 << msb_p1);
        res += msb_val;
        x -= msb_val;
        y -= msb_val;
    }
 
    return res;
}
 
int main() {
    long long int  x = 10, y = 15;
    cout<<"Bitwise AND of all nos b/w "<<x<<" and "<<y<<" is "<<bitwiseAndXandY(x, y)<<endl;
    return 0;
}
