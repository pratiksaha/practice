//to implement a stack which supports push() pop() getMid() delMid() in O(1)
#include<iostream>
#include<list>
using namespace std;

class midStack {
    private:
        list<int> data;
    public:
        void push(int);
        int pop();
        int getMid();
        void delMid();
};

void midStack:: push(int key) {
    data.push_back(key);
}

int midStack:: pop() {
    int key = data.back();
    data.pop_back();
    return key;
}

int midStack:: getMid() {
    list<int>::iterator it = data.begin();
    int n = data.size(); //size is 0(1) in c++ 11
    if (n%2)
        advance(it, n/2);
    else
        advance(it, n/2-1);
    return *it;
}

void midStack:: delMid() {
    list<int>::iterator it = data.begin();
    int n = data.size();
    if (n%2)
        advance(it, n/2);
    else
        advance(it, n/2-1);
    data.erase(it); //O(1) for deleting one elem
}

int main() {
    midStack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    cout<<"Mid : "<<s.getMid()<<endl;
    s.delMid();
    cout<<"Mid : "<<s.getMid()<<endl;
    s.delMid();
    cout<<"Mid : "<<s.getMid()<<endl;
    cout<<s.pop()<<" popped"<<endl;
    cout<<s.pop()<<" popped"<<endl;
    cout<<s.pop()<<" popped"<<endl;
    return 0;   
}
