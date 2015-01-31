//convert a binary tree to binary search tree
#include<iostream>
#include<cstdlib>
#include<algorithm>
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

int countNodes(struct node* node) {
    if (node)
        return countNodes (node->left) + countNodes (node->right) + 1;
    else
        return 0;
}

void storeInorder(struct node* node, int *arr, int *ptr) {
    if (node) {
        storeInorder(node->left, arr, ptr);
        arr[*ptr] = node->data;
        (*ptr)++;
        storeInorder(node->right, arr, ptr);
    }
}

void arrayToBST(struct node* node, int *arr, int *ptr) {
    if (node) {
        arrayToBST(node->left, arr, ptr);
        node->data = arr[*ptr];
        (*ptr)++;
        arrayToBST(node->right, arr, ptr);
    }
}

void BSTfromBT(struct node *node) {
    if (node) {
        int i;
        int n = countNodes(node);
        int *arr = new int[n];
        i = 0;
        storeInorder(node, arr, &i);
        sort(arr, arr+n);
        i = 0;
        arrayToBST(node, arr, &i);
        delete [] arr;
    }
}

int main() {
    struct node *root = NULL;
    root = getNode(10);
    root->left = getNode(30);
    root->right = getNode(15);
    root->left->left = getNode(20);
    root->right->right = getNode(5);
    printTree(root), cout<<endl;
    BSTfromBT(root);
    printTree(root), cout<<endl;
    return 0;
}
