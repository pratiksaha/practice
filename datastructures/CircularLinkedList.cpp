//Circular Linked List
#include<iostream>
#include<cstdlib>
using namespace std;

struct node {
    int data;
    struct node *next;
};

struct node* getNode(int key) {
    struct node* temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL) {
        cout<<"Memory overflow\n";
        exit(1);
    } else {
        temp->data = key;
        temp->next = NULL;
    }
    return temp;
}

bool isEmpty(struct node *head) {
    return (head)?false:true;
}

void push_front(struct node** head, int key) {
    struct node *temp = getNode(key);
    if (*head == NULL) {
        temp->next = temp;
        *head = temp;
        
    } else {
        struct node *last = *head;
        while(last->next != *head)
            last = last->next;
        last->next = temp;
        temp->next = *head;
        *head = temp;
    }
}

void push_back(struct node** head, int key) {
    struct node *temp = getNode(key);
    if (*head == NULL) {
        temp->next = temp;
        *head = temp;
    } else {
        struct node *last = *head;
        while(last->next != *head)
            last = last->next;
        last->next = temp;
        temp->next = *head;
    }
}
 

void pop_front(struct node** head) {
    if (isEmpty(*head)) {
        cout<<"List is empty\n";
    } else {
        struct node *temp = *head;
        struct node *last = *head;
        while(last->next != *head)
            last = last->next;
        if (temp->next != *head ) {
            last->next = (*head)->next;
            *head = (*head)->next;
        } else {
            *head = NULL;
        }
        free(temp);
    }
}

void pop_back(struct node** head) {
    if (isEmpty(*head)) {
        cout<<"List is empty\n";
    } else {
        struct node *temp = *head;
        struct node *last = *head;
        struct node *prev = NULL;
        while(last->next != *head ) {
            prev = last;
            last = last->next;
        }
        if( prev == NULL) {
            *head = NULL;
        } else {
            prev->next = *head;
        }
        free(last);
    }
}


void deleteList(struct node **head) {
    if(isEmpty(*head)) {
        cout<<"List is Empty\n";
    } else {
        struct node *curr = (*head);
        struct node *next;
        while(curr != *head){
            next = curr->next;
            free(curr);
            curr = next;
        }
        *head = NULL;
    }
}

void printList(struct node *head) {
    if (isEmpty(head)){
        cout<<"List is Empty\n";
    } else {
        struct node *node = head;
        cout<<"Linked list :";
        while(node->next != head) {
            cout<<" "<<node->data;
            node = node->next;
        }
        cout<<endl;
    }
}

void sortedInsert(struct node** head, int key) {
    struct node *temp = getNode(key);
    struct node* curr = *head;
 
    if (curr == NULL) {
        temp->next = temp;
        *head = temp;
    } else if (curr->data >= temp->data) {
        while(curr->next != *head)
            curr = curr->next;
        curr->next = temp;
        temp->next = *head;
        *head = temp;
    } else {
        while(curr->next!= *head && curr->next->data<temp->data)
            curr = curr->next;
        temp->next = curr->next;
        curr->next = temp;
    }
}

void splitList(struct node *head, struct node **head1, struct node **head2) {
    struct node *slow_ptr = head;
    struct node *fast_ptr = head;
    if(head == NULL)
        return;
  
    while(fast_ptr->next != head && fast_ptr->next->next != head) {
        fast_ptr = fast_ptr->next->next;
        slow_ptr = slow_ptr->next;
    } 
    if(fast_ptr->next->next == head)
        fast_ptr = fast_ptr->next;     
   
    *head1 = head;   
      
    if(head->next != head)
        *head2 = slow_ptr->next;
 
    fast_ptr->next = slow_ptr->next;
    slow_ptr->next = head;      
}

int main() {
    struct node* head = NULL;
    push_back(&head, 6);
    push_back(&head, 7);
    push_back(&head, 8);
    push_back(&head, 9);
    push_front(&head, 4);
    push_front(&head, 3);
    push_front(&head, 2);
    push_front(&head, 1);
    printList(head);
    pop_front(&head);
    printList(head);
    pop_back(&head);
    printList(head);
    sortedInsert(&head, 5);
    printList(head);
    struct node *h1, *h2;
    splitList(head, &h1, &h2);
    deleteList(&head);
    printList(head);
    printList(h1);
    deleteList(&h1);
    printList(h2);
    deleteList(&h2);
    return 0;
}
