//to in-place replace multiple occurrences of a pattern by X
#include <bits/stdc++.h>
using namespace std;

bool compare(char* str, char* pattern) {
    for (int i = 0; pattern[i]; i++)
        if (str[i] != pattern[i])
            return false;
    return true;
}

void replacePatternByX(char *str, char* pattern) {
    if (pattern == NULL)
        return;
    int len = strlen(pattern);
    if (len == 0)
        return;
    int i = 0, j = 0;
    int count;
    while (str[j]) {
        count = 0;
        while (compare(str+j, pattern)) {
            j = j + len;
            count++;
        }
        if (count > 0)
            str[i++] = 'X';
        if (str[j])
            str[i++] = str[j++];
    }
    str[i] = '\0';
}

int main() {
    char str[] = "abcdtfydghksabcdfhklsffabcd";
    char pattern[] = "abcd";
    cout<<"Replacing "<<pattern<<" by X in "<<str<<" gives : ";
    replacePatternByX(str, pattern);
    cout<<str<<endl;
    return 0;
}
