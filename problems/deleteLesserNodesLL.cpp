//delete nodes which have greater value on right
#include<iostream>
#include<cstdlib>
using namespace std;

struct node {
    int data;
    struct node *next;
};

struct node* getNode() { //alocate memory
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL) {
        cout<<"Memory Full"<<endl;
    }
    return temp;
}

void push_front(struct node **head, int key) { //add node in the front
    struct node* temp = getNode();
    temp->data = key;
    temp->next = *head;
    *head = temp;
}

void deleteList(struct node **head) { //free all space used by the list
    struct node* curr = *head;
    struct node* next;
    while (curr != NULL) {
        next = curr->next;
        free(curr);
        curr = next;
    }
    *head = NULL;
}

void printList(struct node *head) { //print the list
    cout<<"Linked List :";
    while(head != NULL) {
        cout<<" "<<head->data;
        head = head->next;
    }
    cout<<endl;
}

void reverse(struct node **head) { //reverse a list
    struct node* prev = NULL;
    struct node* curr = *head;
    struct node* next;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
}

void deleteGreaterNodes(struct node *node) {
    struct node *curr = node;
    struct node *maxnode = node;
    struct node *temp;
    while (curr != NULL && curr->next != NULL) { 
        if(curr->next->data < maxnode->data) { //delete curr if curr is smaller than max
            temp = curr->next;
            curr->next = temp->next;
            free(temp);
        } else { //update max and move curr
            curr = curr->next;
            maxnode = curr;
        }
     }
}

void deleteLesserNodes(struct node **node) {
    reverse(node); //reverse the linked list
    deleteGreaterNodes(*node); //delete nodes which have a node with greater value node on left side
    reverse(node); //reverse the linked list again
}

int main() {
    struct node *head = NULL;
    push_front(&head,3);
    push_front(&head,2);
    push_front(&head,6);
    push_front(&head,5);
    push_front(&head,11);
    push_front(&head,10);
    push_front(&head,15);
    push_front(&head,12);
    printList(head);
    deleteLesserNodes(&head);
    printList(head);
    deleteList(&head);
    return 0;
}
