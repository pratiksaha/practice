//to check if a number can be expressed as sum of consecutive numbers
#include<bits/stdc++.h>
using namespace std;
 
bool checkSumOfConsecutiveNos(unsigned int n) {
    return ((n&(n-1)) && n);
}
 
int main() {
    int n = 15;
    cout<<n<<" can"<<(checkSumOfConsecutiveNos(n)? " " : " not ")<<"be expressed as sum of consecutive numbers\n";
    return 0;
}
