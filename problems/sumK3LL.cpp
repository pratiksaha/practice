//find a triplet from three linked lists with sum equal to a given number
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

bool findK(struct node *A, struct node *B, struct node *C, int key) {
    struct node *a = A;
    while (a != NULL) {
        struct node *b = B;
        struct node *c = C;
        while (b != NULL && c != NULL) {
            int sum = a->data + b->data + c->data;
            if (sum == key) {
                cout<<"Triplet Found: "<<a->data<<" "<<b->data<<" "<<c->data<<endl;
                return true;
            } else if (sum < key) {
                b = b->next;
            } else {
                c = c->next;
            }
        }
        a = a->next;
    }
    cout<<"No such triplet\n";
    return false;
}

int main() {
    struct node* A = NULL;
    struct node* B = NULL;
    struct node* C = NULL;
    push_front(&A, 20);
    push_front(&A, 4);
    push_front(&A, 15);
    push_front(&A, 10);
    push_front(&B, 10);
    push_front(&B, 9);
    push_front(&B, 4);
    push_front(&B, 2);
    push_front(&C, 1);
    push_front(&C, 2);
    push_front(&C, 4);
    push_front(&C, 8);
    findK(A, B, C, 25);
    deleteList(&A);
    deleteList(&B);
    deleteList(&C);
    return 0;
}
