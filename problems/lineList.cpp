//remove middle points from a list
#include<iostream>
#include<cstdlib>
#include<cassert>
using namespace std;

typedef struct Point {
    int x, y;
}Point;

struct node {
    Point data;
    struct node *next;
};

struct node* getNode() { //alocate memory
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL) {
        cout<<"Memory Full"<<endl;
    }
    return temp;
}

void push_front(struct node **head, int x, int y) { //add node in the front
    struct node* temp = getNode();
    temp->data.x = x;
    temp->data.y = y;
    temp->next = *head;
    *head = temp;
}

void printList(struct node *head) { //print the list
    cout<<"Linked List :";
    while(head != NULL) {
        cout<<" ("<<head->data.x<<","<<head->data.y<<")";
        head = head->next;
    }
    cout<<endl;
}

void deleteNode(struct node *Node, struct node *Next) { //delete a node
    Node->next = Next->next;
    Next->next = NULL;
    free(Next);
}

void modifyList(struct node **head) {
    struct node *curr = *head;
    while (curr) {
        if (curr && curr->next && curr->next->next) { //if there are more than 2 nodes
            struct node *Next = curr->next;
            struct node *NextNext = curr->next->next;
            if (curr->data.x == Next->data.x) { //same x value
                while(NextNext && Next->data.x==NextNext->data.x) {
                    deleteNode(curr, Next);
                    Next = NextNext;
                    NextNext = NextNext->next;
                }
            } else if (curr->data.y==Next->data.y) { //same y value
                while(NextNext && Next->data.y==NextNext->data.y) {
                    deleteNode(curr, Next);
                    Next = NextNext;
                    NextNext = NextNext->next;
                }
            } else {
                assert(0); //adjacent points must have either same x or same y
            }
        }
        curr = curr->next; 
    }
}

int main() {
    struct node *head1 = NULL;
    push_front(&head1, 40, 5);
    push_front(&head1, 20, 5);
    push_front(&head1, 10, 5);
    push_front(&head1, 10, 8);
    push_front(&head1, 10, 10);
    push_front(&head1, 3, 10);
    push_front(&head1, 1, 10);
    push_front(&head1, 0, 10);
    printList(head1);
    modifyList(&head1);
    printList(head1);
    struct node *head2 = NULL;
    push_front(&head2, 12, 3);
    push_front(&head2, 10, 3);
    push_front(&head2, 6, 3);
    push_front(&head2, 4, 3);
    push_front(&head2, 2, 3);
    printList(head2);
    modifyList(&head2);
    printList(head2);
    struct node *head3 = NULL;
    push_front(&head3, 40, 5);
    push_front(&head3, 20 ,5);
    push_front(&head3, 7, 5);
    push_front(&head3, 7, 10);
    push_front(&head3, 5, 10);
    push_front(&head3, 1, 10);
    push_front(&head3, 0, 10);
    printList(head3);
    modifyList(&head3);
    printList(head3);
    return 0;
}
