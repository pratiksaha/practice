//to build the smallest number by removing n digits from a given number and not changing the order of input digits
#include<iostream>
#include<string>
using namespace std;

void buildSmallestNo(string str, int n, string* res) {
    if (str.length() <= n) //append nothing to res if there are more chars to remove than str length
        return;
    if (n == 0) { //append everything to res if there are 0 chars to remove from str
        res->append(str);
        return;
    }
    int minIdx = 0;
    for (int i=1; i<=n ; i++)
        if (str[i] < str[minIdx])
            minIdx = i;
    res->push_back(str[minIdx]);
    buildSmallestNo(str.substr(minIdx+1, str.length()-minIdx), n-minIdx, res);
}

string buildSmallestNo(string str, int n) {
    string res = "";
    buildSmallestNo(str, n, &res);
    return res;
}

int main() {
    string str = "1211981";
    int n = 2;
    cout<<"Smallest no formed from "<<str<<" by removing "<<n<<" chars is "<<buildSmallestNo(str, n)<<endl;
    return 0;
}
