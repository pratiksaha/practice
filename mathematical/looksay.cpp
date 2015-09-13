//to find n'th term in look and say sequence
#include<iostream>
using namespace std;

string looksay(int n) {
    if (n == 1) {
        return "1";
    } else if (n == 2) {
        return "11";
    } else {
        string str = "11";
        for (int i = 3; i<=n; i++) {
            str += '$'; //dummy char
            int len = str.length();
            int count = 1; //initialize count of matching chars
            string temp = ""; //initialize i'th term in series
            for (int j = 1; j < len; j++) { //process previous term to find the next term
                if (str[j] != str[j-1]) {
                    temp += count + '0'; //append count of str[j-1] to temp
                    temp += str[j-1]; //append str[j-1]
                    count = 1; //reset count
                } else {
                    count++; //increment count of matching chars
                }   
            }
            str = temp;
        }
        return str;
    }
}

int main() {
    int N = 4;
    cout<<looksay(N)<<endl;
    return 0;
}
