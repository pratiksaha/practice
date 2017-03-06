//to find if a string follows order defined by a given pattern
#include<bits/stdc++.h>
using namespace std;
#define CHAR_SIZE 256

bool checkStringFollowPattern(string str, string pat) {
    vector<int> label(CHAR_SIZE, -1);
    int order = 1;
    for (int i = 0; i < pat.length() ; i++) {
        label[pat[i]] = order;
        order++;
    }
    int last_order = -1;
    for (int i = 0; i < str.length(); i++) {
        if (label[str[i]] != -1) {
            if (label[str[i]] < last_order)
                return false;
            last_order =  label[str[i]];
        }
    }
    return true;
}

int main() {
    string str = "pratiksaha";
    string pattern = "ps";
    cout<<boolalpha<<checkStringFollowPattern(str, pattern)<<endl;
    return 0;
}
