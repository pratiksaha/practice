//to swap nodes of a Linked List without swapping data
#include<iostream>
#include<cstdlib>
using namespace std;

struct node {
    int data;
    struct node *next;
};

void swapNodes(struct node **head_ref, int x, int y) {
    if (x==y) //nothing to do if x and y are same
        return;
    struct node *prevX = NULL, *currX = *head_ref;
    while (currX && currX->data != x) { //search for x
        prevX = currX;
        currX = currX->next;
    }
    struct node *prevY = NULL, *currY = *head_ref;
    while (currY && currY->data != y) { //search for y
        prevY = currY;
        currY = currY->next;
    }
    if (currX == NULL || currY == NULL) //nothing to do if one of x or y is not found
        return;
    if (prevX != NULL) //if x is not head of linked list
        prevX->next = currY;
    else //make y as new head
        *head_ref = currY;  
    if (prevY != NULL) //if y is not head of linked list
        prevY->next = currX;
    else //make y as new head
        *head_ref = currX;
    struct node *temp = currY->next; //swap next pointers
    currY->next = currX->next;
    currX->next  = temp;
}

struct node* getNode() {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL) {
        cout<<"Memory Full"<<endl;
    }
    return temp;
}

void push_front(struct node **head, int key) {
    struct node* temp = getNode();
    temp->data = key;
    temp->next = *head;
    *head = temp;
}

void printList(struct node *head) {
    cout<<"Linked List :";
    while(head != NULL) {
        cout<<" "<<head->data;
        head = head->next;
    }
    cout<<endl;
}

int main() {
    struct node *start = NULL;
    push_front(&start, 7);
    push_front(&start, 6);
    push_front(&start, 5);
    push_front(&start, 4);
    push_front(&start, 3);
    push_front(&start, 2);
    push_front(&start, 1);
    printList(start);
    swapNodes(&start, 6, 2);
    printList(start);
    return 0;
}
