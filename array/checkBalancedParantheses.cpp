#include<iostream>
#include<stack>
using namespace std;

bool isMatchingPair(char c1, char c2) {
    if (c1 == '(' && c2 == ')')
        return true;
    else if (c1 == '{' && c2 == '}')
        return true;
    else if (c1 == '[' && c2 == ']')
        return true;
    else
        return false;
}

bool isBalanced(string exp) { //Time: O(n) Space: O(n) Works for all 3 brackets at a time
    int i = 0;
    int n = exp.length();
    stack<char> s;
    for(int i=0; i<n; i++) {
        char curr = exp[i];
        if(curr == '{' || curr == '(' || curr == '[') {
            s.push(curr);
        } else if(curr == '}' || curr == ')' || curr == ']') {
            if(s.empty()) {
                return false;
            } else {
                char curr_top = s.top();
                s.pop();
                if (!isMatchingPair(curr_top, curr))
                    return false;
            }
           
        }
    }
    if(s.empty())
        return true;
    else
        return false;
}

bool isBalancedDP(string exp) { //Time: O(n) Space: O(1) Works for only one type of parantheses (here "()")
    int curr_max = 0;
    int max_so_far = 0;
    int n = exp.length();
    for (int i = 0; i< n; i++) {
        if (exp[i] == '(') {
            curr_max++;
            if (curr_max > max_so_far) //update max if required
                max_so_far = curr_max;
        }
        else if (exp[i] == ')') {
            if (curr_max>0)
                curr_max--;
            else //malformed expression
                return false;
        }
    }
    if (curr_max != 0) //check for unbalanced
        return false;
    else
        return true;
}

int main() {
    string s1="{()}[]", s2="{()}[]]", s3="{(()}[]", s4="(())()", s5="(()))())", s6="((())()";
    cout<<"Expression "<<s1<<" is "<<(isBalanced(s1)?"Balanced":"Not Balanced")<<endl;
    cout<<"Expression "<<s2<<" is "<<(isBalanced(s2)?"Balanced":"Not Balanced")<<endl;
    cout<<"Expression "<<s3<<" is "<<(isBalanced(s3)?"Balanced":"Not Balanced")<<endl;
    cout<<"Expression "<<s4<<" is "<<(isBalancedDP(s4)?"Balanced":"Not Balanced")<<endl;
    cout<<"Expression "<<s5<<" is "<<(isBalancedDP(s5)?"Balanced":"Not Balanced")<<endl;
    cout<<"Expression "<<s6<<" is "<<(isBalancedDP(s6)?"Balanced":"Not Balanced")<<endl;
    return 0;
}
