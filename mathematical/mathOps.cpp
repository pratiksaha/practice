#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

vector<int> reverse(vector <int> a) {
    vector<int> res;
    vector<int>:: iterator it, ri;
    it = a.end();
    do {
        it--;
        res.push_back(*it);
    } while(it!=a.begin());
    return res;
}

vector<int> add(vector <int> x, vector <int> y) {
    vector<int> res;
    vector<int>:: iterator xi, yi, ri;
    int carry = 0;
    xi = x.end();
    yi = y.end();
    do {
        xi--;
        yi--;
        int s = *xi+*yi+carry;
        res.push_back(s%10);
        carry = s/10;    
    } while (xi != x.begin() && yi != y.begin());
    if(xi == x.begin() && yi == y.begin()){
        //do nothing;
    } else if (yi == y.begin()){
        do {
            xi--;
            int s = *xi+carry;
            res.push_back(s%10);
            carry = s/10;
        } while(xi != x.begin());
    } else if (xi == x.begin()){
        do {
            yi--;
            int s = *yi+carry;
            res.push_back(s%10);
            carry = s/10;
        } while(yi != y.begin());
    }
    if (carry != 0)
        res.push_back(carry);
    return res;
   
}

vector<int> sub(vector <int> x, vector <int> y) { //assuming x is always > y
    vector<int> res;
    vector<int>:: iterator xi, yi, ri;
    int b = 0;
    xi = x.end();
    yi = y.end();
    do {
        xi--;
        yi--;
        int s = *xi -b -*yi;
        if(s>=0){
            res.push_back(s);
            b = 0;
        }
        else{
            res.push_back(10 + s);
            b = 1;
        }    
    } while(xi != x.begin() && yi != y.begin());
    if (xi == x.begin() && yi == y.begin()){
        //do nothing;
    } else if (yi == y.begin()){
        do{
            xi--;
            int s = *xi -b ;
            if(s>=0){
                res.push_back(s);
                b = 0;
            }
            else{
                res.push_back(10 + s);
                b = 1;
            } 
        }while(xi != x.begin());
    }
    return res;
}

vector<int> mul( vector <int> x, vector <int> y){
    vector<int> res;
    vector<int>:: iterator yi,it;
    res.push_back(0);
    yi = y.end();
    int itr = 1;
    do {
        yi--;
        int times = (*yi)*itr;
        vector<int> temp_ve;
        temp_ve.push_back(0); 
        for(int i = 0; i<times; i++) {
            temp_ve = add(temp_ve, x);
            temp_ve = reverse(temp_ve);
        }
        res = add(res, temp_ve);
        res = reverse(res);
        itr = itr *10;
    } while(yi != y.begin());
    res = reverse(res);
    return res;
}


int main(){
    vector<int> s, t;
    vector<int>:: iterator it;
    char c;
    int x;
    c = getchar();
    while(c!= '\n'){
        s.push_back(c-48);
        c = getchar();
    }
    c = getchar();
    while(c!= '\n'){
        t.push_back(c-48);
        c = getchar();
    }
    cout<<"first no = ";
    for(it= s.begin(); it !=s.end(); ++it)
        cout<<*it;
    cout<<endl;
    cout<<"second no = ";
    for(it= t.begin(); it !=t.end(); ++it)
        cout<<*it;
    cout<<endl;    
    vector<int> sum, diff, prod;
    sum = add(s,t);
    diff = sub(s,t);
    prod = mul(s,t);
    cout<<"sum = ";
    it = sum.end();
    do {
        it--;
        cout<<*it;
    } while (it!=sum.begin());
    cout<<endl;
    cout<<"diff = ";
    it = diff.end();
    do {
        it--;
        cout<<*it;
    } while (it!=diff.begin());
    cout<<endl;
    cout<<"prod = ";
    it = prod.end();
    do {
        it--;
        cout<<*it;
    } while (it!=prod.begin());
    cout<<endl;
    return 0;
}
