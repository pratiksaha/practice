//to evaluate all possible values of a expression
#include<iostream>
#include<vector>
using namespace std;

int eval(int a, char op, int b) {
    if (op=='+')
        return a+b;
    if (op=='-')
        return a-b;
    if (op == '*')
        return a*b;
    if (op == '/')
        return a/b;
}

vector<int> allValueExpression(string expr, int low, int high) {
    vector<int> res;
    if (low == high) { //either a digit or operand if only one character
        res.push_back(expr[low] - '0');
        return res;
    } else if (low == (high-2)) { //middle one must be operator and corner ones must be operand if there are only three characters
        int num = eval(expr[low]-'0', expr[low+1],
                       expr[low+2]-'0');
 
        res.push_back(num);
        return res;
    } else {
        for (int i=low+1; i<=high; i+=2) {
            vector<int> l = allValueExpression(expr, low, i-1); //all possible values to the left of expr[i]   
            vector<int> r = allValueExpression(expr, i+1, high); //all possible values to the right of expr[i]
            for (int s1=0; s1<l.size(); s1++)
                for (int s2=0; s2<r.size(); s2++)
                    res.push_back(eval(l[s1], expr[i], r[s2])); //calculate value for every pair
        }
    }
    return res;
}

int main() {
    string expr = "1*2+3*4";
    int len = expr.length();
    vector<int> ans =allValueExpression(expr, 0, len-1);
    for (int i=0; i< ans.size(); i++)
        cout<<ans[i]<<endl;
    return 0;
}
