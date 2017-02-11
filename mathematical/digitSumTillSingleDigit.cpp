//finding sum of digits of a number until sum becomes single digit
#include<bits/stdc++.h> 
using namespace std;
 
int digitSumTillSingleDigit(int n){
    return (n % 9 == 0) ? 9 : (n % 9);
}
 
int main() {
    int n = 9999;
    cout<<"sum of digits of "<<n<<" until sum becomes single digit is "<<digitSumTillSingleDigit(n)<<endl;
    n = 1234;
    cout<<"sum of digits of "<<n<<" until sum becomes single digit is "<<digitSumTillSingleDigit(n)<<endl;
    return 0;
}
