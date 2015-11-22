//to find if a given number is fancy or not
//Using features of C++ Standard (2011) Compile using g++ -std=c++1
#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
 
bool checkFancy(string num) {
    unordered_map<char, char> fp;
    fp['0'] = '0';
    fp['1'] = '1';
    fp['6'] = '9';
    fp['8'] = '8';
    fp['9'] = '6';
    int n = num.length();
    int l = 0, r = n-1;
    while (l<=r) {
        if (fp.find(num[l]) == fp.end() || fp[num[l]] != num[r])
            return false;
        l++;
        r--;
    }
    return true;
}

int main() {
    string str = "9088806";
    cout<<str<<(checkFancy(str)?" is fancy":"is not fancy")<<endl;
    return 0;
}
