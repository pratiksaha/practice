//
#include<bits/stdc++.h>
using namespace std;

void replaceWildcardBinaryString(string str, int index) {
    if (index == str.size()) {
        cout<<str<<endl;
        return;
    } else if (str[index] == '?') {
        str[index] = '0';
        replaceWildcardBinaryString(str, index + 1);
        str[index] = '1';
        replaceWildcardBinaryString(str, index + 1);
    } else {
        replaceWildcardBinaryString(str, index + 1);
    }
}

void replaceWildcardBinaryString(string str) {
    queue<string> q;
    q.push(str);
    while (!q.empty()) {
        string str = q.front();
        size_t index = str.find('?');
        if(index != string::npos) {
            str[index] = '0';
            q.push(str);
            str[index] = '1';
            q.push(str);
        } else {
            cout<<str<<endl;
        }
        q.pop();
    }
}
 
int main() {
    string str = "1??0?101";
    replaceWildcardBinaryString(str, 0);
    cout<<endl;
    replaceWildcardBinaryString(str);
    return 0;
}
