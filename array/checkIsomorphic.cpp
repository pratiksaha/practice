//to check if two strings are isomorphic
#include<iostream>
#include<cstring>
#include<string>
using namespace std;
#define MAX_CHARS 256

bool checkIsomorphic(string str1, string str2) {
    int m = str1.length(), n = str2.length();
    if (m != n)
        return false;
    bool marked[MAX_CHARS] = {false};
    int map[MAX_CHARS];
    memset(map, -1, sizeof(map));
    for (int i = 0; i < n; i++) {
        if (map[str1[i]] == -1) {
            if (marked[str2[i]] == true)
                return false;
            marked[str2[i]] = true;
            map[str1[i]] = str2[i];
        } else if (map[str1[i]] != str2[i]) {
            return false;
        }
    }
    return true;
}

int main() {
   cout<<checkIsomorphic("aab", "xxy")<<endl;
   cout<<checkIsomorphic("aab", "xyz")<<endl;
   return 0;
}
