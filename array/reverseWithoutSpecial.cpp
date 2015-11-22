//to reverse a string without special characters
#include<iostream>
#include<cstring>
using namespace std;

bool isAlphabet(char x) {
    return ((x>='A'&& x<='Z')||(x>='a'&&x<='z'));
}
 
void reverseWithoutSpecial(char str[]) {
    int l=0, r = strlen(str)-1;
    while (l < r) {
        if (!isAlphabet(str[l])) {
            l++; 
        } else if(!isAlphabet(str[r])) {
            r--;
 
        } else {
            swap(str[l], str[r]);
            l++;
            r--;
        }
    }
}

int main() {
    char str[] = "a!!!b.c.d,e'f,ghi";
    cout<<"Input string: "<<str<<endl;
    reverseWithoutSpecial(str);
    cout<<"Output string: "<<str<<endl;
    return 0;
}
