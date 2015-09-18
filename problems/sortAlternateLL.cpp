//sort a linked list that is alternatively sorted in increasing and decreasing order
#include<iostream>
#include<cstdlib>
using namespace std;

struct node {
    int data;
    struct node *next;
};

struct node* getNode(int key) { //alocate memory
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL) {
        cout<<"Memory Full"<<endl;
    }
    temp->data = key;
    temp->next = NULL;
    return temp;
}

void printList(struct node *head) { //print the list
    cout<<"Linked List :";
    while(head != NULL) {
        cout<<" "<<head->data;
        head = head->next;
    }
    cout<<endl;
}

void splitList(struct node *head, struct node **Ahead, struct node **Dhead) {  
    *Ahead = getNode(0);
    *Dhead = getNode(0);
    struct node *ascn = *Ahead;
    struct node *dscn = *Dhead;
    struct node *curr = head;
    while (curr) {
        ascn->next = curr;
        ascn = ascn->next;
        curr = curr->next;
        if (curr) {
            dscn->next = curr;
            dscn = dscn->next;
            curr = curr->next;
        }
    }
    ascn->next = NULL;
    dscn->next = NULL;
    *Ahead = (*Ahead)->next;
    *Dhead = (*Dhead)->next;
}

void reverselist(struct node *&head) {
    struct node* prev = NULL, *curr = head, *next;
    while (curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

struct node *mergelist(struct node *head1, struct node *head2) {
    if (!head1)
        return head2;
    if (!head2)
        return head1;
    struct node *temp = NULL;
    if (head1->data < head2->data) {
        temp = head1;
        head1->next = mergelist(head1->next, head2);
    } else {
        temp = head2;
        head2->next = mergelist(head1, head2->next);
    }
    return temp;
}

void sortAlternate(struct node **head) {
    struct node *Ahead, *Dhead;
    splitList(*head, &Ahead, &Dhead);
    reverselist(Dhead);
    *head = mergelist(Ahead, Dhead);
}

int main() {
    struct node *head = getNode(10);
    head->next = getNode(40);
    head->next->next = getNode(53);
    head->next->next->next = getNode(30);
    head->next->next->next->next = getNode(67);
    head->next->next->next->next->next = getNode(12);
    head->next->next->next->next->next->next = getNode(89);
    printList(head);
    sortAlternate(&head);
    printList(head);
    return 0;
}
