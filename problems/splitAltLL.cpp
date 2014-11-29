//split a list intp two taking nodes alternately
#include<iostream>
#include<cstdlib>
#include<cassert>
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

void MoveNode(struct node** destRef, struct node** sourceRef) {
    struct node* newNode = *sourceRef;
    assert(newNode != NULL);
    *sourceRef = newNode->next;
    newNode->next = *destRef;
    *destRef = newNode;
}

void splitAlt(struct node* source, struct node** aRef, struct node** bRef) {
    struct node aDummy;
    struct node* aTail = &aDummy; 
    struct node bDummy;
    struct node* bTail = &bDummy;
    struct node* curr = source;
    aDummy.next = NULL;
    bDummy.next = NULL;
    while (curr != NULL) {
        MoveNode(&(aTail->next), &curr);
        aTail = aTail->next; 
        if (curr != NULL) {
            MoveNode(&(bTail->next), &curr);
            bTail = bTail->next;
        }
    }
    *aRef = aDummy.next;
    *bRef = bDummy.next;
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
    struct node *a = NULL;
    struct node *b = NULL;
    splitAlt(head, &a, &b);
    printList(a);
    printList(b);
    deleteList(&head);
    deleteList(&a);
    deleteList(&b);
    return 0;
}
