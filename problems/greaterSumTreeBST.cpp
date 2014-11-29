//transform BST to greater sum tree where each node contains sum of all nodes greater than that node
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

void greaterSumTreeUtil(struct node *node, int *sum) {
    if (node) {
        greaterSumTreeUtil(node->right, sum);
        *sum = *sum + node->data;
        node->data = *sum - node->data;
        greaterSumTreeUtil(node->left, sum);
    }
}

void greaterSumTree(struct node *node) {
    int sum = 0;
    greaterSumTreeUtil(node, &sum);
}

int main() {
    struct node *root = getNode(5);
    root->left = getNode(2);
    root->right = getNode(13);
    root->left->left = getNode(1);
    root->left->right = getNode(3);
    cout<<"Tree :", printTree(root), cout<<endl;
    greaterSumTree(root);
    cout<<"Tree :", printTree(root), cout<<endl;
    deleteTree(&root);
    return 0;
}
