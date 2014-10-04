#include<iostream>
#include<cmath>
using namespace std;

int getFirstSetBitPos(int n)
{
    return log2(n&-n)+1;
}

int turnOffFirstSetBit(int n)
{
  return n&(n-1);
} 

int countSetBits(int n)
{
    int count = 0;
    while(n)
    {
        count += n&1;
        n >>= 1;
    }
    return count;
}

int Log2n(int n)
{
   return (n > 1)? 1 + Log2n(n/2): 0;
}
 
int isPowerOfTwo(int n)
{
    return n && (! (n & (n-1)) );
}
 
int singleSetBitPos(int n)
{
    if (!isPowerOfTwo(n))
        return -1;
    return Log2n(n) + 1;
}

int main(){
    cout<<"First set bit of 12 = "<<getFirstSetBitPos(12)<<endl;
    cout<<"Turning off first set bit of 12 = "<<turnOffFirstSetBit(12)<<endl;
    cout<<"No of set bits in 5 = "<<countSetBits(5)<<endl;
    cout<<"No of set bits in 19 = "<<countSetBits(19)<<endl;
    int pos, num;
    num = 0;
    pos = singleSetBitPos(num);
    (pos == -1)? cout<<"Invalid no "<<num<<endl: cout<<"Only set bit for "<<num<<" = "<< pos<<endl;
    num = 1;
    pos = singleSetBitPos(num);
    (pos == -1)? cout<<"Invalid no "<<num<<endl: cout<<"Only set bit for "<<num<<" = "<< pos<<endl;
    num = 8;
    pos = singleSetBitPos(num);
    (pos == -1)? cout<<"Invalid no "<<num<<endl: cout<<"Only set bit for "<<num<<" = "<< pos<<endl;
    num = 9;
    pos = singleSetBitPos(num);
    (pos == -1)? cout<<"Invalid no "<<num<<endl: cout<<"Only set bit for "<<num<<" = "<< pos<<endl;
    return 0;
}
