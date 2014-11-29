//move last node to front of list
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

void moveLastFirst(struct node **node) { 
    if(*node == NULL || (*node)->next == NULL)
        return;
    struct node *secLast = NULL;
    struct node *last = *node;
    while(last->next != NULL) {
        secLast = last;
        last = last->next;
    }                
    secLast->next = NULL; //set the next of second last as NULL
    last->next = *node; //set next of last as head node
    *node = last;  //set head to last node  
}

int main() {
    struct node *head = NULL;
    push_front(&head, 5);
    push_front(&head, 4);
    push_front(&head, 3);
    push_front(&head, 2);
    push_front(&head, 1);
    printList(head);
    moveLastFirst(&head);
    printList(head);
    deleteList(&head);
    return 0;
}
