//to generate Aliquot Sequence
//Using features of C++ Standard (2011) Compile using g++ -std=c++11
#include <bits/stdc++.h>
using namespace std;
 
int getSum(int n) {
    int sum = 0;
    for (int i=1; i<=sqrt(n); i++) {
        if (n%i==0) {
            if (n/i == i) {
                sum = sum + i;
            } else {
                sum = sum + i;
                sum = sum + (n / i);
            }
        }
    }
    return sum - n;
}
 
void aliquotSequence(int n) {
    cout<<"Aliquot Sequence of "<<n<<" is : ";
    cout<<n;
    unordered_set<int>  s;
    s.insert(n);
    int next = 0;
    while (n > 0) {
        n = getSum(n);
        if (s.find(n) != s.end())        {
            cout<<"\nRepeats with "<<n;
            break;
        }
        cout<<" "<<n;
        s.insert(n);
    }
    cout<<endl;
}
 
/* Driver program to test above function */
int main() {
    aliquotSequence(12);
    return 0;
}
