//reverse every alternate groups of k
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

struct node *reverseAltK(struct node *head, int k) {
    struct node* curr = head;
    struct node* next;
    struct node* prev = NULL;
    int count = 0;
    while (curr != NULL && count < k) { //reverse first k nodes of the linked list
        next  = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    } 
    if(head != NULL) //change next of head to (k+1)th node
        head->next = curr;  
    count = 0;
    while(count < k-1 && curr != NULL ) { //skip next k nodes
        curr = curr->next;
        count++;
    }
    if(curr !=  NULL)
        curr->next = reverseAltK(curr->next, k); //recursively call for the list starting from curr->next
    return prev; //prev is new head of the input list
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
    head = reverseAltK(head, 3);
    printList(head);
    deleteList(&head);
    return 0;
}
