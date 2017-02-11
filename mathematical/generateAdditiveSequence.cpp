//additive sequence
#include<bits/stdc++.h>
using namespace std;

bool isValid(string num) {
    if (num.size() > 1 && num[0] == '0')
        return false;
    else
        return true;
}

int val(string a, int pos) {
    if (pos >= a.length())
        return 0;
    else 
        return (a[pos] - '0');
}

string addString(string a, string b) {
    string sum = "";
    int i = a.length() - 1;
    int j = b.length() - 1;
    int carry = 0;
    while (i >= 0 || j >= 0) {
        int t = val(a, i) + val(b, j) + carry;
        sum += (t % 10 + '0');
        carry = t / 10;
        i--;
        j--;
    }
    if (carry)
        sum += (carry + '0');
    reverse(sum.begin(), sum.end());
    return sum;
}

bool checkAddition(list<string>& res, string a, string b, string c) {
    if (!isValid(a) || !isValid(b))
        return false;
    string sum = addString(a, b);
    if (sum == c) {
        res.push_back(sum);
        return true;
    }
    if (c.size() <= sum.size() || sum != c.substr(0, sum.size())) {
        return false;
    } else {
        res.push_back(sum);
        return checkAddition(res, b, sum, c.substr(sum.size()));
    }
}

list<string> additiveSequence(string num) {
    list<string> res;
    int l = num.length();
    for (int i = 1; i <= l/2; i++) {
        for (int j = 1; j <= (l - i)/2; j++) {
            if (checkAddition(res, num.substr(0, i), num.substr(i, j), num.substr(i + j))) {
                res.push_front(num.substr(i, j));
                res.push_front(num.substr(0, i));
                return res;
            }
        }
    }
    res.clear();
    return res;
}

void generateAdditiveSequence(string num) {
    cout<<"For "<<num<<" :";
    list<string> res = additiveSequence(num);
    for (list<string>::iterator it = res.begin(); it != res.end(); it++)
        cout<<" "<<*it;
    cout<<endl;
}

int main() {
    generateAdditiveSequence("235813");
    generateAdditiveSequence("199100199");
    return 0;
}
