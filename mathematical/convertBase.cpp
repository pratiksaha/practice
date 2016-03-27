//to convert a number from any base to decimal and vice-versa
#include<bits/stdc++.h>
using namespace std;

int toVal(char c) {
    if (c >= '0' && c <= '9')
        return (int)c - '0';
    else
        return (int)c - 'A' + 10;
}

char fromVal(int num) {
    if (num >= 0 && num <= 9)
        return (char)(num + '0');
    else
        return (char)(num - 10 + 'A');
}

void strev(char *str) {
    int len = strlen(str);
    for (int i = 0; i<len/2; i++) {
        char temp = str[i];
        str[i] = str[len-i-1];
        str[len-i-1] = temp;
    }
}

int toDecimal(char *str, int base) {
    int num = 0;
    for (int i=strlen(str)-1, power=1; i>=0; i--) {
        if (toVal(str[i]) >= base) {
           cout<<"Invalid Number\n";
           return -1;
        }
        num += toVal(str[i])*power;
        power = power*base;
    }
    return num;
}

char* fromDecimal(int num, int base) {
    char *res = (char *)malloc(100*sizeof(char));
    int i= 0;
    while (num > 0) {
        res[i++] = fromVal(num%base);
        num /= base;
    }
    res[i] = '\0';
    strev(res);
    return res;
}

int main() {
    int base = 16;
    char str[] = "11A";
    int num = 282;
    cout<<"Decimal equivalent of "<<str<<" in base "<<base<<" is "<<toDecimal(str, base)<<endl;
    cout<<"Base equivalent of "<<num<<" in base "<<base<<" is "<<fromDecimal(num, base)<<endl;
    return 0;
}
