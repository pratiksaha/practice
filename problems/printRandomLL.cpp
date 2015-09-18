//to randomly select a node from a singly linked list
#include<iostream>
#include<cstdlib>
#include<ctime>
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

void printRandom(struct node *head) {
    if (head == NULL)
       return;
    srand(time(NULL));
    int result = head->data;
    struct node *current = head;
    int n;
    for (n=2; current!=NULL; n++) {
        if (rand() % n == 0) //change result with probability 1/n
           result = current->data;
        current = current->next;
    }
   cout<<"Randomly selected key is "<<result<<endl;
}

int main() {
    struct node *head = NULL;
    push_front(&head, 40);
    push_front(&head, 20);
    push_front(&head, 4);
    push_front(&head, 3);
    push_front(&head, 30);
    push_front(&head, 15);
    printList(head);
    printRandom(head);
    return 0;
}
