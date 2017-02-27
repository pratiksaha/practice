//to print all occurrences of every character together
#include<bits/stdc++.h>
using namespace std;
#define MAX_CHAR 26
 
void groupAccFirstAppearance(string str) {
    int n = str.length();
    int  count[MAX_CHAR] = {0};
    for (int i = 0 ; i < n ; i++)
        count[str[i]-'a']++;
    for (int i = 0; i < n ; i++) {
        while (count[str[i]-'a']--)
            cout<<str[i];
        count[str[i]-'a'] = 0;
    }
    cout<<endl;
}
 
int main() {
    string str = "pratiksaha";
    groupAccFirstAppearance(str);
    return 0;
}
