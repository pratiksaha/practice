//convert BT to hold child sum property where data in every node must be equal to sum of data in left and right children
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

void increment(struct node* node, int diff) {
    if(node->left) {
        node->left->data = node->left->data + diff;
        increment(node->left, diff); 
    } else if (node->right) {
        node->right->data = node->right->data + diff;
        increment(node->right, diff);
    }
}

void childSum(struct node* node) {
    if (node && (node->left || node->right) ) {
        childSum(node->left);
        childSum(node->right);
        int left = 0,  right = 0, diff;
        if (node->left)
            left = node->left->data;
        if (node->right)
            right = node->right->data;
        diff = left + right - node->data;
        if (diff > 0)
            node->data = node->data + diff;
        else if (diff < 0)
            increment(node, -diff);  //-diff is used to make diff positive
    }
}

int main() {
    struct node *root = getNode(1);
    root->left = getNode(2);
    root->right = getNode(3);
    root->left->left = getNode(4);
    root->left->right = getNode(5);
    cout<<"Tree :", printTree(root), cout<<endl;
    childSum(root);
    cout<<"Tree :", printTree(root), cout<<endl;
    deleteTree(&root);
    return 0;
}
