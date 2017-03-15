//to get max & min values of an expression
#include<bits/stdc++.h>
using namespace std;

bool isOperator(char op) {
    return (op == '+' || op == '*');
}

void minmaxValueOfExpression(string exp) {
    vector<int> num;
    vector<char> opr;
    string tmp = "";
    for (int i = 0; i < exp.length(); i++) {
        if (isOperator(exp[i])) {
            opr.push_back(exp[i]);
            num.push_back(atoi(tmp.c_str()));
            tmp = "";
        } else {
            tmp += exp[i];
        }
    }
    num.push_back(atoi(tmp.c_str()));
    int len = num.size();
    int minVal[len][len];
    int maxVal[len][len];
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            minVal[i][j] = INT_MAX;
            maxVal[i][j] = 0;
            if (i == j)
                minVal[i][j] = maxVal[i][j] = num[i];
        }
    }
    for (int L = 2; L <= len; L++) {
        for (int i = 0; i < len - L + 1; i++) {
            int j = i + L - 1;
            for (int k = i; k < j; k++) {
                int minTmp = 0, maxTmp = 0;
                if(opr[k] == '+') {
                    minTmp = minVal[i][k] + minVal[k + 1][j];
                    maxTmp = maxVal[i][k] + maxVal[k + 1][j];
                } else if(opr[k] == '*') {
                    minTmp = minVal[i][k] * minVal[k + 1][j];
                    maxTmp = maxVal[i][k] * maxVal[k + 1][j];
                }
                if (minTmp < minVal[i][j])
                    minVal[i][j] = minTmp;
                if (maxTmp > maxVal[i][j])
                    maxVal[i][j] = maxTmp;
            }
        }
    }
    cout<<"Minimum value : "<<minVal[0][len - 1]<<" & Maximum value : "<<maxVal[0][len - 1]<<endl;
}

int main() {
    string expression = "1+2*3+4*5";
    minmaxValueOfExpression(expression);
    return 0;
}
