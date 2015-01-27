// Program for linked implementation of complete binary tree
#include<iostream>
#include<cstdlib>
#include<queue>
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

void insert(struct node **root, int data, queue<struct node *> *q) {
    struct node *temp = getNode(data);
    if (*root) {
        struct node* front = q->front();
        if (!front->left)
            front->left = temp;
        else if (!front->right)
            front->right = temp;
        if (front && front->left && front->right)
            q->pop();
    } else {
        *root = temp;
    }
    q->push(temp);
}

int main() {
    struct node* root = NULL;
    queue<struct node * > q;
    for(int i=1; i<=12; i++)
        insert(&root, i, &q);
    cout<<"Tree :", printTree(root), cout<<endl;
    return 0;
}
