//Merge Sort
#include<iostream>
#include<cstdlib>
using namespace std;

void merge(int arr[], int l, int m, int r) {
    int n1 = m-l+1;
    int n2 = r-m;
    int L[n1], R[n2];
    int i, j, k;
    for (i=0; i<n1; i++)
        L[i] = arr[l+i];
    for (j=0; j<n2; j++)
        R[j] = arr[m+j+1];
    i=0;
    j=0;
    k=l;
    while(i<n1 && j<n2) { //merge from both arrays
        if (L[i] <= R[j] ) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i<n1) { //leftover from left array (if any)
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j<n2) { //leftover from right array (if any)
        arr[k] = R[j];
        j++;
        k++;
    }
}


void mergeSort(int arr[], int l, int r) { //recursive merge sort
    if (l<r) {
        int m = (l+r)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

void mergeSort(int arr[], int n) { //iterative merge sort
    for (int size=1; size<=n-1; size=2*size) { //merge subarrays of sixe 1, 2, 4 and so on
        for (int l=0; l<n-1; l += 2*size) {
            int m = l+size-1;
            int r = min(l+2*size-1, n-1);
            merge(arr, l, m, r);
        }
    }
}

void printArray(int arr[], int size) {
    for (int i=0; i<size; i++)
        cout<<" "<<arr[i];
    cout<<endl;
}

struct SLL {
    int data;
    struct SLL *next;
};

void listSplit(struct SLL* head, struct SLL** left, struct SLL** right) { //split head list into left and right
    if (head==NULL || head->next==NULL) { //length < 2 cases
        *left = head;
        *right = NULL;
    } else { //tortoise and hare
        struct SLL* slow = head;
        struct SLL* fast = head->next;
        while (fast) {
            fast = fast->next;
            if (fast) {
                slow = slow->next;
                fast = fast->next;
            }
        }
        *left = head;
        *right = slow->next;
        slow->next = NULL;
    }
}

struct SLL* merge(struct SLL* a, struct SLL* b) {
    if (a==NULL) {
        return b;
    } else if (b==NULL) {
        return a;
    } else {
        struct SLL* result = NULL;
        if (a->data <= b->data) {
            result = a;
            result->next = merge(a->next, b);
        } else {
            result = b;
            result->next = merge(a, b->next);
        }
        return result;
    }
}

void mergeSort(struct SLL** headRef) {
    struct SLL* head = *headRef;
    if (head && head->next) { //proceed only if head contains more than 1 element
        struct SLL* a;
        struct SLL* b;
        listSplit(head, &a, &b);
        mergeSort(&a);
        mergeSort(&b);
        *headRef = merge(a, b);
    }
}

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

void printList(struct SLL *head) {
    cout<<"Linked List :";
    while(head != NULL) {
        cout<<" "<<head->data;
        head = head->next;
    }
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

void printList(struct DLL *node) {
    cout<<"Doubly Linked List :";
    while(node != NULL) {
        cout<<" "<<node->data;
        node = node->next;
    }
    cout<<endl;
}

struct DLL *split(struct DLL *head) {
    struct DLL *fast = head,*slow = head;
    while (fast->next && fast->next->next) {
        fast = fast->next->next;
        slow = slow->next;
    }
    struct DLL *temp = slow->next;
    slow->next = NULL;
    return temp;
}

struct DLL *merge(struct DLL *first, struct DLL *second) {
    if (!first)
        return second;
    if (!second)
        return first;
    if (first->data < second->data) {
        first->next = merge(first->next,second);
        first->next->prev = first;
        first->prev = NULL;
        return first;
    } else {
        second->next = merge(first,second->next);
        second->next->prev = second;
        second->prev = NULL;
        return second;
    }
}

struct DLL *mergeSort(struct DLL *head) {
    if (!head || !head->next)
        return head;
    struct DLL *second = split(head);
    head = mergeSort(head);
    second = mergeSort(second);
    return merge(head,second);
}

int main() {
    int a1[] = {12, 11, 13, 5, 6, 7};
    int n1 = sizeof(a1)/sizeof(a1[0]);
    cout<<"Input Array :";
    printArray(a1, n1);
    mergeSort(a1, 0, n1-1);
    cout<<"Sorted Array :";
    printArray(a1, n1);
    int a2[] = {12, 11, 13, 5, 6, 7};
    int n2 = sizeof(a2)/sizeof(a2[0]);
    cout<<"Input Array :";
    printArray(a2, n2);
    mergeSort(a2, n2);
    cout<<"Sorted Array :";
    printArray(a1, n2);
    struct SLL* sll = NULL;
    push_front(&sll, 15);
    push_front(&sll, 10);
    push_front(&sll, 5);
    push_front(&sll, 20);
    push_front(&sll, 3);
    push_front(&sll, 2);
    cout<<"Input ";
    printList(sll);
    mergeSort(&sll);
    cout<<"Sorted ";
    printList(sll);
    struct DLL* dll = NULL;
    push_front(&dll, 15);
    push_front(&dll, 10);
    push_front(&dll, 5);
    push_front(&dll, 20);
    push_front(&dll, 3);
    push_front(&dll, 2);
    cout<<"Input ";
    printList(dll);
    mergeSort(dll);
    cout<<"Sorted ";
    printList(dll);
    return 0;
}
