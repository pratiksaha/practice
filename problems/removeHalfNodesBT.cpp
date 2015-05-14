//remove half nodes from a binary tree
#include<iostream>
#include<cstdlib>
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

void printTree(struct node* node) {
    if (node) {
        printTree(node->left); 
        cout<<" "<<node->data;
        printTree(node->right);
    }
}

struct node* removeHalfNodes(struct node* root) {
    if (root) {
        root->left  = removeHalfNodes(root->left);
        root->right = removeHalfNodes(root->right);
        if (root->left==NULL && root->right==NULL) {
            return root;
        } else if (root->left==NULL) {
            struct node* new_root = root->right;
            free(root);
            return new_root;
        } else if (root->right==NULL) {
            struct node* new_root = root->left;
            free(root);
            return new_root;
        } else {
            return root;
        }
    } else {
        return NULL;
    }
}
 
int main(void) {
    struct node *root = getNode(2);
    root->left = getNode(7);
    root->right = getNode(5);
    root->left->right = getNode(6);
    root->left->right->left = getNode(1);
    root->left->right->right = getNode(11);
    root->right->right = getNode(9);
    root->right->right->left = getNode(4);
    cout<<"Before Tree :"; printTree(root); cout<<endl;
    root = removeHalfNodes(root);
    cout<<"After Tree :"; printTree(root); cout<<endl;
    deleteTree(&root);
    return 0;
}
