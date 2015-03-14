//evaluate an expression of the form (2+3)*4 ony single digit nos supported
#include<iostream>
#include<string>
#include<stack>
#include<cassert>
#include<cmath>
#include<cctype>
using namespace std;

bool isNumber(char ch) { //check for a number
    return (ch>='0' && ch<='9');
}

int precedence(char ch) { //return precedence of operators
    switch (ch) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
    }
    return 0;
}

bool checkChar(char ch) { //check for valid chars
    return isNumber(ch) || precedence(ch) || (ch == '(') || (ch == ')');
}

string reversePolish(string in) { //convert infix to postfix expression
    stack<char> s;
    int n = in.size();
    string out;
    for (int i=0; i<n; i++) {
        char ch = in[i];
        assert(checkChar(ch)); //check for valid chars
        if (isNumber(ch)) {
            out.push_back(ch);
        } else if (ch == '(') {
            s.push(ch);
        } else if (ch == ')') {
            while( !s.empty() && s.top() != '(') {
                out.push_back(s.top());
                s.pop();
            }
            assert(!s.empty() && s.top() == '('); //check for malformed expression
            s.pop();
        } else {
            while(!s.empty() && precedence(ch) <= precedence(s.top())) {
                out.push_back(s.top());
                s.pop();   
            }
            s.push(ch);
        }
    }
    while(!s.empty()) {
        out.push_back(s.top());
        s.pop();
    }
    return out;
}

int evaluate(string in) { //evaluate postfix expression
    stack<int> s;
    int n = in.size();
    for (int i=0; i<n; i++) {
        char ch = in[i];
        if (isdigit(ch)) {
            s.push(ch-'0');
        } else {
            int v1 = s.top();
            s.pop();
            int v2 = s.top();
            s.pop();
            switch(ch) {
                case '+':
                    s.push(v2+v1);
                    break;
                case '-':
                    s.push(v2-v1);
                    break;
                case '*':
                    s.push(v2*v1);
                    break;
                case '/':
                    s.push(v2/v1);
                    break;
                case '^':
                    s.push(pow(v2,v1));
                    break;
            }
        }
    }
    int val = s.top();
    s.pop();
    assert(s.empty()); //check for more than one digit nos
    return val;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        cout<<"Exactly one expression expected"<<endl;
    } else {
        string inp = argv[1];
        string post = reversePolish(inp);
        cout<<"Input Expression : "<<inp<<endl;
        cout<<"Reverse Polish Notation : "<<post<<endl;
        int value = evaluate(post);
        cout<<"Value : "<<value<<endl;
    }
    return 0;
}
