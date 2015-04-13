//to compute factorial of big numbers
#include<iostream>
#include<vector>
using namespace std;

void multiply(int x, vector<int> *res) {
    int carry = 0;
    for (vector<int>::iterator it=res->begin(); it!=res->end(); it++) {
        int prod = (*it)*x+carry;
        *it = prod % 10;
        carry  = prod/10;
    }
    while (carry) {
        res->push_back(carry%10);
        carry = carry/10;
    }
}

void factorial(int n) {
    vector<int> res;
    res.push_back(1);
    int res_size = 1;
    for (int x=2; x<=n; x++)
        multiply(x, &res);
    cout<<"Factorial of "<<n<<" is ";
    vector<int>::iterator it = res.end();
    do {
        it--;
        cout<<*it;
    } while( it != res.begin());
    cout<<endl;
}

int main() {
    factorial(100);
    return 0;
}
