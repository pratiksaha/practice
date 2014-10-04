#include<iostream>
#include<climits>
#include<cstdlib>
using namespace std;

void swapArithmetic(int *x, int *y){
    if( x != y){
        *x = *x + *y;
        *y = *x - *y;
        *x = *x - *y;
    }
}

void swapBitwise(int *x, int *y){
    if( x != y){
        *x = *x ^ *y;
        *y = *x ^ *y;
        *x = *x ^ *y;
    }
}

int add(int x, int y) //Mimics the half adder logic
{
    while (y != 0)
    {
        int carry = x & y; 
        x = x ^ y;
        y = carry << 1;
    }
    return x;
}

int min(int x, int y)
{
    return y ^ ((x ^ y) & -(x < y));
}

int max(int x, int y)
{
    return x ^ ((x ^ y) & -(x < y));
}

int oppositeSigns(int x, int y)
{
    //x *= -1;
    return ((x ^ y) < 0);
}

int smallest(int x, int y, int z)
{
  int c = 0;
  while ( x && y && z )
  {
      x--;  y--; z--; c++;
  }
  return c;
}

int addOvf(int* result, int a, int b)
{
    *result = a + b;
    if( a > INT_MAX - b)
        return 1;
    else
    {
        return 0;
    }
}

int main(){
    int a, b, c;
    a = 7;
    b = 7;
    cout<<"Before swapping a="<<a<<" b="<<b<<endl;
    swapArithmetic(&a, &b);
    cout<<"After swapping a="<<a<<" b="<<b<<endl;
    a = 10;
    b = 5;
    cout<<"Before swapping a="<<a<<" b="<<b<<endl;
    swapArithmetic(&a, &b);
    cout<<"After swapping a="<<a<<" b="<<b<<endl;
    a = 28;
    b = 28;
    cout<<"Before swapping a="<<a<<" b="<<b<<endl;
    swapBitwise(&a, &b);
    cout<<"After swapping a="<<a<<" b="<<b<<endl; 
    a = 23;
    b = 32;
    cout<<"Before swapping a="<<a<<" b="<<b<<endl;
    swapBitwise(&a, &b);
    cout<<"After swapping a="<<a<<" b="<<b<<endl;
    a = 79;
    b = 42;
    cout<<"Sum of "<<a<<" & "<<b<<" is "<<add(a,b)<<endl;
    cout<<"Min of "<<a<<" & "<<b<<" is "<<min(a,b)<<endl;
    cout<<"Max of "<<a<<" & "<<b<<" is "<<max(a,b)<<endl;
    cout<<a<<" & "<<b<<" have "<<(oppositeSigns(a, b)?"opposite signs":"same sign")<<endl;
    c = 65;
    cout<<"Smallest of "<<a<<","<<b<<"&"<<c<<" is "<<smallest(a,b,c)<<endl;
    a = 2147483640;
    b = 10;
    cout<<"Sum of "<<a<<" & "<<b<<(addOvf(&c, a, b)?" (Overflow) ":" (No Overflow) ")<<" = "<<c<<endl;
    return 0;
}
