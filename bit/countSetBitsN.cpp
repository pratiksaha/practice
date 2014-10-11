//count set bits in all numbers from 1 to n
#include<iostream>
using namespace std;

unsigned int countSetBits(unsigned int );
 
//Returns position of leftmost set bit. The rightmost position is considered as 0
unsigned int getLeftmostBit (int n)
{
    int m = 0;
    while (n>1)
    {
        n = n>>1;
        m++;
    }
    return m;
}
 
//Given the position of previous leftmost set bit in n (or an upper bound on leftmost position) returns the new position of leftmost set bit in n
unsigned int getNextLeftmostBit (int n, int m)
{
    unsigned int temp = 1<<m;
    while (n<temp)
    {
        temp = temp>>1;
        m--;
    }
    return m;
}
 
// The main recursive function used by countSetBits()
unsigned int _countSetBits(unsigned int n, int m)
{
    // Base Case: if n is 0, then set bit count is 0
    if (n == 0)
        return 0;
 
    /* get position of next leftmost set bit */
    m = getNextLeftmostBit(n, m);
 
    // If n is of the form 2^x-1, i.e., if n is like 1, 3, 7, 15, 31,.. etc, then we are done. 
    if (n == ((unsigned int)1<<(m+1))-1) //(m+1) since positions are considered starting from 0, 1 is added to m
        return (unsigned int)(m+1)*(1<<m);
 
    // update n for next recursive call
    n = n - (1<<m);
    return (n+1) + countSetBits(n) + m*(1<<(m-1));
}
 
// Returns count of set bits present in all numbers from 1 to n
unsigned int countSetBits(unsigned int n)
{
   // Get the position of leftmost set bit in n. This will be used as an upper bound for next set bit function
   int m = getLeftmostBit(n);
 
   // Use the position
   return _countSetBits(n, m);
}

int main()
{
   int n = 17;
   cout<<"Total set bit count is "<<countSetBits(n)<<endl;
   return 0;
}
