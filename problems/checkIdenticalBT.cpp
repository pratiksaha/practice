//check binary tree identical
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

bool checkIdentical(struct node* a, struct node* b) {
    if(a==NULL && b==NULL) {
        return true;
    } else if (a!=NULL && b!=NULL) {
        return (a->data == b->data && checkIdentical(a->left, b->left) && checkIdentical(a->right, b->right));
    } else {
        return false;
    }
} 

int main() {
    struct node *root1 = getNode(1);
    struct node *root2 = getNode(1);
    root1->left = getNode(2);
    root1->right = getNode(3);
    root1->left->left  = getNode(4);
    root1->left->right = getNode(5);
    root2->left = getNode(2);
    root2->right = getNode(3);
    root2->left->left = getNode(4);
    root2->left->right = getNode(5);
    cout<<((checkIdentical(root1, root2))?"Trees are identical":"Trees are not identical")<<endl;
    root2->left->right->left = getNode(6);
    cout<<((checkIdentical(root1, root2))?"Trees are identical":"Trees are not identical")<<endl;
    deleteTree(&root1);
    deleteTree(&root2);
    return 0;
}
