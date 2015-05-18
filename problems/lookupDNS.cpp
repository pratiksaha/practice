//DNS lookup
//Using features of C++ Standard (2011) Compile using g++ -std=c++11
#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

string forwardLookup(unordered_map<string, string> hash, string key) {
    unordered_map<string, string>::iterator it;
    it = hash.find(key);
    if (it == hash.end())
        return "";
    else
        return it->second;
}

string reverseLookup(unordered_map<string, string> hash, string key) {
    unordered_map<string, string>::iterator it;
    it = hash.find(key);
    if (it == hash.end())
        return "";
    else
        return it->second;
}

int main () {
    int n = 3;
    string urls[] = {"www.abc.com", "www.xyz.com", "www.mn.com"};
    string ips[] = {"1.2.3.4", "6.7.8.9", "5.0.0.5"};
    unordered_map<string, string> fhash;
    unordered_map<string, string> rhash;
    for (int i=0; i<n; i++) {
        fhash.insert(make_pair(urls[i], ips[i]));
        rhash.insert(make_pair(ips[i], urls[i]));
    }
    cout<<"Forward lookup : www.mn.com -> "<<forwardLookup(fhash, "www.mn.com")<<endl;
    cout<<"Forward lookup : www.lmno.com -> "<<forwardLookup(fhash, "www.lmno.com")<<endl;
    cout<<"Reverse lookup : 5.0.0.5 -> "<<reverseLookup(rhash, "5.0.0.5")<<endl;
    cout<<"Reverse lookup : 5.5.5.5 -> "<<reverseLookup(rhash, "5.5.5.5")<<endl;
    return 0;
}
