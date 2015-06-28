//check anagrams
#include<iostream>
using namespace std;
#define CHARSIZE 256

bool checkAnagram(char *str1, char *str2) {
    int count1[CHARSIZE] = {0};
    int count2[CHARSIZE] = {0};
    int i;
    for (i=0; str1[i] && str2[i]; i++) {
        count1[str1[i]]++;
        count2[str2[i]]++;
    }
    if (str1[i] || str2[i])
      return false; //strings are of unequal length
    for (i=0; i<CHARSIZE; i++)
        if (count1[i] != count2[i])
            return false; //mismatch in freq of chars
    return true;
}

int main() {
    char str1[] = "pratiksaha";
    char str2[] = "sahapratik";
    char str3[] = "sahspratix";
    cout<<str1<<" & "<<str2<<(checkAnagram(str1, str2)?" are":" are not")<<" anagrams of each other\n";
    cout<<str1<<" & "<<str3<<(checkAnagram(str1, str3)?" are":" are not")<<" anagrams of each other\n";
    return 0;
}
