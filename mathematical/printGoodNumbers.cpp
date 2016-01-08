//to print good numbers in a given range
#include<bits/stdc++.h>
using namespace std;

bool isGood(int n, int d) {
    int digit = n%10;
    int sum = digit;
    if (digit == d) {
      return false;
    } else {
        n /= 10;
        while (n) {
            digit = n%10;
            if (digit==d || digit<=sum) {
                return false;
            } else {
                sum += digit;
                n /= 10;
            }
        }
        return true;
    }
}

void printGoodNumbers(int low, int high, int d) {
    cout<<"All good nos in ["<<low<<","<<high<<"] not containning "<<d<<" are :";
    for (int i=low; i<=high; i++)
        if (isGood(i, d))
            cout<<" "<<i;
    cout<<endl;
}

int main() {
    int low = 410, high = 520, d = 3;
    printGoodNumbers(low, high, d);
    return 0;
}
