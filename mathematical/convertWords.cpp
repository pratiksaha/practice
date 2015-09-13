//to print a given number in word
#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;

#define CHAR_TO_NUM(c) ((int)c - 48)

string threeWords(string num) {
    string ones[10] = { "", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    string deca[10] = { "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
    string tens[10] = { "", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
    string ans = "";
    int len = num.length();
    if (len == 1) {
        if (CHAR_TO_NUM(num[0]) == 0)
            ans = "zero";
        else
            ans = ones[CHAR_TO_NUM(num[0])];
    } else if (len == 2) {
        if (CHAR_TO_NUM(num[0]) == 1)
            ans = deca[CHAR_TO_NUM(num[1])];
        else
            ans = tens[CHAR_TO_NUM(num[0])] + " " + ones[CHAR_TO_NUM(num[1])]; 
    } else {
        if (CHAR_TO_NUM(num[0]) != 0 ) {
            ans = ones[CHAR_TO_NUM(num[0])] + " hundreds and ";
        }
        if (CHAR_TO_NUM(num[1]) == 0 ) {
            ans = ans + ones[CHAR_TO_NUM(num[2])];
        } else if (CHAR_TO_NUM(num[1]) == 1 ) {
            ans = ans + deca[CHAR_TO_NUM(num[2])];
        } else {
            ans = ans + tens[CHAR_TO_NUM(num[1])] + " " + ones[CHAR_TO_NUM(num[2])];
        }
    }
    return ans;
}

string convertWords(string num) {
    int len = num.length();
    int index = 0;
    string powers[] = {"", "thousands", "million", "billion", "trillion", "quadrillion", "quintillion", "sextillion", "septillion"};
    string ans = "";
    while (len>0) {
        string temp;
        if (len == 1) {
            temp = num.substr(len-1, 1);
        } else if (len == 2) {
            temp = num.substr(len-2, 2);
        } else {
            temp = num.substr(len-3, 3);
        }
        ans = threeWords(temp) + " " + powers[index] + " " + ans;
        len -= 3;
        index++;
    }
    return ans;
}

int main(void) {
    string s;
    s = "0";
    cout<<s<<" : "<<convertWords(s)<<endl;
    s = "7";
    cout<<s<<" : "<<convertWords(s)<<endl;
    s = "15";
    cout<<s<<" : "<<convertWords(s)<<endl;
    s = "23";
    cout<<s<<" : "<<convertWords(s)<<endl;
    s = "89";
    cout<<s<<" : "<<convertWords(s)<<endl;
    s = "603";
    cout<<s<<" : "<<convertWords(s)<<endl;
    s = "113";
    cout<<s<<" : "<<convertWords(s)<<endl;
    s = "523";
    cout<<s<<" : "<<convertWords(s)<<endl;
    s = "1923";
    cout<<s<<" : "<<convertWords(s)<<endl;
    s = "15946";
    cout<<s<<" : "<<convertWords(s)<<endl;
    s = "9009015909999999999";
    cout<<s<<" : "<<convertWords(s)<<endl;
    return 0;
}
