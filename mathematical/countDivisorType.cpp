//to find if count of divisors is even or odd
#include<bits/stdc++.h>
using namespace std;

string countDivisorType(int n) {
    int root_n = sqrt(n);
    if (root_n*root_n == n)
        return "odd";
    else
        return "even";
}

int main() {
    int n = 10;
    cout<<"The type of total count of divisors of "<<n<<" is "<<countDivisorType(n)<<endl;
    return 0;
}
