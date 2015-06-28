//to find the longest substring with k unique characters in a given string
#include<iostream>
#include<cstring>
#include<string>
#define CHARSIZE 256
using namespace std;

bool isValid(int count[], int k) {
    int val = 0;
    for (int i=0; i<CHARSIZE; i++)
        if (count[i] > 0)
            val++;
    return (k >= val); //true if k is greater than or equal to val
}

void longestSubStringKUnique(string s, int k) {
    int count[CHARSIZE];
    memset(count, 0, sizeof(count));
    int u = 0; //no of unique chars
    for (int i=0; i<s.length(); i++) {
        if (count[s[i]]==0)
            u++;
        count[s[i]]++;
    }
    if (u<k) {
        cout<<"Not enough unique characters\n";
    } else {
        int curr_start = 0, curr_end = 0, max_window_size = 1, max_window_start = 0;
        memset(count, 0, sizeof(count));
        count[s[0]]++;
        for (int i=1; i<s.length(); i++) {
            count[s[i]]++;
            curr_end++; 
            while (!isValid(count, k)) { //remove from left side ff there are more than k unique character in current window
                count[s[curr_start]]--;
                curr_start++;
            }
            if (curr_end-curr_start+1 > max_window_size) { //update the max window size if required
                max_window_size = curr_end-curr_start+1;
                max_window_start = curr_start;
            }
        }
        cout<<"Max sustring with "<<k<<" unique chars is : "<<s.substr(max_window_start, max_window_size)<<" with length "<<max_window_size<<endl;
    }
}

int main() {
    string s = "aabacbebebe";
    int k = 3;
    longestSubStringKUnique(s, k);
    return 0;
}
