//get the point where two linked list merge
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

void printList(struct node *head) { //print the list
    cout<<"Linked List :";
    while(head != NULL) {
        cout<<" "<<head->data;
        head = head->next;
    }
    cout<<endl;
}

int getCount(struct node* node) {
    int count = 0;
    while (node != NULL) {
        count++;
        node = node->next;
    }
    return count;
}

int findIntesectionUtil(int d, struct node* head1, struct node* head2) {
    struct node* curr1 = head1;
    struct node* curr2 = head2;
    for(int i = 0; i < d; i++) {
        if(curr1 == NULL)
            return -1;
        curr1 = curr1->next;
    }
    while(curr1 !=  NULL && curr2 != NULL) {
        if(curr1 == curr2)
            return curr1->data;
        curr1= curr1->next;
        curr2= curr2->next;
    }
    return -1;
}

int findIntesection(struct node* head1, struct node* head2) {
    int c1 = getCount(head1);
    int c2 = getCount(head2);
    if(c1 > c2)
        return findIntesectionUtil(c1-c2, head1, head2);
    else
        return findIntesectionUtil(c2-c1, head2, head1);
}

int main() {
    struct node *h1 = NULL;
    struct node *h2 = NULL;
    push_front(&h1, 30);
    push_front(&h1, 15);
    push_front(&h1, 9);
    push_front(&h1, 6);
    push_front(&h1, 3);
    push_front(&h2, 10);
    h2->next = h1->next->next->next;
    cout<<"Intersection node is :"<<findIntesection(h1, h2)<<endl;
    return 0; 
}
