//detect and remove loop from a list
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

void correctLL(struct node *head) { //detect and remove loop
    struct node *loop, *slow, *fast, *ptr1, *ptr2;
    loop = NULL;
    slow = fast = head;
    while(slow && fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) { //if slow and fast meet, there is a loop
            loop = slow;
            break;
        }
    }
    if (loop) {
        int nloop = 1;
        ptr1 = ptr2 = loop;
        while(ptr1->next != ptr2) { //count no of nodes in loop
            ptr1 = ptr1->next;
            nloop++;
        }
        ptr1 = ptr2 = head;
        for (int i=0; i<nloop; i++) //move ptr2 nloop steps
            ptr2 = ptr2->next;
        while (ptr1 != ptr2) { //ptr1 and ptr2 meet at beginning of loop
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        ptr2 = ptr2->next;
        while (ptr2->next != ptr1) //get the end of loop
            ptr2 = ptr2->next;
        ptr2->next = NULL; //break the loop
        cout<<"Loop Removed"<<endl;
    } else {
        cout<<"No Loop Found"<<endl;
    }
}

int main() {
    struct node* head = NULL;
    push_front(&head, 7);
    push_front(&head, 6);
    push_front(&head, 5);
    push_front(&head, 4);
    push_front(&head, 3);
    push_front(&head, 2);
    push_front(&head, 1);
    correctLL(head);
    printList(head);
    head->next->next->next->next->next->next->next = head->next->next;
    correctLL(head);
    printList(head);
    return 0;
}
