//Longest Substring Without Repeating Characters
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

#define MAX 256

int longestUniqueSubsttrDP(char *str) {
    int n = strlen(str);
    int *visited = new int[MAX];//-1 indicates char is not visited yet, others denote the pos of last occurence
    
    int i, j; 
    for (i = 0; i < MAX;  i++)
        visited[i] = -1;
 
    int max_len = 1;
    int cur_len = 1;
    int max_beg = 0;
    int cur_beg = 0;  
    visited[str[0]] = 0;
 
    int prev_index; 
    for (i=1; i<n; i++) {
        prev_index =  visited[str[i]];        
        if ( (prev_index == -1) || (i-cur_len > prev_index) ) {//if currrent char not visited yet or previous instance is not part of the current substring
            cur_len++;
        } else {//if previous instance of current char is part of the current substring
            if (cur_len>max_len) {
                max_len = cur_len;
                max_beg = cur_beg;
            }
            cur_len = i - prev_index;
            cur_beg = i - cur_len + 1;
        }
 
        visited[str[i]] = i;
    }

    if (cur_len > max_len) {//to handle the case when the complete input string consists of unique chars
        max_len = cur_len;
        max_beg = cur_beg;
    }
    delete[] visited;
 
    char *res = new char[max_len+1];
    res[max_len] = '\0';
    for(i=max_beg, j=0; j<max_len; i++, j++)
        res[j] = str[i];
    cout<<"Input String : "<<str<<endl;
    cout<<"Length of longest unique substring is "<<max_len<<" which is : "<<res<<endl;
    delete[] res;
}

int main() {
    char a[] = "ABDEFGABEF";
    longestUniqueSubsttrDP(a);
    char b[] = "TESTFORTESTS";
    longestUniqueSubsttrDP(b);
    char c[] = "ABDEFGHIJK";
    longestUniqueSubsttrDP(c);
    char d[] = "PRATIKSAHA";
    longestUniqueSubsttrDP(d);
    char e[] = "ABABDEFG";
    longestUniqueSubsttrDP(e);
    return 0;
}
