//to find maximum np possible by doing at-most K swap
#include<bits/stdc++.h>
using namespace std;
 
void maxNumAtMostKSwaps(string str, int k, string& max) {
    if(k == 0)
        return;
    int n = str.length();
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (str[i] < str[j]) {
                swap(str[i], str[j]);
                if (str.compare(max) > 0)
                    max = str;
                maxNumAtMostKSwaps(str, k - 1, max);
                swap(str[i], str[j]);
            }
        }
    }
}
 
int main() {
    string str = "129814999";
    int k = 4;
    string max = str;
    maxNumAtMostKSwaps(str, k, max);
    cout<<"max no from "<<str<<" formed by doing at most "<<k<<" swaps is "<<max<<endl;
    return 0;
}
