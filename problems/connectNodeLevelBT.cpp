//connect nodes of BT at same level
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

struct node *getNext(struct node *node) {
    struct node *temp = node->next;
    while (temp) {
        if (temp->left)
            return temp->left;
        if (temp->right)
            return temp->right;
        temp = temp->next;
    }
    return NULL;
}

void connectNodeLevel(struct node* node) {
    if (node) {
        node->next = NULL;
        while (node != NULL) {
            struct node *temp = node;
            while (temp != NULL) {
                if (temp->left) {
                    if (temp->right)
                        temp->left->next = temp->right;
                    else
                        temp->left->next = getNext(temp);
                }
                if (temp->right)
                    temp->right->next = getNext(temp);
                temp = temp->next;
            }
            if (node->left)
                node = node->left;
            else if (node->right)
                node = node->right;
            else
                node = getNext(node);
        }
    }
}

int main() {
    struct node *root = getNode(1);
    root->left = getNode(2);
    root->right = getNode(3);
    root->left->left = getNode(4);
    root->left->right = getNode(5);
    cout<<"Tree :", printTree(root), cout<<endl;
    connectNodeLevel(root);
    cout<<"Tree :", printTree(root), cout<<endl;
    deleteTree(&root);
    return 0;
}
