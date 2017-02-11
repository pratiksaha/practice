//to count of numbers with same start and end digits in an interval
#include<bits/stdc++.h>
using namespace std;

int getFirstDigit(int x) {
    while (x >= 10)
        x /= 10;
    return x;
}

int getCountWithSameStartAndEndFrom1(int x) {
    if (x < 10)
        return x;
    int tens = x / 10;
    int res = tens + 9;
    int firstDigit = getFirstDigit(x);
    int lastDigit = x % 10;
    if (lastDigit < firstDigit)
        res--;
    return res;
}
 
int getCountWithSameStartAndEnd(int start, int end) {
    return getCountWithSameStartAndEndFrom1(end) - getCountWithSameStartAndEndFrom1(start - 1);
}

int main() {
    int start = 5, end = 40;
    cout<<"Count of numbers with same start and end digits between "<<start<<" & "<<end<<" is "<<getCountWithSameStartAndEnd(start, end)<<endl;
    return 0;
}
