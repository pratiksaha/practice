//to print all divisors of a number
#include<bits/stdc++.h>
using namespace std;

void printDivisors(int n) {
    cout<<"Divisors of "<<n<<" :";
    vector<int> v;
    for (int i=1; i<=sqrt(n)+1; i++) {
        if (n%i==0) {
            cout<<" "<<i;
            if (n/i != i)
                v.push_back(n/i);
        }
    }
    for (int i=v.size()-1; i>=0; i--)
        cout<<" "<<v[i];
    cout<<endl;
}

int main() {
    int n = 100;
    printDivisors(100);
    return 0;
}
