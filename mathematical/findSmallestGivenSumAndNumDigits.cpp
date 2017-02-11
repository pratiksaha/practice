//to find the largest number that can be formed from given sum of digits and number of digits
#include<bits/stdc++.h>
using namespace std;

void findSmallestGivenSumAndNumDigits(int m, int s) {
    if (s == 0) {
        (m == 1)? cout<<"Smallest number is 0\n" : cout<<"Smallest number is Not possible\n";
    } else if (s > 9*m) {
        cout<<"Smallest number is Not possible\n";
    } else {
        int res[m];
        s -= 1;
        for (int i=m-1; i>0; i--) {
            if (s > 9) {
                res[i] = 9;
                s -= 9;
            } else {
                res[i] = s;
                s = 0;
            }
        }
        res[0] = s + 1;
        cout<<"Smallest number is : ";
        for (int i=0; i<m; i++)
            cout<<res[i];
        cout<<endl;
    }
}

int main() {
    int s = 9, m = 2;
    findSmallestGivenSumAndNumDigits(m, s);
    return 0;
}
