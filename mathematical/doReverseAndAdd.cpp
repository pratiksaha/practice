//to implement reverse and add function
#include<bits/stdc++.h>
using namespace std;
#define limit 4294967295

long long reverseDigits(long long num) {
    long long rev_num = 0;
    while (num > 0) {
        rev_num = rev_num*10 + num%10;
        num = num/10;
    }
    return rev_num;
}

bool isPalindrome(long long num) {
    return (reverseDigits(num) == num);
}

void doReverseAndAdd(long long num) {
    cout<<"For "<<num<<" : ";
    long long rev_num=0;
    while (num <= limit) {
        rev_num = reverseDigits(num);
        num = num + rev_num;
        if (isPalindrome(num)) {
            cout<<num<<endl;
            break;
        } else if (num > limit) {
            cout<<"No palindrome exist\n";
        }
    }
}

int main() {
    doReverseAndAdd(195);
    doReverseAndAdd(265);
    return 0;
}
