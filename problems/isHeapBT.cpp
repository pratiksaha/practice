//to check if a given BT is a heap
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

void deleteTree(struct node **node) { //free all space used by the tree
    if((*node) != NULL) {
        deleteTree(&((*node)->right));
        deleteTree(&((*node)->left));
        struct node *temp = *node;
        *node = NULL;
        free(temp);
    }
}

int getNodeCount(struct node *node) {
    if (node)
        return 1 + getNodeCount(node->left) + getNodeCount(node->right);
    else
        return 0;
}

bool checkComplete(struct node *node, int i, int n) {
    if (!node)
        return true;
    if (i>n)
        return false;
    return (checkComplete(node->left, 2*i+1, n) && checkComplete(node->right, 2*i+2, n));
}

bool checkHeap(struct node *node) {
    if (!node->left && !node->right)
        return true;
    if (node->right) {
        if  (node->data >= node->left->data && node->data >= node->right->data && checkHeap(node->left) && checkHeap(node->right))
            return true;
        else
            return false;
    } else {
        return (node->data >= node->left->data);
    }
}

bool isHeap(struct node *root) {
    int count = getNodeCount(root);
    int index = 0;
    if (checkComplete(root, index, count) && checkHeap(root))
        return true;
    else
        return false;
}

int main() {
    struct node* root = NULL;
    root = getNode(10);
    root->left = getNode(9);
    root->right = getNode(8);
    root->left->left = getNode(7);
    root->left->right = getNode(6);
    root->right->left = getNode(5);
    root->right->right = getNode(4);
    root->left->left->left = getNode(3);
    root->left->left->right = getNode(2);
    root->left->right->left = getNode(1);
    cout<<"Given Tree :";
    printTree(root);
    cout<<(isHeap(root)?" is ":" is not ")<<"a Heap\n";
    return 0;
}
