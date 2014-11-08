//Stack
#include<iostream>
#include<cstdlib>
using namespace std; 

struct node  {
    int data;
    struct node *next;
};

struct node* getNode(int key) {
    struct node* temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL) {
        cout<<"Stack is full\n";
        exit(1);
    } else {
        temp->data = key;
        temp->next = NULL;
    }
    return temp;
}

bool isEmpty(struct node *top) {
    return (top)?false:true;
}

void printStack(struct node* top) {
    cout<<"Stack Contents\n";
    while(!isEmpty(top)) {
        cout<<top->data<<endl;
        top = top->next;
    }
}

void push(struct node **top, int key) {
    struct node *temp = getNode(key);
    temp->next = *top;
    *top = temp;
}

void pop(struct node **top) {
    if(isEmpty(*top)) {
        cout<<"Stack is Empty\n";
    } else {
        struct node *temp = *top;
        *top = (*top)->next;
        free(temp);
    }
}

int getTop(struct node *top) {
    if(isEmpty(top)) {
        cout<<"Stack is Empty\n";
        return NULL;
    } else {
        return top->data;
    }
}

void deleteStack(struct node **top) {
    struct node* curr = *top;
    struct node* next;
    while(curr != NULL) {
        next = curr->next;
        free(curr);
        curr = next;
    }
    *top = NULL;
}

void insertAtBottom(struct node** top, int key) { 
    if(isEmpty(*top)) { 
        push(top, key);
    } else {
        int temp = getTop(*top);
        pop(top);
        insertAtBottom(top, key);
        push(top, temp);
    }            
}
void reverseStack(struct node** top) {  
    if(!isEmpty(*top)) {
        int temp = getTop(*top);
        pop(top);                     
        reverseStack(top);
        insertAtBottom(top, temp);
    }     
}  

int main() {
    struct node* top = NULL;
    cout<<"Stack top is "<<getTop(top)<<endl;
    push(&top, 10);
    push(&top, 20);
    cout<<"Stack top is "<<getTop(top)<<endl;
    push(&top, 30);
    printStack(top);
    pop(&top);
    push(&top, 40);
    push(&top, 50);
    printStack(top);
    reverseStack(&top);
    printStack(top);
    deleteStack(&top);
    getTop(top);
    return 0;
}
