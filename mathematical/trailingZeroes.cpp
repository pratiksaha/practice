//Count trailing 0s in n!
#include<iostream>
using namespace std;
 
int countTrailingZeros(int  n)
{
    //Count of trailing zeroes in n! = floor(n/5) + floor(n/25) + floor(n/125) + ...
    int count = 0;
    for (int i=5; n/i>=1; i *= 5)
        count += n/i; 
    return count;
}

int main()
{
    int n = 100;
    cout<<"Count of trailing 0s in " <<n<< "! is "<<countTrailingZeros(n)<<endl;
    return 0;
}
