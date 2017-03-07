//to check if a string can be converted to an empty string by deleting given sub-string from any position any number of times
#include<bits/stdc++.h>
using namespace std;

bool isEmptyRepeatedRemoval(string str, string sub_str) {
    while (str.size() > 0) {
        int idx = str.find(sub_str);
        if (idx == -1)
            break;
        str.erase(idx, sub_str.size());
    }
 
    return (str.size() == 0);
}

int main() {
    string str = "abcabcdd", sub_str = "abcd";
    cout<<"On removing "<<sub_str<<" from "<<str<<(isEmptyRepeatedRemoval(str, sub_str) ? " can " : " cannot ")<<"become empty\n";
    return 0;
}
