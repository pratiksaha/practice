#include<iostream>
using namespace std;

bool isKthBitSet(unsigned int x, unsigned int k)
{
    return (x & (1 << (k-1)))? true: false;
}
 
bool isPalindrome(unsigned int x)
{
    int l = 1; // Initialize left position
    int r = sizeof(unsigned int)*8; // initialize right position
 
    // One by one compare bits
    while (l < r)
    {
        if (isKthBitSet(x, l) != isKthBitSet(x, r))
            return false;
        l++;
        r--;
    }
    return true;
}
 
int main()
{
    unsigned int x = 1<<16 + 1<<15;
    cout<<x<<" is "<<(isPalindrome(x)?"Palindrome":"Not Palindrome")<<endl;
    x = 1<<20 + 1;
    cout<<x<<" is "<<(isPalindrome(x)?"Palindrome":"Not Palindrome")<<endl;
    return 0;
}
