//to find the smallest number to multiply to convert a floating point number into natural number
#include<bits/stdc++.h>
using namespace std;
 
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a%b);
}
 
int minNumMulToConvertFloatToInt(string &str) {
    int n = str.length();
    int count_after_dot = 0;
    bool dot_seen = false;
    int num = 0;
    for (int i = 0; i < n; i++) {
        if (str[i] != '.') {
            num = num*10 + (str[i] - '0');
            if (dot_seen == true)
                count_after_dot++;
        } else {
            dot_seen = true;
        }
    }
    if (dot_seen == false)
       return 1;
    int dem = (int)pow(10, count_after_dot);
    return (dem / gcd(num, dem));
}
 
int main() {
    string str = "5.125";
    cout<<"smallest number to multiply to convert "<<str<<" into natural number is "<<minNumMulToConvertFloatToInt(str)<<endl;
    return 0;
}
