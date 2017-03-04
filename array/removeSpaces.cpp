//to implement custom trim() function
#include<bits/stdc++.h>
using namespace std;

void removeSpaces(string &str) {
    int n = str.length();
    int i = 0, j = -1;
    bool spaceFound = false;
    while (++j < n && str[j] == ' ');
    while (j < n) {
        if (str[j] != ' ') {
            if ((str[j] == '.' || str[j] == ',' ||str[j] == '?') && i - 1 >= 0 && str[i - 1] == ' ')
                str[i - 1] = str[j++];
            else
                str[i++] = str[j++];
            spaceFound = false;
        } else if (str[j++] == ' ') {
            if (!spaceFound) {
                str[i++] = ' ';
                spaceFound = true;
            }
        }
    }
    if (i <= 1)
        str.erase(str.begin() + i, str.end());
    else
        str.erase(str.begin() + i - 1, str.end());
}

int main() {
    string str = "    mfbsdgksjgf nfsdjgjgd                  fmwe;wkg;lkgejo3t4u fljlgjsdglsg               ";
    cout<<str<<endl;
    removeSpaces(str);
    cout<<str<<endl;
    return 0;
}
