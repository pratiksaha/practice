//to print all anagrams together lexicographically
//TODO:do hashing it lexicographically
#include<bits/stdc++.h>
using namespace std;

bool isValid(char c) {
    return (c>='a' && c<='z');
}
string getHash(string val) {
    int hash[26] = {0};
    int n = val.size();
    for (int i=0; i<n; i++) {
        if (isValid(val[i])) {
            hash[val[i]-'a']++;
        }
    }
    string ret;
    for (int i=0; i<25; i++) {
        ret.push_back(i+'a');
        ret.push_back(hash[i]+'0');
    }
    return ret;
}

void printAnagramsLexicographically(vector<string> input) {
    map<string, vector<string> > hash;
    for (vector<string>::iterator it=input.begin(); it!=input.end(); it++) {
        string key = getHash(*it);
        map<string, vector<string> > :: iterator jt;
        jt = hash.find(key);
        if (jt==hash.end()) {
            vector<string> temp;
            temp.push_back(*it);
            hash.insert(make_pair(key, temp));
        } else {
            jt->second.push_back(*it);
        }
    }
    map<string, vector<string> > ::iterator it;
    it = hash.end();
    do {
        it--;
        vector<string> curr = it->second;
        sort(curr.begin(), curr.end());
        bool first = true;
        for (vector<string>::iterator jt=curr.begin(); jt!=curr.end(); jt++) {
            if (first) {
                cout<<*jt;
                first = false;
            } else {
                cout<<","<<*jt;
            }
        }
        cout<<endl;    
    } while (it != hash.begin());
}

int main() {
    vector<string> input;
    string line;
    while(getline(cin, line))
        input.push_back(line);
    printAnagramsLexicographically(input);
    return 0;
}
