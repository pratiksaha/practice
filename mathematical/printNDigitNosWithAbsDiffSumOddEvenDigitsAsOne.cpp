//to print all n digit numbers with absolute difference between sum of even and odd digits is 1
#include <bits/stdc++.h>
using namespace std;

void printNDigitNosWithAbsDiffSumOddEvenDigitsAsOne(int n, char* out, int index, int evenSum, int oddSum) {
    if (index > n)
        return;
    if (index == n) {
        if (abs(evenSum - oddSum) == 1) {
            out[index] = '\0';
            cout<<" "<<out;
        }
        return;
    }
    if (index & 1) {
        for (int i = 0; i <= 9; i++) {
            out[index] = i + '0';
            printNDigitNosWithAbsDiffSumOddEvenDigitsAsOne(n, out, index + 1, evenSum, oddSum + i);
        }
    } else {
        for (int i = 0; i <= 9; i++) {
            out[index] = i + '0';
            printNDigitNosWithAbsDiffSumOddEvenDigitsAsOne(n, out, index + 1, evenSum + i, oddSum);
        }
    }
}

int printNDigitNosWithAbsDiffSumOddEvenDigitsAsOne(int n) {
    cout<<"All "<<n<<" digit nos with absolute difference between sum of even and odd digits as One are :";
    char out[n + 1];
    int index = 0;
    int evenSum = 0, oddSum = 0;
    for (int i = 1; i <= 9; i++) {
        out[index] = i + '0';
        printNDigitNosWithAbsDiffSumOddEvenDigitsAsOne(n, out, index + 1, evenSum + i, oddSum);
    }
    cout<<endl;
}

int main() {
    printNDigitNosWithAbsDiffSumOddEvenDigitsAsOne(3);
    return 0;
}
