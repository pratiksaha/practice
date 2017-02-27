//to check if two strings are k anagram or not
#include<bits/stdc++.h>
using namespace std;
#define MAX_CHAR 26
 
bool checkKAnagrams(string str1, string str2, int k) {
    int n = str1.length();
    if (str2.length() != n)
        return false;
    int hash_str1[MAX_CHAR] = {0};
    for (int i = 0; i < n ; i++)
        hash_str1[str1[i]-'a']++;
    int count = 0;
    for (int i = 0; i < n ; i++) {
        if (hash_str1[str2[i]-'a'] > 0)
            hash_str1[str2[i]-'a']--;
        else
            count++;
        if (count > k)
            return false;
    }
    return true;
}
 
int main() {
    string str1 = "fodr";
    string str2 = "gork";
    int k = 2;
    cout<<str1<<" & "<<str2<<(checkKAnagrams(str1, str2, k) ? " are " : " are not ")<<k<<"-anagrams\n";
    return 0;
}
