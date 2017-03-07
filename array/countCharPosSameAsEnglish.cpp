//to find number of characters at same position as in english alphabets
#include<bits/stdc++.h>
using namespace std;

int countCharPosSameAsEnglish(string str) {
    int result = 0;
    for (int i = 0 ; i < str.size(); i++)
        if (i == (str[i] - 'a') || i == (str[i] - 'A'))
            result++;
    return result;
}

int main() {
    string str = "AbgdeF";
    cout<<countCharPosSameAsEnglish(str)<<endl;
    return 0;
}
