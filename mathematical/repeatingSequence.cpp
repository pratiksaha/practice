//to find repeating sequence in a fraction
//Using features of C++ Standard (2011) Compile using g++ -std=c++11
#include<bits/stdc++.h>
using namespace std;

string repeatingSequence(int numr, int denr) {
    string res;
    unordered_map<int, int> hash;
    int rem = numr%denr;
    while ((rem!=0) && (hash.find(rem) == hash.end())) {
        hash[rem] = res.length();
        rem = rem*10;
        int res_part = rem / denr;
        res += to_string(res_part);
        rem = rem % denr;
    }
    return (rem == 0)? "" : res.substr(hash[rem]);
}

int main() {
    int numr = 50, denr = 22;
    string res = repeatingSequence(numr, denr);
    cout<<"In "<<numr<<"/"<<denr;
    if (res == "")
        cout<<" no recurring sequence"<<endl;
    else
        cout<<" recurring sequence is "<<res<<endl;
    return 0;
}
