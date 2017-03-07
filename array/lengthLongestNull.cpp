//to find the maximum length that can be removed
//Using features of C++ Standard (2011) Compile using g++ -std=c++11
#include<bits/stdc++.h>
using namespace std;

int lengthLongestNull(string str) {
    vector<pair<char,int> > arr;
    arr.push_back({'@', -1});
    int maxlen = 0;
    for (int i = 0; i < str.length(); i++) {
        arr.push_back({str[i], i});
        while (arr.size()>=3 && arr[arr.size()-3].first=='1' && arr[arr.size()-2].first=='0' && arr[arr.size()-1].first=='0') {
            arr.pop_back();
            arr.pop_back();
            arr.pop_back();
        }
        int tmp = arr.back().second;
        maxlen = max(maxlen, i - tmp);
    }
    return maxlen;
}

int main() {
    cout<<lengthLongestNull("1011100000100")<<endl;
    return 0;
}
