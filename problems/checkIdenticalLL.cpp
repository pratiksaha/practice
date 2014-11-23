//check if two lists are identical
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
    temp->next = (*head);
    (*head) = temp;
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

bool checkIdentical(struct node *a, struct node *b) {
    while(true) {
        if(a == NULL && b == NULL)    
            return true;
        else if(a == NULL && b != NULL) 
            return false;
        else if(a != NULL && b == NULL) 
            return false;
        else if(a->data != b->data)
            return false;
        a = a->next; //we reach each here if a and b are not NULL and their data is same
        b = b->next;
    }
}       

int main() {
    struct node *a = NULL;
    struct node *b = NULL;
    push_front(&a, 1);
    push_front(&a, 2);
    push_front(&a, 3);   
    push_front(&b, 1);
    push_front(&b, 2);
    push_front(&b, 3);
    cout<<((checkIdentical(a, b))?"Lists are identical":"Lists are not identical")<<endl;
    push_front(&b, 3);
    cout<<((checkIdentical(a, b))?"Lists are identical":"Lists are not identical")<<endl;
    deleteList(&a);
    deleteList(&b);
    return 0;
}
