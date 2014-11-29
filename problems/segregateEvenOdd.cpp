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

void segregateEvenOdd(struct node **head) {
    struct node *end = *head;
    while (end->next != NULL)
        end = end->next;
    struct node *new_end = end;
    struct node *curr = *head;
    while (curr->data %2 != 0 && curr != end) { //move all odd nodes before the first even node after end
        new_end->next = curr;
        curr = curr->next;
        new_end->next->next = NULL;
        new_end = new_end->next;
    }
    struct node *prev = NULL;
    if (curr->data%2 == 0) {
        *head = curr; //change the head pointer to point to first even node
        while (curr != end) {
            if ((curr->data)%2 == 0) {
                prev = curr;
                curr = curr->next;
            } else {
                prev->next = curr->next; //make a link b/w prev and curr->next
                curr->next = NULL;
                new_end->next = curr; //Move curr to end
                new_end = curr; //change new end
                curr = prev->next;
            }
        }
    } else {
        prev = curr;
    }
    if (new_end!=end && (end->data)%2 != 0) { //to maintain same order of odd nos in modified list
        prev->next = end->next;
        end->next = NULL;
        new_end->next = end;
    }
}

int main() {
    struct node* head = NULL;
    push_front(&head, 11);
    push_front(&head, 10);
    push_front(&head, 8);
    push_front(&head, 3);
    push_front(&head, 4);
    push_front(&head, 2);
    push_front(&head, 1);
    printList(head);
    segregateEvenOdd(&head);
    printList(head);
    deleteList(&head);
    return 0;
}
