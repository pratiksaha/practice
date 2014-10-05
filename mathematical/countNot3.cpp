#include<iostream>
using namespace std;

int count(int n)
{
    // Base cases (Assuming n is not negative)
    if (n < 3)
        return n;
    if (n >= 3 && n < 10)
       return n-1; 
    // Calculate 10^(d-1) (10 raise to the power d-1) where d isnumber of digits in n
    int po = 1;
    while (n/po > 9)
        po = po*10;
    // find the most significant digit
    int msd = n/po; 
    if (msd != 3)
      return count(msd)*count(po - 1) + count(msd) + count(n%po);
    else
      return count(msd*po - 1);
}

int main()
{
    cout<<"no of digits not conatinning 3 upto 578 is "<<count(578)<<endl;
    return 0;
}
