//to replace arbit pointer of all nodes with the next higher node
#include<iostream>
#include<cstdlib>
using namespace std;

struct node {
    int data;
    struct node *next, *arbit;
};

void listSplit(struct node* head, struct node** left, struct node** right) { //split head list into left and right
    if (head==NULL || head->arbit==NULL) { //length < 2 cases
        *left = head;
        *right = NULL;
    } else { //tortoise and hare
        struct node* slow = head;
        struct node* fast = head->arbit;
        while (fast) {
            fast = fast->arbit;
            if (fast) {
                slow = slow->arbit;
                fast = fast->arbit;
            }
        }
        *left = head;
        *right = slow->arbit;
        slow->arbit = NULL;
    }
}

struct node* merge(struct node* a, struct node* b) {
    if (a==NULL) {
        return b;
    } else if (b==NULL) {
        return a;
    } else {
        struct node* result = NULL;
        if (a->data <= b->data) {
            result = a;
            result->arbit = merge(a->arbit, b);
        } else {
            result = b;
            result->arbit = merge(a, b->arbit);
        }
        return result;
    }
}

void mergeSort(struct node** headRef) {
    struct node* head = *headRef;
    if (head && head->arbit) { //proceed only if head contains more than 1 element
        struct node* a;
        struct node* b;
        listSplit(head, &a, &b);
        mergeSort(&a);
        mergeSort(&b);
        *headRef = merge(a, b);
    }
}

struct node* arbitNextHigh(struct node *head) {
    struct node *temp = head;
    while (temp != NULL) { //copy next pointers to arbit pointers
        temp->arbit = temp->next;
        temp = temp->next;
    }
    mergeSort(&head);
    return head;
}

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
    temp->arbit = NULL;
    *head = temp;
}

void printList(struct node *head, struct node *ahead) { //print the list
    cout<<"Linked List Traversal with next pointer:";
    while(head != NULL) {
        cout<<" "<<head->data;
        head = head->next;
    }
    cout<<endl;
    cout<<"Linked List Traversal with arbitrary pointer:";
    while(ahead != NULL) {
        cout<<" "<<ahead->data;
        ahead = ahead->arbit;
    }
    cout<<endl;
}

int main() {
    struct node* head = NULL;
    push_front(&head, 3);
    push_front(&head, 2);
    push_front(&head, 10);
    push_front(&head, 5);
    struct node *ahead = arbitNextHigh(head);
    printList(head, ahead);
    return 0;
}
