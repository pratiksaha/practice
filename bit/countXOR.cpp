//to find XOR of counts 0s and 1s
#include<bits/stdc++.h>
using namespace std;

int countXOR(int n) {
    int count0 = 0, count1 = 0;
    while (n) {
        (n % 2 == 0) ? count0++ :count1++;
        n /= 2;
    }
    return (count0 ^ count1);
}
 
int main() {
    int n = 31;
    cout<<"XOR of count of 0s and count of 1s in "<<n<<" is "<<countXOR(n)<<endl;
    return 0;
}
