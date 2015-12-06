//to rearrange a linked list alternately reversed
#include<bits/stdc++.h>
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

void printList(struct node *head) { //print the list
    cout<<"Linked List :";
    while(head != NULL) {
        cout<<" "<<head->data;
        head = head->next;
    }
    cout<<endl;
}

void deleteList(struct node **head) { //free all space used by the list
    struct node *curr = *head;
    struct node *next;
    while (curr != NULL) {
        next = curr->next;
        free(curr);
        curr = next;
    }
    *head = NULL;
}

void reverseList(struct node **head) { //reverse a list
    struct node *curr = *head;
    struct node *prev = NULL;
    struct node *next;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
}

void rearrangeAltRev(struct node **head) {
    struct node *slow = *head;
    struct node *fast = slow->next;
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    struct node *head1 = *head;
    struct node *head2 = slow->next;
    slow->next = NULL;
    reverseList(&head2);
    struct node *curr = getNode();
    curr->data = 0;
    curr->next = NULL;
    *head = curr;
    while (head1 || head2) {
        if (head1) {
            curr->next = head1;
            curr = curr->next;
            head1 = head1->next;
        }
        if (head2) {
            curr->next = head2;
            curr = curr->next;
            head2 = head2->next;
        }
    }
    curr = *head;
    *head = curr->next;
    curr->next = NULL;
    free(curr);
}

int main() {
    struct node *head = NULL;
    push_front(&head, 1);
    push_front(&head, 2);
    push_front(&head, 3);
    push_front(&head, 4);
    push_front(&head, 5);
    printList(head);
    rearrangeAltRev(&head);
    printList(head);
    deleteList(&head);
    return 0;
}
