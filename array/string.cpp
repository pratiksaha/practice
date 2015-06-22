//string
#include<iostream>
#include<cstring>
using namespace std;

enum State {
    IN,
    OUT
};

int countWords(char *str) {
    State state = OUT;
    int wc = 0;
    while (*str) {
        if (*str == ' ' || *str == '\n' || *str == '\t') {
            state = OUT;
        } else if (state == OUT) {
            state = IN;
            wc++;
        }
        str++;
    }
    return wc;
}

void removeSpaces(char *str) {
    int count = 0;
    for (int i=0; str[i]; i++)
        if (str[i] != ' ')
            str[count++] = str[i];
    str[count] = '\0';
}

void reverse(char *str) {
    int i =0;
    int j = strlen(str) - 1;
    while (i < j)
        swap(str[i++], str[j--]);
}

void printReverse(char *str) {
    if (*str) {
       printReverse(str+1);
       cout<<*str;
    }
}

int main() {
    char str[] = "  Pra  tik Sa ha    ";
    cout<<str<<endl;
    cout<<"No of words : "<<countWords(str)<<endl;
    removeSpaces(str);
    cout<<str<<endl;
    reverse(str);
    cout<<str<<endl;
    printReverse(str), cout<<endl;
    return 0;
}
