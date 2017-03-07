//to print all distinct substrings of size 2 and their counts
//Using features of C++ Standard (2011) Compile using g++ -std=c++11
#include<bits/stdc++.h>
#include<boost/functional/hash.hpp>
using namespace std;
using namespace boost;

struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1,T2> &p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);
        size_t seed = 0;
        hash_combine(seed, h1);
        hash_combine(seed, h2);
        return seed;  
    }
};

void freqDistinctSubstringsLength2(string str) {
    unordered_map<pair<char,char>, int, pair_hash> dPairs;
    for (int i=0; i<str.size()-1; i++)
        dPairs[make_pair(str[i], str[i+1])]++;
    cout<<"Distinct sub-strings with counts :\n";
    for (unordered_map<pair<char,char>, int, pair_hash>::iterator it=dPairs.begin(); it!=dPairs.end(); it++)
        cout<<"( "<<it->first.first<<" , "<<it->first.second<<" ) => "<<it->second<<endl;
}

int main() {
    freqDistinctSubstringsLength2("abcacdcacabacaassddssklac");
    return 0;
}
