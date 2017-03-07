//to count distinct strings with even odd swapping allowed
//Using features of C++ Standard (2011) Compile using g++ -std=c++11
#include<bits/stdc++.h>
using namespace std;
#define MAX_CHAR 26

string encodeString(string str) {
    int hashEven[MAX_CHAR] = {0};
    int hashOdd[MAX_CHAR] = {0};
    for (int i=0; i<str.length(); i++) {
        char c = str[i];
        if (i&1)
            hashOdd[c-'a']++;
        else
            hashEven[c-'a']++;
    }
    string encoding = "";
    for (int i=0; i<MAX_CHAR; i++) {
        encoding += to_string(hashEven[i]);
        encoding += to_string('-');
        encoding += to_string(hashOdd[i]);
        encoding += to_string('-');
    }
    return encoding;
}

int countDistinctOddEvenChanges(string input[], int n) {
    int countDist = 0;
    unordered_set<string> s;
    for (int i=0; i<n; i++) {
        if (s.find(encodeString(input[i])) == s.end()) {
            s.insert(encodeString(input[i]));
            countDist++;
        }
    }
    return countDist;
}

int main() {
    string input[] = {"abcd", "acbd", "adcb", "cdba", "bcda", "badc"};
    int n = sizeof(input)/sizeof(input[0]);
    cout<<countDistinctOddEvenChanges(input, n)<<endl;
    return 0;
}
