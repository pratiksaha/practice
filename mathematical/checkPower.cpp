//to check if a given number can be expressed as power
#include<iostream>
#include<cmath>
using namespace std;

bool checkPower(unsigned int n) {
    if (n <= 1)
        return true;
    for (int x=2; x<=sqrt(n); x++) {
        unsigned p = x;
        while (p<=n) {
            p *= x;
            if (p==n)
                return true;
        }
    }
    return false;
}

int main() {
    cout<<"Nos which can be expressed as powers are:";
    for (int i =2; i<100; i++)
        if (checkPower(i))
           cout<<" "<<i;
    cout<<endl;
    return 0;
}
