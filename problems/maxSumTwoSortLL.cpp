//construct a linked list that contains maximum sum path from start to end
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

struct node* finalMaxSumList(struct node *a, struct node *b) {
    struct node *result = NULL;
    struct node *pre1 = a, *curr1 = a;
    struct node *pre2 = b, *curr2 = b;
    while (curr1 != NULL || curr2 != NULL) {
        int sum1 = 0, sum2 = 0;
        while (curr1!=NULL && curr2!=NULL && curr1->data!=curr2->data) {
            if (curr1->data < curr2->data) {
                sum1 += curr1->data;
                curr1 = curr1->next;
            } else {
                sum2 += curr2->data;
                curr2 = curr2->next;
            }
        }
        if (curr1 == NULL) {
            while (curr2 != NULL) {
                sum2 += curr2->data;
                curr2 = curr2->next;
            }
        }
        if (curr2 == NULL) {
            while (curr1 != NULL) {
                sum1 += curr1->data;
                curr1 = curr1->next;
            }
        }
        if (pre1 == a && pre2 == b) {
            result = (sum1 > sum2)? pre1 : pre2;
        } else {
            if (sum1 > sum2)
                pre2->next = pre1->next;
            else
                pre1->next = pre2->next;
        }
        pre1 = curr1, pre2 = curr2;
        if (curr1)
            curr1 = curr1->next;
        if (curr2)
            curr2 = curr2->next;
    }
    return result;
}

int main() {
    struct node *head1 = NULL, *head2 = NULL, *res = NULL;
    push_front(&head1, 120);
    push_front(&head1, 110);
    push_front(&head1, 90);
    push_front(&head1, 30);
    push_front(&head1, 3);
    push_front(&head1, 1);
    push_front(&head2, 130);
    push_front(&head2, 120);
    push_front(&head2, 100);
    push_front(&head2, 90);
    push_front(&head2, 32);
    push_front(&head2, 12);
    push_front(&head2, 3);
    push_front(&head2, 0);
    cout<<"First ", printList(head1);
    cout<<"Second ", printList(head2);
    res = finalMaxSumList(head1, head2);
    cout<<"Result ", printList(res);
    return 0;
}
