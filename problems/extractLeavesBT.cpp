//extract leaves of BT in a DLL
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

void deleteList(struct node **head) { //free all space used by the list
    struct node* curr = *head;
    struct node* next;
    while (curr != NULL) {
        next = curr->right;
        free(curr);
        curr = next;
    }
    *head = NULL;
}

void printList(struct node *head) { //print the list
    cout<<"Linked List :";
    while(head != NULL) {
        cout<<" "<<head->data;
        head = head->right;
    }
    cout<<endl;
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

struct node* extractLeaves(struct node *root, struct node **head) {
    if (root) {
        if (root->left == NULL && root->right == NULL) {
            root->right = *head;
            if (*head != NULL)
                (*head)->left = root;
            *head = root;
            return NULL;
        }
        root->right = extractLeaves(root->right, head);
        root->left = extractLeaves(root->left, head);
        return root;
    } else {
        return NULL;
    }
}

int main() {
    struct node *root = getNode(1);
    root->left = getNode(2);
    root->right = getNode(3);
    root->left->left = getNode(4);
    root->left->right = getNode(5);
    cout<<"Tree :", printTree(root), cout<<endl;
    struct node *head = NULL;
    extractLeaves(root, &head);
    cout<<"Tree :", printTree(root), cout<<endl;
    printList(head);
    deleteTree(&root);
    deleteList(&head);
    return 0;
}
