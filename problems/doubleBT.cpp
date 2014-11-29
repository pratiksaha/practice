//convert BT to double tree
#include<iostream>
#include<cstdlib>
using namespace std;

struct node {
    int data;
    struct node* left;
    struct node* right;
};
  
struct node* newNode(int key) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = key;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void printTree(struct node* node) {
    if (node) {
        printTree(node->left); 
        cout<<" "<<node->data;
        printTree(node->right);
    }
}

void deleteTree(struct node **node) {
    if((*node) != NULL) {
        deleteTree(&((*node)->right));
        deleteTree(&((*node)->left));
        struct node *temp = *node;
        *node = NULL;
        free(temp);
    }
}

void doubleTree(struct node* node) {
    if (node) {
        doubleTree(node->left);
        doubleTree(node->right);
        struct node* oldLeft = node->left;
        node->left = newNode(node->data);
        node->left->left = oldLeft;
    }
}

int main() {
    struct node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    cout<<"Tree :", printTree(root), cout<<endl;
    doubleTree(root);
    cout<<"Tree :", printTree(root), cout<<endl;
    deleteTree(&root);
    return 0;
}
