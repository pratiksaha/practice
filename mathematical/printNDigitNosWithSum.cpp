//to print all n digit numbers whose sum of digits equals to given sum
#include<bits/stdc++.h>
using namespace std;

void printNDigitNosWithSum(int n, int sum, char* out, int index) {
    if (index > n || sum < 0)
        return;
    if (index == n) {
        if(sum == 0) {
            out[index] = '\0';
            cout<<" "<<out;
        }
        return;
    }
    for (int i = 0; i <= 9; i++) {
        out[index] = i + '0';
        printNDigitNosWithSum(n, sum - i, out, index + 1);
    }
}

void printNDigitNosWithSum(int n, int sum) {
    char out[n + 1];
    cout<<"All "<<n<<" digit nos with sum "<<sum<<" are :";
    for (int i = 1; i <= 9; i++) {
        out[0] = i + '0';
        printNDigitNosWithSum(n, sum - i, out, 1);
    }
    cout<<endl;
}

int main() {
    printNDigitNosWithSum(2, 3);
    return 0;
}
