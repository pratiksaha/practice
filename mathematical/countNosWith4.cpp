//to count numbers having 4 as a digit
#include<iostream>
#include<cmath>
using namespace std;

int countNosWith4(int n) {
    if (n<4)
        return 0;
    int d = log10(n); //d = (no of digits in n) - 1
    int a[d+1];
    a[0] = 0, a[1] = 1;
    for (int i=2; i<=d; i++)
        a[i] = a[i-1]*9 + ceil(pow(10,i-1));
    int p = ceil(pow(10, d));
    int msd = n/p;
    if (msd == 4)
        return (msd)*a[d] + (n%p) + 1;
    else if (msd > 4)
        return (msd-1)*a[d] + p + countNosWith4(n%p);
    else
        return (msd)*a[d] + countNosWith4(n%p);
}

int main() {
    int n = 328;
    cout<<"Count of numbers from 1 to "<<n<<" that have 4 as a a digit is "<<countNosWith4(n)<<endl;
   return 0;
}
