//Linked List
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

void printListReverse(struct node* head) { //print list in reverse
    if(head == NULL)
        return;
    printListReverse(head->next);
    cout<<" "<<head->data;
}

void getMiddle(struct node *head) { //get the middle of the list
    struct node *slow_ptr = head;
    struct node *fast_ptr = head;
    if(head != NULL) {
        while(fast_ptr != NULL && fast_ptr->next != NULL) {
            fast_ptr = fast_ptr->next->next;
            slow_ptr = slow_ptr->next;
        }
        cout<<"Middle element : "<<slow_ptr->data<<endl;
    }
}

int getCount(struct node *head, int key) { //No of occurences of the given key in the list
    struct node *temp = head;
    int count = 0;
    while(temp != NULL) {
        if (temp->data == key)
            count++;
         temp = temp->next;
    }
    return count;
}

int getSize(struct node *head) { //No of nodes in the list
    struct node *temp = head;
    int count = 0;
    while(temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

void push_front(struct node **head, int key) { //add node in the front
    struct node* temp = getNode();
    temp->data = key;
    temp->next = *head;
    *head = temp;
}

void push_back(struct node **head, int key) { //add node at the back
    struct node *temp = getNode();
    temp->data = key;
    temp->next = NULL;
    if (*head == NULL) {       
        *head = temp;
    } else {
        struct node *last = *head;
        while(last->next != NULL)
            last = last->next;
        last->next = temp;
    }
}

void push_at(struct node **head, int pos, int key) { //add node at the given pos
    int len = getSize(*head);
    if(pos > len+1) {
        cout<<"There are less than "<<pos<<" elements in the list"<<endl;
    }else if(pos == 0) {
        push_front(head, key);
    } else if (pos == len+1) {
        push_back(head, key);
    } else {
        struct node *temp = getNode();
        temp->data = key;
        temp->next == NULL;
        struct node *curr = *head;
        for(int i=0; i<pos-1; i++)
            curr = curr->next;
        temp->next = curr->next;
        curr->next = temp;
    }
}

void pop_front(struct node **head) { //remove node from the front
    if(*head == NULL){
        cout<<"List is empty"<<endl;
    } else {
        struct node *temp = *head;
        if((*head)->next == NULL) {
            *head = NULL;
            free(temp);   
        } else {
            *head = (*head)->next;
            free(temp);
        }
    }
}

void pop_back(struct node **head) { //remove node from the back
    if(*head == NULL) {
        cout<<"List is empty"<<endl;
    } else {
        struct node *temp = *head;
        if((*head)->next == NULL) {
            *head = NULL;
            free(temp);   
        } else {
            struct node *prev = NULL;
            while(temp->next != NULL) {
                prev = temp;
                temp = temp->next;
            }
            prev->next = NULL;
            free(temp);
        }
    }
}

void pop_at(struct node **head, int pos) { //remove node from the given pos
    if(*head == NULL) {
        cout<<"List is empty"<<endl;
    } else {
        int len = getSize(*head);
        if(pos > len) {
            cout<<"There are less than "<<pos<<" elements in the list"<<endl;
        }else if(pos == 0) {
            pop_front(head);
        } else if (pos == len) {
            pop_back(head);
        } else {
            struct node *curr = *head;
            for(int i=0; i<pos-1; i++)
                curr = curr->next;
            struct node *temp = curr->next;
            curr->next = temp->next;
            free(temp);
        }
    }
}

int getNthNodeFromBeg(struct node* head, int pos) { //get pos'th node from the beginning
    int len = getSize(head);
    if (pos > len) {
        cout<<"Given position "<<pos<<" is beyond the linked list of size "<<len<<endl;
        return NULL;
    } else {
        struct node* temp = head;
        int count = 0;
        while (count < pos-1) {
            count++;
            temp = temp->next;
        }
        return temp->data;
    }
}

int getNthNodeFromEnd(struct node* head, int pos) { //get pos'th node from the end
    int len = getSize(head);
    if (pos > len) {
        cout<<"Given position "<<pos<<" is beyond the linked list of size "<<len<<endl;
        return NULL;
    } else {
        struct node* temp = head;
        int count = 0;
        while (count<len-pos) {
            count++;
            temp = temp->next;
        }
        return temp->data;
    }
}

void reverse(struct node **head) { //reverse a list
    struct node* prev = NULL;
    struct node* curr = *head;
    struct node* next;
    while (curr != NULL) {
        next  = curr->next; 
        curr->next = prev;  
        prev = curr;
        curr = next;
    }
    *head = prev;
}

void reverseRec(struct node **head) { //reverse a list recursively
    if (*head) {
        struct node* first = *head;
        struct node* rest = first->next;
        if (rest) {
            reverseRec(&rest);
            first->next->next = first;
            first->next = NULL;
            *head = rest;
        }
    }
}

void rotateCounterClockwise(struct node **head, int k) { //rotate a list k times in Counter Clockwise direction
    if (k == 0 || k>getSize(*head))
        return;

    struct node* curr = *head;
 
    int count = 1;
    while (count < k && curr != NULL) {
        curr = curr->next;
        count++;
    }
    if (curr == NULL)
        return;
    struct node *kthNode = curr;
 
    while (curr->next != NULL)
        curr = curr->next;
 
    curr->next = *head;
    *head = kthNode->next;
    kthNode->next = NULL;
}

void rotateClockwise(struct node **head, int k) { //rotate a list k times in Clockwise direction
    int len = getSize(*head);
    if (k == 0 || k>getSize(*head))
        return;
    rotateCounterClockwise(head, len-k);
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

int main() {
    struct node *l = NULL;
    push_back(&l, 1);
    push_back(&l, 2);
    push_back(&l, 3);
    cout<<"List in reverse order :";
    printListReverse(l);
    cout<<endl;
    getMiddle(l);
    cout<<"Size : "<<getSize(l)<<endl;
    cout<<"Count of 5 : "<<getCount(l, 5)<<endl;
    cout<<"Count of 2 : "<<getCount(l, 2)<<endl;
    printList(l);
    pop_back(&l);
    pop_back(&l);
    pop_back(&l);
    printList(l);
    push_front(&l, 1);
    push_front(&l, 2);
    push_front(&l, 3);
    printList(l);
    cout<<"pos 1 from begnning "<<getNthNodeFromBeg(l,1)<<endl;
    cout<<"pos 1 from end "<<getNthNodeFromEnd(l,1)<<endl;
    pop_front(&l);
    pop_front(&l);
    pop_front(&l);
    printList(l);
    push_at(&l, 3, 11);
    printList(l);
    push_at(&l, 1, 11);
    printList(l);
    push_at(&l, 0, 6);
    printList(l);
    push_at(&l, 0, 5);
    printList(l);
    push_at(&l, 2, 7);
    printList(l);
    push_at(&l, 2, 19);
    printList(l);
    push_at(&l, 2, 76);
    printList(l);
    push_at(&l, 2, 23);
    printList(l);
    pop_at(&l, 8);
    printList(l);
    pop_at(&l, 7);
    printList(l);
    pop_at(&l, 0);
    printList(l);
    pop_at(&l, 2);
    printList(l);
    reverse(&l);
    printList(l);
    reverseRec(&l);
    printList(l);
    rotateCounterClockwise(&l, 2);
    printList(l);
    rotateClockwise(&l, 1);
    printList(l);
    deleteList(&l);
    printList(l);
    return 0;
}
