//to calculate sum of all numbers present in a string containing alphanumeric characters
#include<bits/stdc++.h>
using namespace std;

int sumAllNosInString(string str) {
    string temp = "";
    int sum = 0;
    int n = str.length(); 
    for (int i = 0; i < n; i++){
        char ch = str[i];
        if (isdigit(ch)) {
            temp += ch;
        } else {
            sum += atoi(temp.c_str());
            temp = "";
        }
    }
    return sum + atoi(temp.c_str());
}

int main() {
    string str = "12abc20yz68";
    cout<<"Sum of all nos in "<<str<<" is "<<sumAllNosInString(str)<<endl;
    return 0;
}
