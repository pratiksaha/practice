#include<iostream>
using namespace std;

unsigned int getModulo(unsigned int n, unsigned int d) //get modulus by a power of 2
{
    return ( n & (d-1) );
}

int main(){
    int n = 6;
    int d = 4;
    cout<<n<<"%"<<d<<" = "<<getModulo(n, d)<<endl;
    return 0;
}
