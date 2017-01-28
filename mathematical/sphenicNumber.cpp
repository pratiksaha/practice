//print Sphenic numbers
//Using features of C++ Standard (2011) Compile using g++ -std=c++11
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

vector<int> least_pf(MAX, 0);

void leastPrimeFactor() {
    least_pf[1] = 1;
    for (int i = 2; i <= MAX; i++) {
        if (least_pf[i] == 0) {
            least_pf[i] = i;
            for (int j = 2*i; j <= MAX; j += i) {
                if (least_pf[j] == 0) {
                    least_pf[j] = i;
                }
            }
        }
    }
}

bool sphenicNumber(int n) {
    unordered_set<int> s;
    while (n > 1) {
        int lpf = least_pf[n];
        int init_size = s.size();
        s.insert(lpf);
        if (s.size() == init_size || s.size() > 3)
            return false;
        n /= lpf;
    }
    return (s.size() == 3);
}

int main() {
    leastPrimeFactor();
    cout<<"Printing Sphenic Numbers upto 100 :";
    for (int i=1; i<100; i++)
        if (sphenicNumber(i))
           cout<<" "<<i;
    cout<<endl;
    return 0;
}
