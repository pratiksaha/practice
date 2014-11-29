//add sum of all greater nodes to each node of a BST
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

void addSumAllGreaterUtil(struct node *node, int *sum) {
    if (node) {
        addSumAllGreaterUtil(node->right, sum);
        *sum = *sum + node->data;
        node->data = *sum;
        addSumAllGreaterUtil(node->left, sum);
    }
}

void addSumAllGreater(struct node *node) {
    int sum = 0;
    addSumAllGreaterUtil(node, &sum);
}

int main() {
    struct node *root = getNode(5);
    root->left = getNode(2);
    root->right = getNode(13);
    root->left->left = getNode(1);
    root->left->right = getNode(3);
    cout<<"Tree :", printTree(root), cout<<endl;
    addSumAllGreater(root);
    cout<<"Tree :", printTree(root), cout<<endl;
    deleteTree(&root);
    return 0;
}
