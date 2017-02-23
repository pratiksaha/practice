//to count numbers with k odd divisors in range
#include<bits/stdc++.h>
using namespace std;
 
bool isPerfect(int n) {
    int s = sqrt(n);
    return (s*s == n);
}
 
int divisorCount(int n) {
    int count=0;
    for (int i=1; i<=sqrt(n)+1; i++) {
        if (n%i==0) {
            if (n/i == i)
                count += 1;
            else
                count += 2;
        }
    }
    return count;
}

int kDivisorsRange(int a,int b,int k) {
    int count = 0;
    for (int i=a; i<=b; i++)
        if (isPerfect(i))
            if (divisorCount(i) == k)
                count++;
    return count;
}

int main() {
    int a = 2, b = 49, k = 3;
    cout<<"No of integers in ["<<a<<","<<b<<"] which are divisible by "<<k<<" is "<<kDivisorsRange(a, b, k)<<endl;
    return 0;
}
