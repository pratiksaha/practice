//to find the largest number that can be formed from given sum of digits and number of digits
#include<bits/stdc++.h>
using namespace std;

void findLargestGivenSumAndNumDigits(int m, int s) {
    if (s == 0) {
        (m == 1)? cout<<"Largest number is 0\n" : cout<<"Largest number is Not possible\n";
    } else if (s > 9*m) {
        cout<<"Largest number is Not possible\n";
    } else {
        int res[m];
        for (int i=0; i<m; i++) {
            if (s >= 9) {
                res[i] = 9;
                s -= 9;
            } else {
                res[i] = s;
                s = 0;
            }
        }
        cout<<"Largest number is : ";
        for (int i=0; i<m; i++)
            cout<<res[i];
        cout<<endl;
    }
}

int main() {
    int s = 9, m = 2;
    findLargestGivenSumAndNumDigits(m, s);
    return 0;
}
