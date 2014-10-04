#include<iostream>
using namespace std;

void binary(unsigned n)
{
    if (n > 1)
        binary(n/2);
    cout<<n%2;
}
 
int main(void)
{
    cout<<"Binary of 9 is ";
    binary(9);
    cout<<endl;
    cout<<"Binary of 4 is ";
    binary(4);
    cout<<endl;
    return 0;
}
