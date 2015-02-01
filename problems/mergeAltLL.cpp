//merge two lists alternately
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

void printList(struct node *head) { //print the list
    cout<<"Linked List :";
    while(head != NULL) {
        cout<<" "<<head->data;
        head = head->next;
    }
    cout<<endl;
}

struct node *mergeAlt(struct node *a, struct node *b, bool flip=true) {
    struct node* result = NULL;
    if (a == NULL) {
        return b;
    } else if (b == NULL) {
        return a;
    } else {
        result = getNode();
        if (flip) {
            result->data = a->data;
            result->next = mergeAlt(a->next, b, false);
        } else {
            result->data = b->data;
            result->next = mergeAlt(a, b->next, true);
        }
        return result;
    }
}

int main() {
    struct node *head1 = NULL, *head2 = NULL, *res = NULL;
    push_front(&head1, 120);
    push_front(&head1, 100);
    push_front(&head1, 95);
    push_front(&head1, 30);
    push_front(&head1, 3);
    push_front(&head1, 1);
    push_front(&head2, 130);
    push_front(&head2, 120);
    push_front(&head2, 93);
    push_front(&head2, 90);
    push_front(&head2, 32);
    push_front(&head2, 12);
    push_front(&head2, 3);
    push_front(&head2, 0);
    res = mergeAlt(head1, head2);
    cout<<"First ", printList(head1);
    cout<<"Second ", printList(head2);
    cout<<"Result ", printList(res);
    return 0;
}
