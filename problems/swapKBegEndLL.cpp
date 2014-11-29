//swap kth node from beginning and end
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

void swapKth(struct node **head, int k) {
    int n = 0;
    struct node *curr = *head;
    while (curr != NULL) {
        n++;
        curr = curr->next;
    }
    
    if (n < k)
        return; //invalid k
    if (2*k -1 ==  n)
        return; //kth from beg and end are same
    
    struct node *x = *head;
    struct node *x_prev = NULL;
    for (int i = 1; i < k; i++) {
        x_prev = x;
        x = x->next;
    }
    struct node *y = *head;
    struct node *y_prev = NULL;
    for (int i = 1; i < n-k+1; i++) { // k th node from end = n-k+1 th node from end
        y_prev = y;
        y = y->next;
    }
    if (x_prev)
        x_prev->next = y;
    if (y_prev)
        y_prev->next = x;
    struct node *temp = x->next;
    x->next = y->next;
    y->next = temp;
    
    if (k == 1)
        *head = y;
    if (k == n)
        *head = x;
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
    swapKth(&head, 3);
    printList(head);
    deleteList(&head);
    return 0;
}
