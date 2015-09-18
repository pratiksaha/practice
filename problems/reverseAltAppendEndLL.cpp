//to reverse alternate nodes and append them to end of list
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

void printList(struct node *head) { //print the list
    cout<<"Linked List :";
    while(head != NULL) {
        cout<<" "<<head->data;
        head = head->next;
    }
    cout<<endl;
}

void push_front(struct node **head, int key) { //add node in the front
    struct node* temp = getNode();
    temp->data = key;
    temp->next = *head;
    *head = temp;
}

void reverseAltAppendEnd(struct node *odd) {
    if (odd == NULL || odd->next == NULL || odd->next->next == NULL) //no change is required if linked list has less than 3 node
        return; 
    struct node *even = odd->next;
    odd->next = odd->next->next;
    odd = odd->next;
    even->next = NULL;
    while (odd && odd->next) {
       struct node *temp = odd->next->next;
       odd->next->next = even;
       even = odd->next;
       odd->next = temp;
       if (temp)
         odd = temp;
    }
    odd->next = even;
}

int main() {
    struct node *head = NULL;
    push_front(&head, 7);
    push_front(&head, 6);
    push_front(&head, 5);
    push_front(&head, 4);
    push_front(&head, 3);
    push_front(&head, 2);
    push_front(&head, 1);
    printList(head);
    reverseAltAppendEnd(head);
    printList(head);
    return 0;
}
