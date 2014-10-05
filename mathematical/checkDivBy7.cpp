// A Program to check whether a number is divisible by 7
#include<iostream>
using namespace std;
 
int isDivisibleBy7( int num )
{
    // If number is negative, make it positive
    if( num < 0 )
        return isDivisibleBy7( -num ); 
    // Base cases
    if( num == 0 || num == 7 )
        return 1;
    if( num < 10 )
        return 0; 
    return isDivisibleBy7( (num/10) - 2*(num-(num/10)*10) );
}

int main()
{
    int num = 616;
    cout<<num<<(isDivisibleBy7(num)?" is divisible by 7":" is not divisible by 7")<<endl;
    num = 615;
    cout<<num<<(isDivisibleBy7(num)?" is divisible by 7":" is not divisible by 7")<<endl;
    return 0;
}
