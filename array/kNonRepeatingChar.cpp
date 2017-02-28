//to find k th non repeating character in a string
#include<bits/stdc++.h>
using namespace std;
#define MAX_CHAR 256
 
int kNonRepeatingChar(string str, int k) {
    int n = str.length();
    int count[MAX_CHAR];
    int index[MAX_CHAR];
    for (int i = 0; i < MAX_CHAR; i++) {
        count[i] = 0;
        index[i] = n;
    }
    for (int i = 0; i < n; i++) {
        char x = str[i];
        ++count[x];
        if (count[x] == 1)
            index[x] = i;
        if (count[x] == 2)
            index[x] = n;
    }
    sort(index, index+MAX_CHAR);
    return (index[k-1] != n)? index[k-1] : -1;
}
 
int main() {
    string str = "geeksforgeeks";
    int k = 3;
    int res = kNonRepeatingChar(str, k);
    if (res == -1)
        cout<<"There are less than "<<k<<" non-repeating characters\n";
    else
        cout<<k<<"th non-repeating character is "<<str[res]<<endl;
    return 0;
}
