#include<iostream>
using namespace std;
#define CHAR_BIT 8

unsigned int getAbs(int n)
{
    int const mask = n >> (sizeof(int) * CHAR_BIT - 1);
    return ((n ^ mask) - mask);
}

int main(){
    int x;
    x = 7;
    cout<<"Abs of "<<x<<" = "<<getAbs(x)<<endl;
    x = -7;
    cout<<"Abs of "<<x<<" = "<<getAbs(x)<<endl;
    return 0;
}
