//Anagram substring search
#include<iostream>
#include<cstring>
using namespace std;
#define MAX 256 //Considering 256 ASCII chars

bool isEqual(char A[], char B[]){//Comparison done in O(1) time
    for(int i=0; i<MAX; i++)
        if (A[i] != B[i])
            return false;
    return true;
}

void searchAnagram(char *pat, char *txt) {
    int M = strlen(pat);
    int N = strlen(txt);
    char countP[MAX] = {0};//count of all characters of pattern O(1) space
    char countTW[MAX] = {0};//count of current window of text O(1) space
    int i;
    for (i=0; i<M; i++) {
        countP[pat[i]]++;
        countTW[txt[i]]++;
    }
    for (int i = M; i < N; i++) {    
        if (isEqual(countP, countTW))//Compare counts of current window of text with counts of pattern[]
            cout<<"Anagram pattern found at index "<<(i - M)<<endl;
        countTW[txt[i]]++;//Add current character to current window   
        countTW[txt[i-M]]--;//Remove the first character of previous window
    }   
    if (isEqual(countP, countTW))//check the last window in text explicitly
        cout<<"Anagram pattern found at index "<<(N-M)<<endl;
}

int main() {
    char txt[] = "BACDGABCDA";
    char pat[] = "ABCD";
    searchAnagram(pat, txt);
    return 0;
}
