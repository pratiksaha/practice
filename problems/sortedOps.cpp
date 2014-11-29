//sorted insert, intersection and union of 2 sorted lists
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

void sortedInsert(struct node** head, int key) { //sorted insert
    struct node *newNode = getNode();
    newNode->data = key;
    newNode->next = NULL;
    if (*head == NULL || (*head)->data >= newNode->data) {
        newNode->next = *head;
        *head = newNode;
    } else {
        struct node* curr = *head;
        while (curr->next!=NULL && curr->next->data < newNode->data)
            curr = curr->next;
        newNode->next = curr->next;
        curr->next = newNode;
    }
}

struct node *inSorted(struct node *a, struct node *b) { //intersection
    struct node *in = NULL;
    struct node **last = &in;
    while (a != NULL && b != NULL) {
        if (a->data < b->data) {    
            a = a->next;
        } else if (a->data > b->data) {
            b = b->next;
        } else {
            push_front(last, a->data);
            last = &((*last)->next);
            a = a->next;
            b = b->next;
        }
    }
    return in;
}

struct node *unSorted(struct node *a, struct node *b) { //union
    struct node *un = NULL;
    struct node **last = &un;
    while (a != NULL && b != NULL) {
        if (a->data < b->data) {
            push_front(last, a->data);
            last = &((*last)->next);    
            a = a->next;
        } else if (a->data > b->data) {
            push_front(last, a->data);
            last = &((*last)->next);
            b = b->next;
        } else {
            push_front(last, a->data);
            last = &((*last)->next);
            a = a->next;
            b = b->next;
        }
    }
    while (a != NULL) {
        push_front(last, a->data);
        last = &((*last)->next);    
        a = a->next;
    }
    while (b != NULL) {
        push_front(last, b->data);
        last = &((*last)->next);
        b = b->next;
    }
    return un;
}

int main() {
    struct node *head = NULL;
    head = getNode();
    head->data = 15;
    head->next = NULL;
    sortedInsert(&head, 12);
    sortedInsert(&head, 10);
    sortedInsert(&head, 25);
    sortedInsert(&head, 13);
    sortedInsert(&head, 11);
    struct node *tail = NULL;
    tail = getNode();
    tail->data = 15;
    tail->next = NULL;
    sortedInsert(&tail, 11);
    sortedInsert(&tail, 30);
    printList(head);
    printList(tail);
    struct node *in, *un;
    in = inSorted(head, tail);
    printList(in);
    un = unSorted(head, tail);
    printList(un);
    deleteList(&head);
    deleteList(&tail);
    deleteList(&in);
    deleteList(&un);
    return 0;
}
