//roman
#include<bits/stdc++.h>
using namespace std;

int value(char r) {
    if (r == 'I')
        return 1;
    if (r == 'V')
        return 5;
    if (r == 'X')
        return 10;
    if (r == 'L')
        return 50;
    if (r == 'C')
        return 100;
    if (r == 'D')
        return 500;
    if (r == 'M')
        return 1000;
    return -1;
}

int sub_digit(char num1, char num2, int i, char *c) {
    c[i++] = num1;
    c[i++] = num2;
    return i;
}

int digit(char ch, int n, int i, char *c) {
    for (int j = 0; j < n; j++)
        c[i++] = ch;
    return i;
}

void printDecimal(string str) {
    int res = 0;
    cout<<"Decimal equivalent of "<<str<<" is ";
    for (int i=0; i<str.length(); i++) {
        int s1 = value(str[i]);
        if (i+1 < str.length()) {
            int s2 = value(str[i+1]);
            if (s1 >= s2) {
                res = res + s1;
            } else {
                res = res + s2 - s1;
                i++;
            }
        } else {
            res = res + s1;
            i++;
        }
    }
    cout<<res<<endl;
}

void printRoman(int number) {
    char c[10001];
    int i = 0;
    assert(number>0);
    cout<<"Roman numeral for "<<number<<" is ";
    while (number != 0) {
        if (number >= 1000) {
            i = digit('M', number/1000, i, c);
            number = number%1000;
        } else if (number >= 500) {
            if (number < 900) {
                i = digit('D', number/500, i, c);
                number = number%500;
            } else {
                i = sub_digit('C', 'M', i, c);
                number = number%100 ;
            }
        } else if (number >= 100) {
            if (number < 400) {
                i = digit('C', number/100, i, c);
                number = number%100;
            } else {
                i = sub_digit('C','D',i,c);
                number = number%100;
            }
        } else if (number >= 50 ) {
            if (number < 90) {
                i = digit('L', number/50,i,c);
                number = number%50;
            } else {
                i = sub_digit('X','C',i,c);
                number = number%10;
            }
        } else if (number >= 10) {
            if (number < 40) {
                i = digit('X', number/10,i,c);
                number = number%10;
            } else {
                i = sub_digit('X','L',i,c);
                number = number%10;
            }
        } else if (number >= 5) {
            if (number < 9) {
                i = digit('V', number/5,i,c);
                number = number%5;
            } else {
                i = sub_digit('I','X',i,c);
                number = 0;
            }
        } else if (number >= 1) {
            if (number < 4) {
                i = digit('I', number,i,c);
                number = 0;
            } else {
                i = sub_digit('I', 'V', i, c);
                number = 0;
            }
        }
    }
    for (int j = 0; j < i; j++)
        cout<<c[j];
    cout<<endl;
}

int main() {
    printRoman(3549);
    printDecimal("MCMIV");
    return 0;
}
