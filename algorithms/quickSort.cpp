//Quick Sort
#include<iostream>
#include<cstdlib>
using namespace std;

int partition(int arr[], int l, int r) { //CLRS partition
    int x = arr[r]; //pivot
    int i = l-1;
    for (int j=l; j<=r-1; j++) {
        if (arr[j] < x) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[r]);
    return i+1;
}

void quickSort(int arr[], int l, int r) { //CLRS quick sort
    if (l<r) {
        int p = partition(arr, l, r);
        quickSort(arr, l, p-1);
        quickSort(arr, p+1, r);
    }
}

void quickSortIterative(int arr[], int l, int r) {
    int stack[r-l+1];
    int top = -1;
    stack[++top] = l;
    stack[++top] = r;
    while (top>=0) {
        r = stack[top--];
        l = stack[top--];
        int p = partition(arr, l, r);
        if (p-1>l) { //push left side to stack if there are elems on left side of pivot
            stack[++top] = l;
            stack[++top] = p-1;
        }
        if (p+1<r) { //push right side to stack if there are elems on right side of pivot
            stack[++top] = p+1;
            stack[++top] = r;
        }
    }
}

void printArray(int arr[], int size) {
    for (int i=0; i<size; i++)
        cout<<" "<<arr[i];
    cout<<endl;
}

struct DLL {
    int data;
    struct DLL *prev, *next;
};

struct DLL* getNode(int key) {
    struct DLL* temp = (struct DLL *)malloc(sizeof(struct DLL));
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

void push_front(struct DLL** head, int key) {
    struct DLL *temp = getNode(key);
    if (*head == NULL) {
        *head = temp;
    } else {
        temp->next = *head;
        temp->prev = NULL;
        (*head)->prev = temp;
        *head = temp;
    }
}

struct DLL *getTail(struct DLL *curr) {
    while (curr && curr->next)
        curr = curr->next;
    return curr;
}

struct DLL* partition(struct DLL *l, struct DLL *r) {
    int x  = r->data;
    struct DLL *i = l->prev;
    for (struct DLL* j=l; j!=r; j=j->next) {
        if (j->data <= x) {
            i = (i == NULL)? l : i->next;
            swap(i->data, j->data);
        }
    }
    i = (i == NULL)? l : i->next;
    swap(i->data, r->data);
    return i;
}

void quickSort(struct DLL* l, struct DLL *r) {
    if (r!=NULL && l!=r && l!=r->next) {
        struct DLL *p = partition(l, r);
        quickSort(l, p->prev);
        quickSort(p->next, r);
    }
}

void quickSort(struct DLL *head) {
    quickSort(head, getTail(head));
}

void printList(struct DLL *node) {
    cout<<"Doubly Linked List :";
    while(node != NULL) {
        cout<<" "<<node->data;
        node = node->next;
    }
    cout<<endl;
}

struct SLL {
    int data;
    struct SLL *next;
};

struct SLL* getNode() {
    struct SLL *temp = (struct SLL *)malloc(sizeof(struct SLL));
    if (temp == NULL) {
        cout<<"Memory Full"<<endl;
    }
    return temp;
}

void push_front(struct SLL **head, int key) {
    struct SLL* temp = getNode();
    temp->data = key;
    temp->next = *head;
    *head = temp;
}

struct SLL *getTail(struct SLL *curr) {
    while (curr && curr->next)
        curr = curr->next;
    return curr;
}

struct SLL *partition(struct SLL *head, struct SLL *end, struct SLL **newHead, struct SLL **newEnd) {
    struct SLL *pivot = end;
    struct SLL *prev = NULL, *curr = head, *tail = pivot;
    while (curr != pivot) {
        if (curr->data < pivot->data) {
            if ((*newHead) == NULL) //first node that has a value less than the pivot becomes the new head
                (*newHead) = curr;
            prev = curr;
            curr = curr->next;
        } else {
            if (prev) //move curr node to next of tail and change tail
                prev->next = curr->next;
            struct SLL *temp = curr->next;
            curr->next = NULL;
            tail->next = curr;
            tail = curr;
            curr = temp;
        }
    }
    if ((*newHead) == NULL) //pivot becomes the head if the pivot data is the smallest elem in the curr list
        (*newHead) = pivot;
    (*newEnd) = tail; //update newEnd to the curr last node
    return pivot;
}

struct SLL *quickSort(struct SLL *head, struct SLL *end) {
    if (head == NULL || head == end)
        return head;
    struct SLL *newHead = NULL, *newEnd = NULL;
    struct SLL *pivot = partition(head, end, &newHead, &newEnd); //partition
    if (newHead != pivot) {
        struct SLL *temp = newHead;
        while (temp->next != pivot) //set the node before the pivot node as NULL
            temp = temp->next;
        temp->next = NULL;
        newHead = quickSort(newHead, temp); //recur for the list before pivot
        temp = getTail(newHead); //change next of last node of the left half to pivot
        temp->next = pivot;
    }
    pivot->next = quickSort(pivot->next, newEnd); //recur for the list after the pivot element
    return newHead;
}

void quickSort(struct SLL **head) {
    (*head) = quickSort(*head, getTail(*head));
}

void printList(struct SLL *head) {
    cout<<"Singly Linked List :";
    while(head != NULL) {
        cout<<" "<<head->data;
        head = head->next;
    }
    cout<<endl;
}

int main() {
    int a1[] = {10, 7, 8, 9, 1, 5};
    int n1 = sizeof(a1)/sizeof(a1[0]);
    cout<<"Input Array :";
    printArray(a1, n1);
    quickSort(a1, 0, n1-1);
    cout<<"Sorted Array :";
    printArray(a1, n1);
    int a2[] = {10, 7, 8, 9, 1, 5};
    int n2 = sizeof(a2)/sizeof(a2[0]);
    cout<<"Input Array :";
    printArray(a2, n2);
    quickSortIterative(a2, 0, n2-1);
    cout<<"Sorted Array :";
    printArray(a2, n2);
    struct SLL* sll = NULL;
    push_front(&sll, 5);
    push_front(&sll, 20);
    push_front(&sll, 4);
    push_front(&sll, 3);
    push_front(&sll, 30);
    cout<<"Input ";
    printList(sll);
    quickSort(&sll);
    cout<<"Sorted ";
    printList(sll);
    struct DLL* dll = NULL;
    push_front(&dll, 5);
    push_front(&dll, 20);
    push_front(&dll, 4);
    push_front(&dll, 3);
    push_front(&dll, 30);
    cout<<"Input ";
    printList(dll);
    quickSort(dll);
    cout<<"Sorted ";
    printList(dll);
    return 0;
}
