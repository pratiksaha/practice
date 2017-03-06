//to print all possible expression which evaluate to target
#include<bits/stdc++.h>
using namespace std;

void printExpressions(vector<string>& res, string curExp, string input, int target, int pos, int curVal, int last) {
    if (pos == input.length()) {
        if (curVal == target)
            res.push_back(curExp);
        return;
    }
    for (int i = pos; i < input.length(); i++) {
        if (i != pos && input[pos] == '0')
            break;
        string part = input.substr(pos, i + 1 - pos);
        int cur = atoi(part.c_str());
        if (pos == 0) {
            printExpressions(res, curExp + part, input, target, i + 1, cur, cur);
        } else {
            printExpressions(res, curExp + "+" + part, input, target, i + 1, curVal + cur, cur);
            printExpressions(res, curExp + "-" + part, input, target, i + 1, curVal - cur, -cur);
            printExpressions(res, curExp + "*" + part, input, target, i + 1, curVal - last + last * cur, last * cur);
        }
    }
}

vector<string> printExpressions(string input, int target) {
    vector<string> res;
    printExpressions(res, "", input, target, 0, 0, 0);
    return res;
}

void printResult(string input, int target, vector<string> res) {
    cout<<target<<" can be reached from "<<input<<" by :";
    for (int i = 0; i < res.size(); i++)
        cout<<" "<<res[i];
    cout<<endl;
}

int main() {
    string input = "123";
    int target = 6;
    vector<string> res = printExpressions(input, target);
    printResult(input, target, res);
    input = "125";
    target = 7;
    res = printExpressions(input, target);
    printResult(input, target, res);
    return 0;
}
