//merge 2 sorted linked list in reverse
#include<bits/stdc++.h>
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

void deleteList(struct node **head) { //free all space used by the list
    struct node *curr = *head;
    struct node *next;
    while (curr != NULL) {
        next = curr->next;
        free(curr);
        curr = next;
    }
    *head = NULL;
}

struct node* reverseSortedMerge(struct node *a, struct node *b) {
    if (!a && !b)
        return NULL;
    struct node *res = NULL;
    while (a && b) {
        if (a->data <= b->data) {
            struct node *temp = a->next;
            a->next = res;
            res = a;
            a = temp;
        } else {
            struct node *temp = b->next;
            b->next = res;
            res = b;
            b = temp;
        }
    }
    while (a) {
        struct node *temp = a->next;
        a->next = res;
        res = a;
        a = temp;
    }
    while (b) {
        struct node *temp = b->next;
        b->next = res;
        res = b;
        b = temp;   
    }
    return res;
}


int main() {
    struct node *a = NULL;
    push_front(&a, 15);
    push_front(&a, 10);
    push_front(&a, 5);
    struct node *b = NULL;
    push_front(&b, 20);
    push_front(&b, 3);
    push_front(&b, 2);
    printList(a);
    printList(b);
    struct node *res = reverseSortedMerge(a, b);
    printList(res);
    deleteList(&res);
    return 0;
}
