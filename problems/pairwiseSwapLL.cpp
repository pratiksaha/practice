//pairwise swap in lists
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

void pairWiseSwapItr(struct node *node) {
    while (node != NULL && node->next != NULL) {
        swap(node->data, node->next->data);
        node = node->next->next;
    }
}

void pairWiseSwapRecr(struct node *node) {
    if(node != NULL && node->next != NULL) {
        swap(node->data, node->next->data);
        pairWiseSwapRecr(node->next->next);
    } 
}

void pairWiseSwapLink(struct node **node) {
    if (*node == NULL || (*node)->next == NULL)
        return;
    struct node *prev = *node;
    struct node *curr = (*node)->next;
    *node = curr;
    struct node *next;
    while (true) {
        next = curr->next;
        curr->next = prev;
        if (next == NULL || next->next == NULL) { //if next is NULL or next is the last node
            prev->next = next;
            break;
        }
        prev->next = next->next;
        prev = next;
        curr = prev->next;
    }
}

int main() {
    struct node *head = NULL;
    push_front(&head, 5);
    push_front(&head, 4);
    push_front(&head, 3);
    push_front(&head, 2);
    push_front(&head, 1);
    printList(head);
    pairWiseSwapItr(head);
    printList(head);
    pairWiseSwapRecr(head);
    printList(head);
    pairWiseSwapLink(&head);
    printList(head);
    deleteList(&head);
    return 0;
}
