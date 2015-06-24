//string
#include<iostream>
#include<cstring>
#include<cctype>
#include<cstdlib>
using namespace std;
#define CHARSIZE 256

enum State {
    IN,
    OUT
};

int countWords(char *str) { //count words in a string
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

void removeSpaces(char *str) { //remove spaces from a string
    int count = 0;
    for (int i=0; str[i]; i++)
        if (str[i] != ' ')
            str[count++] = str[i];
    str[count] = '\0';
}

void reverse(char *str) { //reverse a string
    int i =0;
    int j = strlen(str) - 1;
    while (i < j)
        swap(str[i++], str[j--]);
}

void printReverse(char *str) { //print a string in reverse order
    if (*str) {
       printReverse(str+1);
       cout<<*str;
    }
}

void convertLower(char *str) { //convert a string to lower case
    while (*str) {
        *str = tolower(*str);
        str++;
    }
}

char maxOccuringChar(char *str) { //get the max occuring char in a string
    int *hash = (int *)calloc(sizeof(int), CHARSIZE);
    for (int i=0; *(str+i); i++)
        hash[*(str+i)]++;
    int maxIdx = 0;
    for (int i=0; i<CHARSIZE; i++)
        if (hash[i] > hash[maxIdx])
            maxIdx = i;
    free(hash);
    return maxIdx;
}

void removeDirtyChars(char *str, char *mask) { //remove dirty chars in a string
    int *hash = (int *)calloc(sizeof(int), CHARSIZE);
    for (int i=0; *(mask+i); i++)
        hash[*(mask+i)]++;
    int ipIdx = 0, resIdx = 0;
    while (*(str+ipIdx)) {
        if(hash[*(str+ipIdx)] == 0) {
            *(str+resIdx) = *(str+ipIdx);
            resIdx++;
        }
        ipIdx++;
    }
    *(str+resIdx) = '\0';
}

void printDuplicates(char *str) { //print duplicates in a string
    int *hash = (int *)calloc(sizeof(int), CHARSIZE);
    for (int i=0; *(str+i); i++)
        hash[*(str+i)]++;
    cout<<"Duplicates in "<<str<<" :";
    for (int i=0; i<CHARSIZE; i++)
        if (hash[i] > 1)
            cout<<" "<<(char)i<<":"<<hash[i];
    cout<<endl;
    free(hash);
}

void removeDuplicates(char *str) { //remove duplicates in a string
    int *hash = (int *)calloc(sizeof(int), CHARSIZE);
    int ipIdx = 0, resIdx = 0;
    while (*(str+ipIdx)) {
        if (hash[*(str+ipIdx)] == 0) {
            hash[*(str+ipIdx)] = 1;
            *(str+resIdx) = *(str+ipIdx);
            resIdx++;
        }
        ipIdx++;
    }
    *(str+resIdx) = '\0';
}

void divideString(char *str, int k) { //divide str into k equal parts
    int n = strlen(str);
    cout<<"Dividing "<<str<<" of size "<<n<<" into "<<k<<"equal parts\n";
    if(n%k != 0) {
        cout<<""<<n<<" is not divisible by "<<k<<endl;
    } else {
        int part = n/k;
        for(int i=0; i<n; i++) {
            if (i%part == 0 && i !=0)
                cout<<endl;
            cout<<*(str+i);
        }
        cout<<endl;
    }
}

void printContainingAll(char *word, char *list[], int n)  { //print those strings from list that contain all chars of word
    int m = strlen(word);
    int *hash = (int *)calloc(sizeof(int), CHARSIZE);
    for (int i=0; *(word+i); i++)
        hash[*(word+i)] = 1;
    cout<<"Word(s) in list {";
    for(int i=0; i<n; i++)
        cout<<" "<<list[i];
    cout<<"} that contains all chars of "<<word<<" :";
    for (int i=0; i<n; i++) {
        int count = 0;
        for (int j=0; *(list[i]+j); j++) {
            if (hash[*(list[i]+j)]) {
                count++;
                hash[*(list[i]+j)] = 0;
            }
        }
        if (count == m)
            cout<<" "<<list[i];
        for (int j=0; *(word+j); j++)
            hash[*(word+j)] = 1;
    }
    cout<<endl;
}

int main() {
    char str[] = "  My name is  Pra  tik Sa ha    ";
    char mask[] = "apstkh";
    char *list[] = {"aneiypfjhsrkfm", "yiuqyroqr", "azxbcv"};
    cout<<"Given string : "<<str<<endl;
    cout<<"No of words : "<<countWords(str)<<endl;
    removeSpaces(str);
    cout<<"String removed of spaces : "<<str<<endl;
    reverse(str);
    cout<<"Reversed string "<<str<<endl;
    cout<<"Printing string "<<str<<" in reverse order ", printReverse(str), cout<<endl;
    convertLower(str);
    cout<<"Lower case string : "<<str<<endl;
    reverse(str);
    cout<<"Max occuring char in "<<str<<" is "<<maxOccuringChar(str)<<endl;
    removeDirtyChars(str, mask);
    cout<<"String removed of dirty chars "<<mask<<" : "<<str<<endl;
    printDuplicates(str);
    removeDuplicates(str);
    cout<<"String removed of duplicates : "<<str<<endl;
    divideString(str, 3);
    printContainingAll(str, list, 3);
    return 0;
}
