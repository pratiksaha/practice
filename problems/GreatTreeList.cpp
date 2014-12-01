//Convert a tree to double link list in place
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

void printTree(struct node *node) { //print the tree inorder
    if (node) {
        printTree(node->left);
        cout<<" "<<node->data;
        printTree(node->right);
    }
}

void printList(struct node *head) { //print the list
    cout<<"Linked List :";
    while(head != NULL) {
        cout<<" "<<head->data;
        head = head->right;
    }
    cout<<endl;
}

void convertTreeListUtil(struct node *node, struct node **prev, struct node **head) {
    if (node) {
        convertTreeListUtil(node->left, prev, head);
        if (*prev) {
            (*prev)->right = node;
        } else {
            *head = node;
        }
        node->left = *prev;
        *prev = node;
        convertTreeListUtil(node->right, prev, head);
    }
}

struct node* convertTreeList(struct node *node) {
    struct node *head = NULL;
    if (node) {
        struct node *prev = NULL;
        convertTreeListUtil(node, &prev, &head);
    }
    return head;
}

int main() {
    struct node *root = getNode(10);
    root->left = getNode(12);
    root->right = getNode(15);
    root->left->left = getNode(25);
    root->left->right = getNode(30);
    root->right->left = getNode(36);
    cout<<"Tree :", printTree(root), cout<<endl;
    struct node *head = convertTreeList(root);
    printList(head);
    return 0;
}
