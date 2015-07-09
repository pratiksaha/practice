//remove adjacent duplicates
#include<iostream>
#include<cstring>
using namespace std;

char* removeAdjDup(char *str, char *last) {
    if (str[0] == '\0' || str[1] == '\0') { //if length of string is 1 or 0
        return str;
    } else if (str[0] == str[1]) { //remove leftmost same chars and recur
        *last = str[0];
        while (str[1] && str[0] == str[1])
            str++;
        str++;
        return removeAdjDup(str, last);
    } else { //first char is different from its adjacent
        char* rem = removeAdjDup(str+1, last);
        if (rem[0] && rem[0] == str[0]) { //first char of the rem matches with first char of str
            *last = str[0];
            return (rem+1);
        } else if (rem[0] == '\0' && *last == str[0]) { //rem is empty and last is same of first char of str
            return rem;
        } else { //first two chars does not match
            rem--;
            rem[0] = str[0];
            return rem;
        }
    }
}
 
char *removeAdjDup(char *str) {
    char last = '\0';
    return removeAdjDup(str, &last);
}

int main() {
    char str1[] = "pratiksahaaaapppa";
    cout<<str1<<" => ";
    cout<<removeAdjDup(str1)<<endl;
    char str2[] = "azxxxzy";
    cout<<str2<<" => ";
    cout<<removeAdjDup(str2)<<endl;
    char str3[] = "caaabbbaac";
    cout<<str3<<" => ";
    cout<<removeAdjDup(str3)<<endl;
    char str4[] = "gghhg";
    cout<<str4<<" => ";
    cout<<removeAdjDup(str4)<<endl;
    char str5[] = "aaaacddddcappp";
    cout<<str5<<" => ";
    cout<<removeAdjDup(str5)<<endl;
    char str6[] = "aaaaaaaaaa";
    cout<<str6<<" => ";
    cout<<removeAdjDup(str6)<<endl;
    char str7[] = "qpaaaaadaaaaadprq";
    cout<<str7<<" => ";
    cout<<removeAdjDup(str7)<<endl;
    char str8[] = "acaaabbbacdddd";
    cout<<str8<<" => ";
    cout<<removeAdjDup(str8)<<endl;
    char str9[] = "acbbcddc";
    cout<<str9<<" => ";
    cout<<removeAdjDup(str9)<<endl;
    return 0;
}
