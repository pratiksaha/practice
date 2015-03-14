//to reverse words of a string
#include<iostream>
#include<cstdlib>
using namespace std;

void reverse(char *begin, char *end) {
    while (begin < end) {
        swap(*begin, *end);
        begin++;
        end--;
    }
}

void reverseWords(char *s) {
    char *word_begin = NULL;
    char *temp = s;
    while (*temp) { //reverse individual words
        if ((word_begin==NULL)&&(*temp!=' ')) { //if beginning of string is white space
            word_begin=temp;
        }
        if(word_begin && ((*(temp+1) == ' ') || (*(temp+1) == '\0'))) {
            reverse(word_begin, temp);
            word_begin = NULL;
        }
        temp++;
    }
    reverse(s, temp-1);//finally reverse the whole string
}

int main() {
    char s[] = "saha pratik is name my";
    cout<<"Input :"<<s<<endl;
    reverseWords(s);
    cout<<"Output :"<<s<<endl;
    return 0;
}
