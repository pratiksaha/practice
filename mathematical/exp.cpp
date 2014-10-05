//calculate e raise to the power x
#include<iostream>
using namespace std;
#define precision 100
 
double exponential(float x)
{
    double sum = 1.0; // initialize sum of series
    for(int i=precision-1; i>0; i-- )
        sum = 1 + x*sum/i; 
    return sum;
}

int main()
{
    float x = 1.0f;
    cout<<"e^"<<x<<" = "<<exponential(x)<<endl;
    return 0;
}
