//Queue
#include<iostream>
#include<cstdlib>
using namespace std; 

struct node  {
    int data;
    struct node *next;
};

struct queue {
    struct node *front;
    struct node *rear;
};

struct node* getNode(int key) {
    struct node* temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL) {
        cout<<"Queue is full\n";
        exit(1);
    } else {
        temp->data = key;
        temp->next = NULL;
    }
    return temp;
}

bool isEmpty(struct queue q) {
    return (q.front == NULL && q.rear == NULL)?true:false;
}

void enQueue(struct queue *q, int key) {
    struct node *temp = getNode(key);
    if (isEmpty(*q)) {
       q->front = q->rear = temp;
    } else {
        q->rear->next = temp;
        q->rear = temp;
    }
}

void deQueue(struct queue *q ) {
    if (!isEmpty(*q)) {
        struct node *temp;
        temp = q->front;
        if (q->front == q->rear) {
            q->front = NULL;
            q->rear = NULL;
        } else {
            q->front = q->front->next;
        }
        free(temp);
    }
}

int getFront(struct queue q) {
    if (isEmpty(q)) {
       return NULL;
    } else {
        return q.front->data;
    }
}

int getRear(struct queue q) {
    if(isEmpty(q)) {
       return NULL;
    } else {
        return q.rear->data;
    }
}

void printQueue(struct queue q) {
    if(isEmpty(q)) {
        cout<<"Queue is Empty\n";
    } else {
        struct node *temp = q.front;
        while(temp != q.rear){
            cout<<" "<<temp->data;
            temp = temp->next;
        }
        cout<<" "<<temp->data<<endl;    
    }
}

void deleteQueue(struct queue *q) {
    if(isEmpty(*q)) {
        cout<<"Queue is Empty\n";
    } else {
        struct node *curr = q->front;
        struct node *next;
        while(curr != q->rear){
            next = curr->next;
            free(curr);
            curr = next;
        }
        free(curr);
        q->front = NULL;
        q->rear = NULL;
    }
}

int main() {
    struct queue q;
    q.front = NULL;
    q.rear = NULL;
    printQueue(q);
    enQueue(&q, 1);
    enQueue(&q, 2);
    enQueue(&q, 3);
    enQueue(&q, 4);
    enQueue(&q, 5);
    enQueue(&q, 6);
    deQueue(&q);
    deQueue(&q);
    cout<<"Front :"<<getFront(q)<<" Rear :"<<getRear(q)<<endl;
    printQueue(q);
    deleteQueue(&q);
    printQueue(q);
    return 0;   
}
