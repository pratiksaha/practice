//print all premutations of a string with repeatations
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

void repeatedPermutations(char *str, char *data, int last, int index) {
    int len = strlen(str);
    for (int i=0; i<len; i++) {
        data[index] = str[i] ;
        if (index == last)
            cout<<data<<endl;
        else
            repeatedPermutations(str, data, last, index+1);
    }
}

void repeatedPermutations(char *str) {
    int len = strlen(str) ;
    char *data = (char *)malloc(sizeof(char)*(len + 1)) ;
    data[len] = '\0';
    sort(str, str+len);
    repeatedPermutations(str, data, len-1, 0);
    free(data);
}

int main() {
    char str[] = "BCA";
    repeatedPermutations(str);
    return 0;
}
