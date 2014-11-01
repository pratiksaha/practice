//Word Break Problem
//Using features of C++ Standard (2001) Compile using g++ -std=c++11
#include<iostream>
#include<string>
#include<algorithm>
#include<unordered_map>
#include<utility>
using namespace std;

unordered_map<string, int> dictionary = {   {"a", 1}, //unordered_map used for dictionary for avg constant time lookup
                                            {"ice", 1},
                                            {"cream", 1},
                                            {"icecream", 1}
                                        };

bool dictionaryContains(string word) {
    if ( dictionary.find(word) != dictionary.end() )
        return true;
    else
        return false;
}

unordered_map<string, string> table; //table for memoization

string wordBreak(string word) {
    if ( dictionaryContains(word) )
        return word;
    if ( table.find(word) != table.end() )
        return table[word];
    int len = word.length();
    string seg_break;
    for (int i=1; i<len; i++) {
        string prefix = word.substr(0, i);
        if ( dictionaryContains(prefix) ) {
            string suffix = word.substr(i, len-i+1);
            seg_break = wordBreak(suffix);
            if ( !seg_break.empty() ) {
                table.insert(make_pair(word, prefix + " " + suffix));
                return prefix + " " + suffix;
            }
        }
    }
    table.insert(make_pair(word, seg_break));
    return seg_break;
}

int main() {
    string s1 = "aice";
    string s2 = "icecream";
    string s3 = "anice";
    string res;
    res = wordBreak(s1);
    cout<<"For \'"<<s1<<"\' word break is : "<<(res.empty()?"Not Possible":res)<<endl;
    res = wordBreak(s2);
    cout<<"For \'"<<s2<<"\' word break is : "<<(res.empty()?"Not Possible":res)<<endl;
    res = wordBreak(s3);
    cout<<"For \'"<<s3<<"\' word break is : "<<(res.empty()?"Not Possible":res)<<endl;
}
