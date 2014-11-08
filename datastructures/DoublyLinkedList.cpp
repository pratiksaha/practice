//Doubly Linked List
#include<iostream>
#include<cstdlib>
using namespace std;

struct node {
    int data;
    struct node *prev, *next;
};

struct node* getNode(int key) {
    struct node* temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL) {
        cout<<"Memory overflow\n";
        exit(1);
    } else {
        temp->data = key;
        temp->prev = NULL;
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
        *head = temp;
    } else {
        temp->next = *head;
        temp->prev = NULL;
        (*head)->prev = temp;
        *head = temp;
    }
}

void push_back(struct node** head, int key) {
    struct node *temp = getNode(key);
    if (*head == NULL) {
        *head = temp;
    } else {
        struct node *last = *head;
        while(last->next != NULL)
            last = last->next;
        last->next = temp;
        temp->prev = last;
        temp->next = NULL;
    }
}

void deleteNode(struct node **head, struct node *del) {
    if(*head == NULL || del == NULL)//check consistency
        return;
    if(del->next == NULL && del->prev == NULL) //if node is the only node in the list
        *head = NULL;
    if(*head == del) //if node to be deleted is head node
        *head = del->next;
    if(del->next != NULL) //if node to be deleted is not the last node
        del->next->prev = del->prev;
    if(del->prev != NULL) //if node to be deleted is not the first node
        del->prev->next = del->next;
    free(del);
} 

void pop_front(struct node** head) {
    if (isEmpty(*head)) {
        cout<<"List is empty\n";
    } else {
        struct node *temp = *head;
        if(temp->next != NULL) {
            *head = (*head)->next;
            (*head)->prev = NULL;
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
        while(temp->next != NULL)
            temp = temp->next;
        if(temp->prev != NULL) {
            temp->prev->next = NULL;         
        } else {
            *head = NULL;
        }
        free(temp);
    }
}

int getFront(struct node* head) {
    if (isEmpty(head)) {
        cout<<"List is empty\n";
        return NULL;
    } else {
        return head->data;
    }
}

int getBack(struct node* head) {
    if (isEmpty(head)) {
        cout<<"List is empty\n";
        return NULL;
    } else {
        struct node *temp = head;
        while(temp->next != NULL)
            temp = temp->next;
        return temp->data;
    }
}

void reverse(struct node **head) {
    struct node *temp = NULL; 
    struct node *curr = *head;
    while (curr !=  NULL) {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;             
        curr = curr->prev;
    }
    if(temp != NULL )
        *head = temp->prev;
}

void deleteList(struct node **head) {
    if(isEmpty(*head)) {
        cout<<"List is Empty\n";
    } else {
        struct node *curr = (*head);
        struct node *next;
        while(curr != NULL){
            next = curr->next;
            free(curr);
            curr = next;
        }
        *head = NULL;
    }
}

void printList(struct node *node) {
    if (isEmpty(node)){
        cout<<"List is Empty\n";
    } else {
        struct node *last;
        cout<<"Traversal in forward direction :";
        while(node != NULL) {
            cout<<" "<<node->data;
            last = node;
            node = node->next;
        }
        cout<<endl;
        cout<<"Traversal in reverse direction :";
        while (last != NULL) {
            cout<<" "<<last->data;
            last = last->prev;
        }
        cout<<endl;
    }
}

int main() {
    struct node* head = NULL;
    push_back(&head, 6);
    push_back(&head, 7);
    push_back(&head, 8);
    push_back(&head, 9);
    push_front(&head, 5);
    push_front(&head, 4);
    push_front(&head, 3);
    push_front(&head, 2);
    push_front(&head, 1);
    cout<<"Front :"<<getFront(head)<<" Rear :"<<getBack(head)<<endl;
    printList(head);
    pop_front(&head);
    pop_back(&head);
    deleteNode(&head, head->next->next->next);
    reverse(&head);
    cout<<"Front :"<<getFront(head)<<" Rear :"<<getBack(head)<<endl;
    printList(head);
    pop_front(&head);
    pop_front(&head);
    pop_front(&head);
    pop_front(&head);
    pop_front(&head);
    pop_front(&head);
    printList(head);
    push_back(&head, 7);
    push_back(&head, 8);
    push_back(&head, 9);
    push_front(&head, 5);
    push_front(&head, 4);
    push_front(&head, 3);
    push_front(&head, 2);
    printList(head);
    pop_back(&head);
    pop_back(&head);
    pop_back(&head);
    pop_back(&head);
    pop_back(&head);
    pop_back(&head);
    pop_back(&head);
    printList(head);
    return 0;
}
