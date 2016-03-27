//to convert Binary To Gray and Gray to Binary
#include<bits/stdc++.h>
using namespace std;

char exor(char a, char b) {
    return (a == b)? '0': '1';
}

char flip(char c) {
    return (c == '0')? '1': '0';
}

string BinaryGray(string binary) {
    string gray = "";
    gray += binary[0];
    for (int i=1; i<binary.length(); i++) {
        gray += exor(binary[i-1], binary[i]);
    }
    return gray;
}

string GrayBinary(string gray) {
    string binary  = "";
    binary += gray[0];
    for (int i=1; i<gray.length(); i++) {
        if (gray[i] == '0')
            binary += binary[i-1];
        else
            binary += flip(binary[i-1]);
    }
    return binary;
}

int main() {
    string binary = "01001";
    string gray = "01101";
    cout<<"Gray code of "<<binary<<" is "<<BinaryGray(binary)<<endl;
    cout<<"Binary code of "<<gray<<" is "<<GrayBinary(gray)<<endl;
    return 0;
}
