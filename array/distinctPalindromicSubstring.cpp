//to find all distinct palindrome substrings of a given string
//Using features of C++ Standard (2011) Compile using g++ -std=c++11
#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

void palindromicSubStrs(string s) {
    unordered_map<string, int> hash;
    int n = s.size();

    int result[2][n+1];
    s = "@" + s + "#"; //insert guards to iterate easily over s
 
    for (int j=0; j<=1; j++) {
        int rp = 0;
        result[j][0] = 0;
        int i = 1;
        while(i <= n) {
            while (s[i-rp-1] == s[i+j+rp])
                rp++; //incrementing the length of palindromic radius as and when we find valid palindrome
            result[j][i] = rp; //assigning the found palindromic length to odd/even length array
            int k = 1;
            while ((result[j][i-k] != rp-k) && (k<rp)) {
                result[j][i+k] = min(result[j][i-k], rp-k);
                k++;
            }
            rp =max(rp-k, 0);
            i = i+k;
        }
    }
    s = s.substr(1, n); //remove guards
    hash.insert(make_pair(string(1, s[0]), 1));
    for(int i=1; i<=n; i++) {
        for(int j=0; j<=1; j++) {
            for(int rp=result[j][i]; rp>0; rp--) { //put all obtained palindromes in a hash map to find only distinct palindromes
                hash.insert(make_pair(s.substr(i-rp-1, 2*rp+j),1));
            }
        }
        hash.insert(make_pair(string(1, s[i]), 1));
    }

    cout<<"For input string:"<<s<<" "<<hash.size()-1<<" distinct palindromic substrings are:";
    unordered_map<string, int>::iterator it;
    for(it=hash.begin(); it!=hash.end(); it++)
        cout<<" "<<(*it).first;
    cout<<endl;
}

int main() {
    string s = "abaaa";
    palindromicSubStrs(s);
    return 0;
}
