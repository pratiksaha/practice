//to find min number whose factorial contains at least n trailing zeroes
#include<bits/stdc++.h>
using namespace std;

bool check(int p, int n) {
    int temp = p, count = 0, f = 5;
    while (f <= temp) {
        count += temp/f;
        f = f*5;
    }
    return (count >= n);
}

int minNoWithTrailingZerosInFactorial(int n) {
    if (n==1)
        return 5;
    int low = 0;
    int high = 5*n;
    while (low <high) {
        int mid = (low + high)/2;
        if (check(mid, n))
            high = mid;
        else
            low = mid+1;
    }
    return low;
}

int main() {
    int n = 6;
    cout<<"Min No with "<<n<<" trailing zeroes in factorial is "<<minNoWithTrailingZerosInFactorial(n)<<endl;
    return 0;
}
