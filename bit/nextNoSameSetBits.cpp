#include<iostream>
using namespace std;
 
unsigned int nextHigherNo(unsigned int x)
{
    unsigned int rightOne, nextHigherOneBit, rightOnesPattern, next;
    next = 0;
    if(x) {
        // right most set bit
        rightOne = x & -(signed)x;
        // reset the pattern and set next higher bit
        // left part of x will be here
        nextHigherOneBit = x + rightOne; 
        // isolate the pattern
        rightOnesPattern = x ^ nextHigherOneBit;
        // right adjust pattern
        rightOnesPattern = (rightOnesPattern)/rightOne;
        // correction factor
        rightOnesPattern >>= 2; 
        // rightOnesPattern is now part [A] of the above explanation.
        // integrate new pattern (Add [D] and [A])
        next = nextHigherOneBit | rightOnesPattern;
    }
    return next;
}
 
int main()
{
    int x = 156;
    cout<<"Next higher number with same number of set bits as "<<x<<" is "<<nextHigherNo(x)<<endl;
    return 0;
}
