//to find all strings formed from a given number where each digit maps to given characters
//Using features of C++ Standard (2011) Compile using g++ -std=c++11
#include<bits/stdc++.h>
using namespace std;

vector<string> findCombinationsStringsFromCharDigitMap(vector<int> input, vector<char> table[]) {
    vector<string> out, temp;
    unordered_map<int, int> mp;
    int index = 0;
    for (vector<int>::iterator iti = input.begin(); iti != input.end(); iti++) {
        int d = *iti;
        if (mp.find(d) == mp.end())
            mp[d] = index;
        temp.clear();
        for (int i = 0; i < table[d - 1].size(); i++) {
            if (index == 0) {
                string s(1, table[d - 1].at(i));
                out.push_back(s);
            }
            if (index > 0) {
                for(vector<string>::iterator itj = out.begin(); itj != out.end(); itj++) {
                    string str = *itj;
                    string s(1, table[d - 1].at(i));
                    if(mp[d] != index)
                        s = str[mp[d]];
                    str = str + s;
                    temp.push_back(str);
                }
                if(mp[d] != index)
                    break;
            }
        }
        if(index > 0)
            out = temp;
        index++;
    }
    return out;
}
 
int main() {
    vector<char> table[] =
    {
        { 'A', 'B', 'C' },
        { 'D', 'E', 'F' },
        { 'G', 'H', 'I' },
        { 'J', 'K', 'L' },
        { 'M', 'N', 'O' },
        { 'P', 'Q', 'R' },
        { 'S', 'T', 'U' },
        { 'V', 'W', 'X' },
        { 'Y', 'Z' }
    };
    vector<int> input = { 1, 2, 1};
    vector<string> out = findCombinationsStringsFromCharDigitMap(input, table);
    for (vector<string>::iterator it = out.begin(); it != out.end(); it++)
        cout<<" "<<*it;
    cout<<endl;
    return 0;
}
