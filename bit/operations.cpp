#include<iostream>
using namespace std;

int multiplyBy3Point5(int x)
{
    /*Multiply by 8 and decrease by the number and then divide by 2*/
    return ((x<<3)-x)>>1;
}

int multiplyBySeven(unsigned int n)
{ 
    /*Multiply by 8 and decrease by the number*/
    return ((n<<3)-n);
}

int addOne(int x)
{
    int m = 1;
 
    /* Flip all the set bits until we find a 0 */
    while( x & m )
    {
        x = x^m;
        m <<= 1;
    }
 
    /* flip the rightmost 0 bit */
    x = x^m;
    return x;
}

int main(){
    cout<<"Add one to 0 = "<<addOne(0)<<endl;
    cout<<"Add one to 5 = "<<addOne(5)<<endl;
    cout<<"Add one to 10 = "<<addOne(10)<<endl;
    cout<<"Multilpy 7 to 6 = "<<multiplyBySeven(6)<<endl;
    cout<<"Multiply 3.5 with 6 = "<<multiplyBy3Point5(6)<<endl;
    return 0;
}
