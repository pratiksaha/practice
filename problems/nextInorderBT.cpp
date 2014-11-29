//populate next node in inorder traversal for all nodes in BT
#include<iostream>
#include<cstdlib>
#include<climits>
using namespace std;

struct node {
    int data;
    struct node *left;
    struct node *right;
    struct node *next;
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
    temp->next = NULL;
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
        cout<<" "<<node->data<<":";
        if (node->next)
            cout<<node->next->data;
        else
            cout<<"NULL";
        printTree(node->right);
    }
}

void nextInorderUtil(struct node* node, struct node **next) {
    if (node) {
        nextInorderUtil(node->right, next);
        node->next = *next;
        *next = node;
        nextInorderUtil(node->left, next);
    }
}

void nextInorder(struct node *node) {
    struct node *next = NULL;
    nextInorderUtil(node, &next);
}

int main() {
    struct node *root = getNode(4);
    root->left = getNode(3);
    root->right = getNode(5);
    root->left->left = getNode(1);
    root->left->right = getNode(2);
    cout<<"Tree :", printTree(root), cout<<endl;
    nextInorder(root);
    cout<<"Tree :", printTree(root), cout<<endl;
    deleteTree(&root);
    return 0;
}
