//to find substring with equal number of 0's, 1's and 2's
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

int substringWithEqual012(string str) {
    int n = str.length();
    unordered_map<pair<int, int>, int, pair_hash> mp;
    mp[make_pair(0, 0)] = 1;
    int zc = 0, oc = 0, tc = 0;
    int res = 0;
    for (int i = 0; i < n; i++) {
        if (str[i] == '0') zc++;
        else if (str[i] == '1') oc++;
        else tc++;
        pair<int, int> tmp = make_pair(zc - oc, zc - tc);
        res = res + mp[tmp];
        mp[tmp]++;
    }
    return res;
}

int main() {
    cout<<substringWithEqual012("0102010")<<endl;
    return 0;
}
