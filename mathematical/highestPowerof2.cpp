//to find highest power of 2 smaller than or equal to n
#include<bits/stdc++.h>
using namespace std;
 
unsigned int highestPowerof2(unsigned int n) {
    if (n < 1)
        return 0;
    unsigned int res = 1;
    for (int i=0; i<8*sizeof(unsigned int); i++) {
        unsigned int curr = 1 << i;
        if (curr > n)
            break;
        res = curr;
    }
    return res;
}
 
int main() {
    int n = 10;
    cout<<"Highest power of 2 smaller than or equal to "<<n<<" is "<<highestPowerof2(n)<<endl;
    return 0;
}
