//return previous element in an expanding matrix
#include<bits/stdc++.h>
using namespace std;

string prevElemExpandingMatrix(string str) {
    int n = str.length();
    while (n--) {
        if (str[n] == 'd') {
            str[n] = 'c';
            break;
        }
        else if (str[n] == 'b') {
            str[n] = 'a';
            break;
        }
        if (str[n] == 'a')
            str[n] = 'b';
        else if (str[n] == 'c')
            str[n] = 'd';
    }
    return str;
}

int main() {
    string str = "aacbddc";
    cout<<"Left of "<<str<<" is "<<prevElemExpandingMatrix(str)<<endl;
   return 0;
}
