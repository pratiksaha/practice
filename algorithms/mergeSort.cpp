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

void mergeSort(int arr[], int n) { //iteartive morge sort
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

struct node {
    int data;
    struct node *next;
};

void listSplit(struct node* head, struct node** left, struct node** right) { //split head list into left and right
    if (head==NULL || head->next==NULL) { //length < 2 cases
        *left = head;
        *right = NULL;
    } else { //tortoise and hare
        struct node* slow = head;
        struct node* fast = head->next;
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

struct node* merge(struct node* a, struct node* b) {
    if (a==NULL) {
        return b;
    } else if (b==NULL) {
        return a;
    } else {
        struct node* result = NULL;
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

void mergeSort(struct node** headRef) {
    struct node* head = *headRef;
    if (head && head->next) { //proceed only if head contains more than 1 element
        struct node* a;
        struct node* b;
        listSplit(head, &a, &b);
        mergeSort(&a);
        mergeSort(&b);
        *headRef = merge(a, b);
    }
}

struct node* getNode() {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL) {
        cout<<"Memory Full"<<endl;
    }
    return temp;
}

void push_front(struct node **head, int key) {
    struct node* temp = getNode();
    temp->data = key;
    temp->next = *head;
    *head = temp;
}

void printList(struct node *head) {
    cout<<"Linked List :";
    while(head != NULL) {
        cout<<" "<<head->data;
        head = head->next;
    }
    cout<<endl;
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
    struct node* a = NULL;
    push_front(&a, 15);
    push_front(&a, 10);
    push_front(&a, 5);
    push_front(&a, 20);
    push_front(&a, 3);
    push_front(&a, 2);
    cout<<"Input ";
    printList(a);
    mergeSort(&a);
    cout<<"Sorted ";
    printList(a);
    return 0;
}
