//print the Next Greater Element for every element which is the first greater element on the right side of the element in the array
#include<iostream>
#include<iomanip>
#include<stack>
using namespace std;

void nextGreaterElement(int arr[], int n) {
    stack<int> s;  
    int i, element, next;
 
    s.push(arr[0]);
    for (i=1; i<n; i++) {
        next = arr[i];
 
        if (!s.empty()) {
            element = s.top(); //if stack is not empty, then pop an element from stack
            s.pop();
            while (element < next) { //while the popped element is smaller than next
                cout<<setw(3)<<element<<"--->"<<setw(3)<<next<<endl;
                if (s.empty())
                   break;
                element = s.top();
                s.pop();
            }
            if (element>next) //if element is greater than next, then push the element back
                s.push(element);
        }
        s.push(next);
    }
    while (!s.empty()) {//the remaining elements in stack do not have the next greater element
        element = s.top();
        s.pop();
        next = -1;
        cout<<setw(3)<<element<<"--->"<<setw(3)<<next<<endl;
    }
}

int main() {
    int arr[]= {11, 13, 21, 3};
    nextGreaterElement(arr, sizeof(arr)/sizeof(arr[0]));
    return 0;
}
