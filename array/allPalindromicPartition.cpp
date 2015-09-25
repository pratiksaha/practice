//to print all palindromic partitions of a given string
#include<iostream>
#include<string>
#include<vector>
using namespace std;

bool isPalindrome(string str, int low, int high) {
    while (low < high) {
        if (str[low] != str[high])
            return false;
        low++;
        high--;
    }
    return true;
}
 
void allPalindromicPartition(vector<vector<string> >&allPart, vector<string> &currPart, int start, int n, string str) {
    if (start >= n) {
        allPart.push_back(currPart);
    } else {
        for (int i=start; i<n; i++) {
            if (isPalindrome(str, start, i)) {
                currPart.push_back(str.substr(start, i-start+1));
                allPalindromicPartition(allPart, currPart, i+1, n, str);
                currPart.pop_back();
            }
        }
    }
}

void allPalindromicPartition(string str) {
    int n = str.length();
    vector<vector<string> > allPart;
    vector<string> currPart; 
    allPalindromicPartition(allPart, currPart, 0, n, str);
    for (int i=0; i< allPart.size(); i++ ) {
        for (int j=0; j<allPart[i].size(); j++)
            cout<<" "<<allPart[i][j];
        cout<<endl;
    }
}

int main() {
    string str = "sahap";
    allPalindromicPartition(str);
    return 0;
}
