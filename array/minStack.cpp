//to design a data structure minStack that supports stack operations push() pop() isEmpty() and an additional operation getMin() which returns min elem from the minStack with all these operations O(1)
#include<iostream>
#include<stack>
using namespace std;

class minStack {
    private:
        stack<int> data;
        stack<int> min;
    public:
        bool isEmpty();
        void push(int x);
        int pop();
        int getMin();
        
};
 
bool minStack::isEmpty() {
    if (data.empty())
        return true;
    else
        return false;
}

void minStack::push(int key) {
    if(data.empty()) {
        data.push(key);
        min.push(key);
    } else {
        data.push(key);
        int curr_min = min.top();
        if(key <= curr_min)
            min.push(key);
    }
}

int minStack::pop() {
    int key = data.top();
    data.pop();
    int curr_min = min.top();
    if (curr_min == key)
        min.pop(); 
    return key;
}

int minStack::getMin() {
    return min.top();
}

int main() {
    minStack s;
    cout<<"Check for empty "<<s.isEmpty()<<endl;
    s.push(10);
    s.push(20);
    cout<<"Check for empty "<<s.isEmpty()<<endl;
    s.push(30);
    cout<<"Min : "<<s.getMin()<<endl;
    s.push(5);
    cout<<"Min : "<<s.getMin()<<endl;
    cout<<s.pop()<<" popped"<<endl;
    cout<<"Min : "<<s.getMin()<<endl;
    return 0;
}
