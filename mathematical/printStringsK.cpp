//print all k length strings
#include<iostream>
#include<string>
using namespace std;

void printStringsK(string str, string prefix, int n, int k) {
    if (k==0) {
        cout<<prefix<<endl;
    } else {
        for (int i=0; i<n; i++) {
            string newPrefix = prefix + str[i];
            printStringsK(str, newPrefix, n, k-1);
        }
    }
}

int main() {
    string str = "ABC";
    int k = 3;
    printStringsK(str, "", str.length(), k);
    return 0;
}
