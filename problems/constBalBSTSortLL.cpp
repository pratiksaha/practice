//construct balanced bst from sorted linked list
#include<iostream>
#include<cstdlib>
using namespace std;

struct Tnode {
    int data;
    struct Tnode *left;
    struct Tnode *right;
};

struct Tnode * getTNode(int key) { //allocate memory and initialize
    struct Tnode * temp = (struct Tnode *)malloc(sizeof(struct Tnode));
    if(temp == NULL) {
        cout<<"Memory full\n";
        exit(1);
    }
    temp->data = key;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

struct Lnode {
    int data;
    struct Lnode *next;
};

struct Lnode* getLNode() { //alocate memory
    struct Lnode *temp = (struct Lnode *)malloc(sizeof(struct Lnode));
    if (temp == NULL) {
        cout<<"Memory Full"<<endl;
    }
    return temp;
}

void push_front(struct Lnode **head, int key) { //add node in the front
    struct Lnode* temp = getLNode();
    temp->data = key;
    temp->next = *head;
    *head = temp;
}

void printList(struct Lnode *head) { //print the list
    cout<<"Linked List :";
    while(head != NULL) {
        cout<<" "<<head->data;
        head = head->next;
    }
    cout<<endl;
}

void printTree(struct Tnode *node) { //print the tree inorder
    if (node) {
        printTree(node->left);
        cout<<" "<<node->data;
        printTree(node->right);
    }
}

int count(struct Lnode *head) {
    int count = 0;
    while(head) {
        head = head->next;
        count++;
    }
    return count;
}

struct Tnode * getBalBSTSortLLUtil(struct Lnode **head, int n) { 
    if (n>0) {
        struct Tnode *left = getBalBSTSortLLUtil(head, n/2);
        struct Tnode *root = getTNode((*head)->data);
        root->left = left;
        *head = (*head)->next;
        root->right = getBalBSTSortLLUtil(head, n-n/2-1);
        return root;
    } else {
        return NULL;
    }
}

struct Tnode * getBalBSTSortLL(struct Lnode *head) {
    int n = count(head);
    return getBalBSTSortLLUtil(&head, n);
}

int main() {
    struct Lnode *head = NULL;
    push_front(&head, 7);
    push_front(&head, 6);
    push_front(&head, 5);
    push_front(&head, 4);
    push_front(&head, 3);
    push_front(&head, 2);
    push_front(&head, 1);
    printList(head);
    struct Tnode *root = getBalBSTSortLL(head);
    cout<<"Tree :", printTree(root), cout<<endl;
    return 0;
}
