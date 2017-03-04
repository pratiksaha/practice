//to change the gender of a string
//Using features of C++ Standard (2011) Compile using g++ -std=c++11
#include<bits/stdc++.h>
using namespace std;
 
string changeGender(string str) {
    unordered_multimap <string, string> dictionary = {
        {"batman", "batwoman"},
        {"batwoman", "batman"},
        {"boy", "girl"},
        {"girl", "boy"},
        {"boyfriend", "girlfriend"},
        {"girlfriend", "boyfriend"},
        {"father", "mother"},
        {"mother", "father"},
        {"husband", "wife"},
        {"wife", "husband"},
        {"he", "she"},
        {"she", "he"},
        {"his", "her"},
        {"her", "his"},
        {"male", "female"},
        {"female", "male"},
        {"man", "woman"},
        {"woman", "man"},
        {"Mr", "Ms"},
        {"Mr", "Ms"},
        {"sir", "madam"},
        {"madam", "sir"},
        {"son", "daughter"},
        {"daughter", "son"},
        {"uncle", "aunt"},
        {"aunt", "uncle"},
    };
    str = str + ' ';
    int n = str.length();
    string temp = "", ans = "";
    for (int i=0; i<=n-1; i++) {
        if (str[i] != ' ') {
            temp.push_back(str[i]);
        } else {
            if (dictionary.find(temp) != dictionary.end())
                temp = dictionary.find(temp)->second;
            ans = ans + temp + ' ';
            temp.clear();
        }
    }
    return(ans);
}
 
int main() {
    string str = "she is going to watch movie with her boyfriend";
    cout<<changeGender(str)<<endl;
    return (0);
}
