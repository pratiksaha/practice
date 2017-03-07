//to find minimum number of characters to be removed to make two strings anagram
#include<bits/stdc++.h>
using namespace std;
#define CHARS 26

int minCharsRemovalMakeAnagram(string str1, string str2) {
    int count1[CHARS] = {0}, count2[CHARS] = {0};
    for (int i=0; str1[i]!='\0'; i++)
        count1[str1[i]-'a']++;
    for (int i=0; str2[i]!='\0'; i++)
        count2[str2[i]-'a']++;
    int result = 0;
    for (int i=0; i<26; i++)
        result += abs(count1[i] - count2[i]);
    return result;
}

int main() {
    string str1 = "bcadeh", str2 = "hea";
    cout<<"Min chars to be removedto make "<<str1<<" & "<<str2<<" anagrams is "<<minCharsRemovalMakeAnagram(str1, str2)<<endl;
    return 0;
}
