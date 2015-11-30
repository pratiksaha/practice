//to find the max lebgth of balanced parantheses
#include<iostream>
#include<string>
#include<stack>
using namespace std;
 
int maxLenBalanced(string str) {
    int n = str.length();
    stack<int> stk;
    stk.push(-1);
    int result = 0;
    for (int i=0; i<n; i++) {
        if (str[i] == '(') {
            stk.push(i);
        } else {
            stk.pop();
            if (!stk.empty())
                result = max(result, i - stk.top());
            else
                stk.push(i);
        }
    }
 
    return result;
}

int main() {
    string str = "((()()";
    cout<<"Max Length Balanced Parantheses for "<<str<<" is "<<maxLenBalanced(str)<<endl;
    str = "()(()))))";
    cout<<"Max Length Balanced Parantheses for "<<str<<" is "<<maxLenBalanced(str)<<endl;
    return 0;
}
