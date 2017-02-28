//to print all ways to to break the given string in bracket form
#include<bits/stdc++.h>
using namespace std;
 
void allWaysToBracket(string str, int index, string out) {
    if (index == str.length())
        cout<<out<<endl;
    for (int i = index; i < str.length(); i ++)
        allWaysToBracket(str, i + 1, out + "(" + str.substr(index, i+1-index) + ")" );
}

int main() {
    string str = "abcd";
    allWaysToBracket(str, 0, "");
    return 0;
}
