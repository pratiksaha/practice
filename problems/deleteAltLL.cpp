//delete alternate nodes of list
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

void deleteAlt(struct node *head) {
    if(head) {
        struct node *prev = head;
        struct node *node = head->next;
        while (prev != NULL && node != NULL) {
            prev->next = node->next;  
            free(node);
            prev = prev->next;
            if(prev != NULL)
                node = prev->next;
        }
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
    push_front(&head, 1);;
    printList(head);
    deleteAlt(head);
    printList(head);
    deleteList(&head);
    return 0;
}
