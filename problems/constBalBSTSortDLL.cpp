//construct balanced bst from sorted doubly linked list
#include<iostream>
#include<cstdlib>
using namespace std;

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

struct node * getNode(int key) { //allocate memory and initialize
    struct node * temp = (struct node *)malloc(sizeof(struct node));
    if(temp == NULL) {
        cout<<"Memory full\n";
        exit(1);
    }
    temp->data = key;
    temp->prev= NULL;
    temp->next = NULL;
    return temp;
}

void push_front(struct node **head, int key) { //add node in the front
    struct node* temp = getNode(key);
    temp->prev = NULL;
    temp->next = *head;
    if (*head)
        (*head)->prev = temp;
    *head = temp;
}

void printList(struct node *head) { //print the list
    cout<<"Linked List :";
    while(head != NULL) {
        cout<<" "<<head->data;
        head = head->next;
    }
    cout<<endl;
}

void printTree(struct node *node) { //print the tree inorder
    if (node) {
        printTree(node->prev);
        cout<<" "<<node->data;
        printTree(node->next);
    }
}

int count(struct node *head) {
    int count = 0;
    while(head) {
        head = head->next;
        count++;
    }
    return count;
}

struct node * getBalBSTSortDLLUtil(struct node **head, int n) { 
    if (n>0) {
        struct node *left = getBalBSTSortDLLUtil(head, n/2);
        struct node *root = getNode((*head)->data);
        root->prev = left;
        *head = (*head)->next;
        root->next = getBalBSTSortDLLUtil(head, n-n/2-1);
        return root;
    } else {
        return NULL;
    }
}

struct node * getBalBSTSortDLL(struct node *head) {
    int n = count(head);
    return getBalBSTSortDLLUtil(&head, n);
}

int main() {
    struct node *head = NULL;
    push_front(&head, 7);
    push_front(&head, 6);
    push_front(&head, 5);
    push_front(&head, 4);
    push_front(&head, 3);
    push_front(&head, 2);
    push_front(&head, 1);
    printList(head);
    struct node *root = getBalBSTSortDLL(head);
    cout<<"Tree :", printTree(root), cout<<endl;
    return 0;
}
