//retain m nodes then delete n nodes
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

void deleteNAfterM(struct node *head, int m, int n) {
    struct node *curr = head, *t;
    int count;
    while (curr) {
        for (int count = 1; count<m && curr!= NULL; count++) //skip m nodes
            curr = curr->next;
        if (curr == NULL) //return if we reached end of list
            return;
        t = curr->next;
        for (int count = 1; count<=n && t!= NULL; count++) { //start from next node and delete N nodes
            struct node *temp = t;
            t = t->next;
            free(temp);
        }
        curr->next = t;
        curr = t;
    }
}

int main() {
    struct node *head = NULL;
    push_front(&head, 10);
    push_front(&head, 9);
    push_front(&head, 8);
    push_front(&head, 7);
    push_front(&head, 6);
    push_front(&head, 5);
    push_front(&head, 4);
    push_front(&head, 3);
    push_front(&head, 2);
    push_front(&head, 1);
    printList(head);
    deleteNAfterM(head, 2, 4);
    printList(head);
    deleteList(&head);
    return 0;
}
