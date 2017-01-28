//to check if a number is power of another number
#include<bits/stdc++.h>
using namespace std;

bool isPower(int x, long int y) {
    if (x == 1)
        return (y == 1);
    long int pow = 1;
    while (pow < y)
        pow *= x;
   return (pow == y);
}

int main() {
    int x, y;
    x = 10, y = 1;
    cout<<y<<" is"<<(isPower(x, y)? " " : " not ")<<"a  power of "<<x<<endl;
    x = 1, y = 20;
    cout<<y<<" is"<<(isPower(x, y)? " " : " not ")<<"a  power of "<<x<<endl;
    x = 2, y = 128;
    cout<<y<<" is"<<(isPower(x, y)? " " : " not ")<<"a  power of "<<x<<endl;
    x = 2, y = 30;
    cout<<y<<" is"<<(isPower(x, y)? " " : " not ")<<"a  power of "<<x<<endl;
    return 0;
}
