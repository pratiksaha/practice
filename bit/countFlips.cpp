#include<iostream>
using namespace std;

int countFlips(int a, int b){
    int c = a^b;
    int count = 0;
    while(c)
    {
        count += c&1;
        c >>= 1;
    }
    return count;
}

int main(){
    int a, b;
    a = 8;
    b = 9;
    cout<<"No of flips to convert "<<a<<" to "<<b<<" is "<<countFlips(a, b)<<endl;
    return 0;
}
