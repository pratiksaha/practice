//to find the maximum depth of nested parentheses
#include<iostream>
#include<string>
using namespace std;

int maxDepthNestedParantheses(string s) {
    int curr_max = 0;
    int max_so_far = 0;
    int n = s.length();
    for (int i = 0; i< n; i++) {
        if (s[i] == '(') {
            curr_max++;
            if (curr_max > max_so_far) //update max if required
                max_so_far = curr_max;
        }
        else if (s[i] == ')') {
            if (curr_max>0)
                curr_max--;
            else //malformed expression
                return -1;
        }
    }
    if (curr_max != 0) //check for unbalanced
        return -1;
    return max_so_far;
}

int main() {
    string s = "((())((())))";
    cout<<"For "<<s<<" max depth of nested parantheses: "<<maxDepthNestedParantheses(s)<<endl;
    return 0;
}
