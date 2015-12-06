//to check if a given array can represent Preorder traversal of a BST
#include<bits/stdc++.h>
using namespace std;
 
bool checkBST(int pre[], int n) {
    stack<int> s;
    int root = INT_MIN;
    for (int i=0; i<n; i++) {
        if (pre[i] < root) //return false if we find a node who is on right side and smaller than root
            return false;
        while (!s.empty() && s.top()<pre[i]) { //make the last removed item as new root and keep removing items smaller than pre[i] if pre[i] is in right subtree of stack top
            root = s.top();
            s.pop();
        }
        s.push(pre[i]); //at this point either stack is empty or pre[i] is smaller than root
    }
    return true;
}

void printArray(int a[], int n) {
    cout<<"Array :";
    for (int i=0; i<n; i++)
        cout<<" "<<a[i];
}

int main() {
    int n;
    int pre1[] = {40, 30, 35, 80, 100};
    int pre2[] = {40, 30, 35, 20, 80, 100};
    n = sizeof(pre1)/sizeof(pre1[0]);
    printArray(pre1, n);
    checkBST(pre1, n)?cout<<" can ":cout<<" cannot ";
    cout<<"represent a BST\n";
    n = sizeof(pre2)/sizeof(pre2[0]);
    printArray(pre2, n);
    checkBST(pre2, n)?cout<<" can ":cout<<" cannot ";
    cout<<"represent a BST\n";
    return 0;
}
