//to add 2 fractions
#include<bits/stdc++.h>
using namespace std;
 
int gcd(int a, int b) {
    if (a == 0)
        return b;
    return gcd(b%a, a);
}
 
void lowest(int &den3, int &num3) {
    int common_factor = gcd(num3,den3);
    den3 = den3/common_factor;
    num3 = num3/common_factor;
}

void addFraction(int num1, int den1, int num2, int den2, int &num3, int &den3) {
    den3 = gcd(den1,den2);
    den3 = (den1*den2) / den3;
    num3 = (num1)*(den3/den1) + (num2)*(den3/den2);
    lowest(den3,num3);
}
 
int main() {
    int num1=1, den1=500, num2=2, den2=1500, den3, num3;
    addFraction(num1, den1, num2, den2, num3, den3);
    cout<<num1<<"/"<<den1<<" + "<<num2<<"/"<<den2<<" is equal to "<<num3<<"/"<<den3<<endl;
    return 0;
}
