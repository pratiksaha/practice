#include <iostream>
using namespace std;

long int russianPeasant(int a, int b) {
    int res = 0;
    while (b > 0) {
        if (b & 1)//if second number becomes odd, add the first number to result
            res = res + a;
        a = a << 1;//double the first number
        b = b >> 1;//halve the second number
    }
    return res;
}

int main()
{
    cout<<russianPeasant(18, 1) << endl;
    cout<<russianPeasant(20, 12) << endl;
    return 0;
}
