//to find sum of divisors of a natural number
#include<bits/stdc++.h>
using namespace std;

int sumOfDivisors(int num) {
    int result = 0;
    for (int i=2; i<=sqrt(num); i++) {
        if (num%i==0) {
            if (i==(num/i))
                result += i;
            else
                result += (i + num/i);
        }
    }
    return (result + 1);
}
 
int main() {
    int num = 36;
    cout<<"Sum of proper divisors of "<<num<<" is "<<sumOfDivisors(num)<<endl;
    return 0;
}
