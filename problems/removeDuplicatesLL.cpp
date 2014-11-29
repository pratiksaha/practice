//remove duplicates
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

void removeDuplicatesSorted(struct node* head) {
    struct node* curr = head;
    struct node* next;
    if(curr) {
        while(curr->next != NULL) {
            if(curr->data == curr->next->data) {            
                next = curr->next->next;
                free(curr->next);
                curr->next = next; 
            } else {
                curr = curr->next;
            }
        }
    }
}

void removeDuplicatesUnsorted(struct node *head) {
    struct node *ptr1, *ptr2, *dup;
    ptr1 = head;
    while(ptr1 != NULL && ptr1->next != NULL) {
        ptr2 = ptr1;
        while(ptr2->next != NULL) {
            if(ptr1->data == ptr2->next->data) {
                dup = ptr2->next;
                ptr2->next = ptr2->next->next;
                free(dup);
            } else {
                ptr2 = ptr2->next;
            }
        }
        ptr1 = ptr1->next;
    }
}

int main() {
    struct node *sl = NULL;
    struct node *ul = NULL;
    push_front(&sl, 20);
    push_front(&sl, 13);
    push_front(&sl, 13); 
    push_front(&sl, 11);
    push_front(&sl, 11);
    push_front(&sl, 11);
    push_front(&ul, 10);
    push_front(&ul, 11);
    push_front(&ul, 12);
    push_front(&ul, 11);
    push_front(&ul, 11);
    push_front(&ul, 12);
    push_front(&ul, 10);
    printList(sl);
    removeDuplicatesSorted(sl);
    printList(sl);
    printList(ul);
    removeDuplicatesUnsorted(ul);
    printList(ul);
    deleteList(&sl);
    deleteList(&ul);
    return 0;
}
