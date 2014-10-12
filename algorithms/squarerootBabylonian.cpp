//Returns the square root of n
#include<iostream>
using namespace std;

float Babylonian(float n) {
    float x = n;
    float y = 1;
    float e = 0.000001; // e decides the accuracy level
    while(x - y > e) {
        x = (x + y)/2;
        y = n/x;
    }
    return x;
}

int main()
{
    int n = 49;
    cout<<"Square root of "<<n<<" is "<<Babylonian(n)<<endl;
    n = 81;
    cout<<"Square root of "<<n<<" is "<<Babylonian(n)<<endl;
    n = 99;
    cout<<"Square root of "<<n<<" is "<<Babylonian(n)<<endl;
    return 0;
}
