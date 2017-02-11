//to generate palindromic numbers less than n
#include<bits/stdc++.h>
using namespace std;
 
int createPalindrome(int input, int b, bool isOdd) {
    int n = input;
    int palin = input;
    if (isOdd)
        n /= b;
    while (n > 0) {
        palin = palin * b + (n % b);
        n /= b;
    }
    return palin;
}
 
void allPalindromes(int n) {
    int number;
    cout<<"All palindromes till "<<n<<" are :";
    for (int j = 0; j < 2; j++) {
        int i = 1;
        while ((number = createPalindrome(i, 10, j % 2)) < n) {
            cout<<" "<<number;
            i++;
        }
    }
    cout<<endl;
}
 
int main() {
    allPalindromes(104);
    return 0;
}
