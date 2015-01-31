//delete a node in a linked list under constraints
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

void deleteNode(struct node *node)  { //delete a node given only the node to be deleted
    if (node->next == NULL) {
        cout<<"Cannot delete the last node\n";
    } else {
        struct node *temp = node->next;
        node->data    = temp->data;
        node->next    = temp->next;
        free(temp);
    }
}

void deleteNode(struct node *head, struct node *node) { //delete a node without using double pointer or global pointer or returning a pointer
    if (head == node) {
        if(head->next == NULL) {
            cout<<"List cannot be made empty\n";
        } else {
            head->data = head->next->data;
            node = head->next;
            head->next = head->next->next;
            free(node);
        }
    } else {
        struct node *prev = head;
        while(prev->next != NULL && prev->next != node)
            prev = prev->next;
        if (prev->next == NULL) {
            cout<<"Node is not present in Linked List\n";
        } else {
            prev->next = prev->next->next;
            free(node);
        }
    }
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
    deleteNode(head, head);
    deleteNode(head, head->next->next->next->next);
    deleteNode(head);
    deleteNode(head->next);
    printList(head);
    return 0;
}
