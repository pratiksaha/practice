#include<iostream>
using namespace std;

unsigned int nextPowerOf2(unsigned int n)
{
    unsigned int p = 1;
    if (n && !(n & (n - 1)))
        return n;
 
    while (p < n) {
        p <<= 1;
    }
    return p;
}
 
int main()
{
    unsigned int n = 5;
    cout<<"Next power of 2 after "<<n<<" is "<<nextPowerOf2(n)<<endl;
    return 0;
}
