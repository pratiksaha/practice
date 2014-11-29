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

void sort012(struct node *head) {
    int count[3] = {0, 0, 0};
    struct node *ptr = head;
    while (ptr != NULL) {
        count[ptr->data] += 1;
        ptr = ptr->next;
    }
    int i = 0;
    ptr = head;
    while (ptr != NULL)
    {
        if (count[i] == 0) {
            ++i;
        } else {
            ptr->data = i;
            --count[i];
            ptr = ptr->next;
        }
    }
}

int main() {
    struct node *head = NULL;
    push_front(&head, 0);
    push_front(&head, 1);
    push_front(&head, 0);
    push_front(&head, 2);
    push_front(&head, 1);
    push_front(&head, 1);
    push_front(&head, 2);
    push_front(&head, 1);
    push_front(&head, 2);
    printList(head);
    sort012(head);
    printList(head);
    deleteList(&head);
    return 0;
}
