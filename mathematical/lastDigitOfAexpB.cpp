//to find last digit of a^b
#include<bits/stdc++.h>
using namespace std;
 
int modulo(int a, char b[]) {
    int mod = 0;
    for (int i=0; i<strlen(b); i++)
        mod = (mod*10 + b[i] - '0')%a;
    return mod;
}
 
int lastDigitOfAexpB(char a[], char b[]) {
    int len_a = strlen(a), len_b = strlen(b);
    if (len_a==1 && len_b==1 && b[0]=='0' && a[0]=='0')
        return 1;
    if (len_b==1 && b[0]=='0' )
        return 1;
    if (len_a==1 && a[0]=='0')
        return 0;
    int exp = (modulo(4,b)==0)? 4 : modulo(4, b);
    int res = pow(a[len_a - 1] - '0', exp);
    return res % 10;
}
 
int main() {
    char a[] = "117", b[] = "3";
    cout<<lastDigitOfAexpB(a, b)<<endl;
    return 0;
}
