//to check if a string is perfect reversible or not
#include<bits/stdc++.h>
using namespace std;

bool perfectReversible(string str) {
    int i = 0, j = str.length()-1;
    while (i < j) {
        if (str[i] != str[j])
            return false;
        i++;
        j--;
    }
    return true;
}

int main() {
    string str="aba";
    cout<<"String "<<str<<" is"<<(perfectReversible(str) ? " " : " not ")<<"perfect reversible\n";
    return 0;
} 
