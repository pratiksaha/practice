//sort a stack
#include<iostream>
#include<stack>
using namespace std;

void sortStack(stack<int> *s, bool reverse=false) {
    stack<int> aux;
    while(!s->empty()) {
        int curr = s->top();
        s->pop();
        if (aux.empty()) {
            aux.push(curr);
        } else {
            while(!aux.empty()) {
                int temp = aux.top();
                if (temp <= curr) {
                    break;
                } else{
                    aux.pop();
                    s->push(temp);
                }
            }
            aux.push(curr);
        }
    }
    if (reverse) {
        *s = aux;
    } else {
        while(!aux.empty()) {
            int key = aux.top();
            aux.pop();
            s->push(key);
        }
    }
}

void sortedInsert(stack<int> *s, int x, bool reverse=false) {
    if ((s->empty() || x>s->top()) && reverse){
        s->push(x);
    } else {
        int temp = s->top();
        s->pop();
        sortedInsert(s, x);
        s->push(temp);
    }
}

void sortStackRecr(stack<int> *s, bool reverse=false) {
    if (!s->empty()) {
        int x = s->top();
        s->pop();
        sortStackRecr(s, reverse);
        sortedInsert(s, x, reverse);
    }
}

int main () {
    stack<int> s1, s2, s3, s4;
    int arr[] = {36, 25, 45, 12, 3, 5, 90, 56};
    for (int i=0; i<(sizeof(arr)/sizeof(arr[0])); i++) {
        s1.push(arr[i]);
        s2.push(arr[i]);
        s3.push(arr[i]);
        s4.push(arr[i]);
    }
    sortStack(&s1);
    sortStack(&s2, true);
    sortStack(&s3);
    sortStack(&s4, true);
    cout<<"Stack 1:";
    while(!s1.empty()) {
        cout<<" "<<s1.top();
        s1.pop();
    }
    cout<<endl;
    cout<<"Stack 2:";
    while(!s2.empty()) {
        cout<<" "<<s2.top();
        s2.pop();
    }
    cout<<endl;
    cout<<"Stack 3:";
    while(!s3.empty()) {
        cout<<" "<<s3.top();
        s3.pop();
    }
    cout<<endl;
    cout<<"Stack 4:";
    while(!s4.empty()) {
        cout<<" "<<s4.top();
        s4.pop();
    }
    cout<<endl;
    return 0;
}
