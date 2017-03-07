//to sort a string according to the order defined by a pattern string
#include<bits/stdc++.h>
using namespace std;
#define MAX_CHAR 26

void sortAccordingPattern(string &str, string pat) {
    int count[MAX_CHAR] = {0};
    for (int i = 0 ; i < str.length(); i++)
        count[str[i] - 'a']++;
    int index = 0;
    for (int i = 0; i < pat.length(); i++)
        for (int j = 0; j < count[pat[i] - 'a']; j++)
            str[index++] = pat[i];
}

int main() {
    string pat = "bca";
    string str = "abc";
    cout<<str<<endl;
    sortAccordingPattern(str, pat);
    cout<<str<<endl;;
    return 0;
}
