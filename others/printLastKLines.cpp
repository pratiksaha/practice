//to print the last k lines.
#include<iostream>
#include<cstring>
using namespace std;
#define DELIM '\n'

void printLastKLines(char *str, int n) {
    if (n>0) { //no need to print if n<=0
        int count = 0;
        char *target_pos = NULL;
        target_pos = strrchr(str, DELIM); //http://www.cplusplus.com/reference/cstring/strrchr/
        if (target_pos) {
            while (count < n) {
                while (str<target_pos && *target_pos != DELIM)
                    target_pos--;
                if (*target_pos == DELIM)
                    target_pos--, count++;
                else
                    break;
            }
            if (str < target_pos)
                target_pos += 2;
            cout<<target_pos;
        } else {
            cout<<"No delimiter found";
        }
        cout<<endl;
    }
}

int main() {
    char *str1 = "str1\nstr2\nstr3\nstr4\nstr5\nstr6\nstr7\nstr8\nstr9\nstr10\nstr11\nstr12\nstr13\nstr14\nstr15\nstr16\nstr17\nstr18\nstr19\nstr20\nstr21\nstr22\nstr23\nstr24\nstr25";
    char *str2 = "str1\nstr2\nstr3\nstr4\nstr5\nstr6\nstr7";
    char *str3 = "\n";
    char *str4 = "";
    printLastKLines(str1, 5);
    cout<<"-----------------\n";
    printLastKLines(str2, 10);
    cout<<"-----------------\n";
    printLastKLines(str3, 10);
    cout<<"-----------------\n";
    printLastKLines(str4, 10);
    cout<<"-----------------\n";
    return 0;
}
