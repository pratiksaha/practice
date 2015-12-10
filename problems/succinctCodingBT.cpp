//to encode and decode a binary tree succinctly
#include<bits/stdc++.h>
using namespace std;
 
struct node {
    int data;
    struct node *left;
    struct node *right;
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

void succinctEncode(struct node *node, list<bool> *strc, list<int> *data) {
    if (node) {
        strc->push_back(1);
        data->push_back(node->data);
        succinctEncode(node->left, strc, data);
        succinctEncode(node->right, strc, data);
    } else {
        strc->push_back(0);
    }
}

struct node *succinctDecode(list<bool> *strc, list<int> *data) {
    struct node *root = NULL;
    if (strc->size() > 0) {
        bool b = strc->front();
        strc->pop_front();
        if (b == 1) {
            int key = data->front();
            data->pop_front();
            root = getNode(key);
            root->left = succinctDecode(strc, data);
            root->right = succinctDecode(strc, data);
        }
    }
    return root;
}

int main() {
    struct node *root = getNode(10);
    root->left = getNode(20);
    root->right = getNode(30);
    root->left->left = getNode(40);
    root->left->right = getNode(50);
    root->right->right = getNode(70);
    cout<<"Given Tree :";
    printTree(root);
    cout<<endl;
    list<bool> strc;
    list<int> data;
    succinctEncode(root, &strc, &data);
    cout<<"Encoded Tree :\n";
    cout<<"    Structure List :";
    for (list<bool>::iterator it = strc.begin(); it != strc.end(); it++)
        cout<<" "<<*it;
    cout<<endl;
    cout<<"    Data List :";
    for (list<int>::iterator it = data.begin(); it != data.end(); it++)
        cout<<" "<<*it;
    cout<<endl;
    struct node *newroot = succinctDecode(&strc, &data);
    cout<<"Decoded Tree :";
    printTree(newroot);
    cout<<endl;
    return 0;
}
