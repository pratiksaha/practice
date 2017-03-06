//to find longest common subsequence with permutations allowed
#include<bits/stdc++.h>
using namespace std;

string longestCommonSubsequenceWithPermutations(string str1, string str2) {
    int count1[26] = {0}, count2[26]= {0};
    for (int i=0; i<str1.length(); i++)
        count1[str1[i]-'a']++;
    for (int i=0; i<str2.length(); i++)
        count2[str2[i]-'a']++;
    string result;
    for (int i=0; i<26; i++)
        for (int j=1; j<=min(count1[i],count2[i]); j++)
            result.push_back('a' + i);
    return result; 
}

int main() {
    string str1 = "dajfdffdlkdf", str2 = "jkld";
    cout<<longestCommonSubsequenceWithPermutations(str1, str2)<<endl;
    return 0;
}
