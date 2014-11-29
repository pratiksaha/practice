//convert given tree to sumtree where every node contains sum of values of nodes in left and right subtrees in the original tree
#include<iostream>
#include<cstdlib>
#include<climits>
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

void deleteTree(struct node **node) { //free all space used by the tree
    if((*node) != NULL) {
        deleteTree(&((*node)->right));
        deleteTree(&((*node)->left));
        struct node *temp = *node;
        *node = NULL;
        free(temp);
    }
}

void printTree(struct node *node) { //print the tree inorder
    if (node) {
        printTree(node->left);
        cout<<" "<<node->data;
        printTree(node->right);
    }
}

int sumTree(struct node *node) {
    if (node) {
        int old_val = node->data;
        node->data = sumTree(node->left) + sumTree(node->right);
        return node->data + old_val;
    } else {
        return 0;
    }
}

int main() {
    struct node *root = getNode(1);
    root->left = getNode(2);
    root->right = getNode(3);
    root->left->left = getNode(4);
    root->left->right = getNode(5);
    cout<<"Tree :", printTree(root), cout<<endl;
    sumTree(root);
    cout<<"Tree :", printTree(root), cout<<endl;
    deleteTree(&root);
    return 0;
}
