//to check if given two strings are at distance one.
#include <bits/stdc++.h>
using namespace std;

bool checkEditDistanceOne(string s1, string s2) {
    int m = s1.length(), n = s2.length();
    if (abs(m - n) > 1)
        return false;
    int count = 0;
    int i = 0, j = 0;
    while (i < m && j < n) {
        if (s1[i] != s2[j]) { //curr chars do not match
            if (count == 1) //already one mismatch is found
                return false;
            if (m>n) {
                i++;
            } else if (m<n) {
                j++;
            } else {
                i++;
                j++;
            }
            count++;
        } else {
            i++;
            j++;
        }
    }
    if (i < m || j < n) //last char is extra in any string
        count++;
    return (count==1);
}

int main() {
   string s1 = "saha";
   string s2 = "shah";
   cout<<"For "<<s1<<" & "<<s2<<" edit distance "<<(checkEditDistanceOne(s1, s2)?"is":"is not")<<" one\n";
   return 0;
}
