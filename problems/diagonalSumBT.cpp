//find the diagonal sum of a binary tree
//Using features of C++ Standard (2011) Compile using g++ -std=c++11
#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<queue>
#include<unordered_map>
using namespace std;

struct node {
    int data;
    struct node* left;
    struct node* right;
};
 
struct node * getNode(int key) { //allocate memory and initialize
    struct node * temp = (struct node *)malloc(sizeof(struct node));
    if(temp == NULL) {
        cout<<"Memory full\n";
        exit(1);
    }
    temp->data = key;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void printTree(struct node *node) { //print the tree inorder
    if (node) {
        printTree(node->left);
        cout<<" "<<node->data;
        printTree(node->right);
    }
}

void diagonlSum(struct node *root) {
    queue<struct node *> nodeq;
    queue<int> vdq;
    unordered_map<int, int> table;
    unordered_map<int, int>::iterator it;
    nodeq.push(root);
    vdq.push(0);
    while (!nodeq.empty()) {
        struct node *temp = nodeq.front();
        int vd = vdq.front();
        nodeq.pop();
        vdq.pop();
        while(temp) {
            it = table.find(vd);
            if (it != table.end() ) {
                it->second = it->second + temp->data;
            } else {
                table.insert(make_pair(vd, temp->data));
            }
            if (temp->left) {
                nodeq.push(temp->left);
                vdq.push(vd+1);
            }
            temp = temp->right;
        }
    }
    cout<<"Diagonal sums are :";
    for(it=table.begin(); it!=table.end(); it++)
        cout<<" "<<it->second;
    cout<<endl;
}

int main() {
    struct node *root = getNode(1);
    root->left = getNode(2);
    root->right = getNode(3);
    root->left->left = getNode(9);
    root->left->right = getNode(6);
    root->right->left = getNode(4);
    root->right->right = getNode(5);
    root->right->left->left = getNode(12);
    root->right->left->right = getNode(7);
    root->left->right->left = getNode(11);
    root->left->left->right = getNode(10);
    cout<<"Tree :", printTree(root), cout<<endl;
    diagonlSum(root);
    return 0;
}
