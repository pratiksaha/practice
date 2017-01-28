//print kaprekar's no from 1 to 10000
#include<bits/stdc++.h>
using namespace std;

bool kaprekarNumber(int n) {
    if (n == 1)
       return true;
    int sq_n = n * n;
    int count_digits = 0;
    while (sq_n) {
        count_digits++;
        sq_n /= 10;
    }
    sq_n = n*n;
    for (int r_digits=1; r_digits<count_digits; r_digits++) {
        int eq_parts = pow(10, r_digits);
        if (eq_parts == n)
            continue;
        int sum = sq_n/eq_parts + sq_n % eq_parts;
        if (sum == n)
            return true;
    }
    return false;
}

int main(){
    cout<<"Printing Kaprekar Numbers upto 10000 :";
    for (int i=1; i<10000; i++)
        if (kaprekarNumber(i))
            cout<<" "<<i;
    cout<<endl;
    return 0;
}
