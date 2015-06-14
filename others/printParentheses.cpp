//print all parantheses combinations
# include<iostream>
using namespace std;

     
 
void printParentheses(int pos, int n, int open, int close, char* str) {   
    if(close == n) {
        str[pos] = '\0';
        cout<<str<<endl;
    } else {
        if(open > close) {
            str[pos] = ')';
            printParentheses(pos+1, n, open, close+1, str);
        }
        if(open < n) {
            str[pos] = '(';
            printParentheses(pos+1, n, open+1, close, str);
        }
    }
}

void printParentheses(int n) {
    if (n>0) {
        char str[2*n+1];
        printParentheses(0, n, 0, 0, str);
    }
    
}

int main() {
    int n = 4;
    printParentheses(n);
    return 0;
}
