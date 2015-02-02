//clone a list with next and arbit pointer
#include<iostream>
#include<cstdlib>
using namespace std;

struct node {
    int data;
    struct node *next;
    struct node *arbit;
};

struct node* getNode(int key) { //alocate memory
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL) {
        cout<<"Memory Full"<<endl;
    }
    temp->data = key;
    temp->next = NULL;
    temp->arbit = NULL;
    return temp;
}

void printList(struct node *head) { //print the list
    while(head != NULL) {
        cout<<head->data<<" "<<head->arbit->data<<endl;
        head = head->next;
    }
}

struct node *clone(struct node *orig) {//clone the original list
    struct node *copy = NULL;
    struct node *curr = orig;
    while (curr) {
        struct node *temp = getNode(curr->data);
        temp->next = curr->next;
        curr->next = temp;
        curr = curr->next->next;
    }
    curr = orig;
    while (curr) {
        curr->next->arbit = curr->arbit->next;
        curr = curr->next->next;
    }   
    copy = orig->next;
    curr = copy;
    while (orig->next->next) {
        orig->next = orig->next->next;
        orig = orig->next;
        curr->next = orig->next;
        curr = curr->next;
    }
    orig->next = NULL;
    return copy;
}

int main() {
    struct node *org = getNode(1);
    org->next = getNode(2);
    org->next->next = getNode(3);
    org->next->next->next = getNode(4);
    org->next->next->next->next = getNode(5);
    org->arbit = org->next->next;
    org->next->arbit = org;
    org->next->next->arbit = org->next->next->next->next;
    org->next->next->next->arbit = org->next->next;
    org->next->next->next->next->arbit = org->next;
    struct node *dup = clone(org);
    cout<<"Original List :\n", printList(org);
    cout<<"Duplicate List :\n", printList(dup); 
    return 0;
} 
