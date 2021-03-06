//Quick Sort
#include<iostream>
#include<cstdlib>
#include<algorithm>
using namespace std;

int partition(int arr[], int l, int r) { //Lomuto partition
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

void quickSort(int arr[], int l, int r) { //Lomuto quick sort
    if (l<r) {
        int p = partition(arr, l, r);
        quickSort(arr, l, p-1);
        quickSort(arr, p+1, r);
    }
}

int partitionHoare(int arr[], int l, int r) { //Hoare partition
    int x = arr[l];
    int i = l;
    int j = r;
    while(1) {
        while(arr[j] > x)
            j--;
        while(arr[i] < x)
            i++;
        if (i<j)
            swap(arr[i], arr[j]);
        else
            return j;
    }
}

void quickSortHoare(int arr[], int l, int r) { //Hoare quick sort
    if (l<r) {
        int p = partitionHoare(arr, l, r);
        quickSortHoare(arr, l, p-1);
        quickSortHoare(arr, p+1, r);
    }
}

int partitionRandomized(int arr[], int l, int r) { //Randomized partition
    int i = l + (rand()%(r-l+1)); //simple way to generate a random no between l and r
    swap(arr[r], arr[i]);
    return partition(arr, l, r);
}

void quickSortRandomized(int arr[], int l, int r) { //Randomized quick sort
    if (l<r) {
        int p = partitionRandomized(arr, l, r);
        quickSortRandomized(arr, l, p-1);
        quickSortRandomized(arr, p+1, r);
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

int partitionNLogN(int arr[], int l, int r, int x) {
    int i;
    for (i=l; i<r; i++)
        if (arr[i]==x)
            break;
    swap(arr[i], arr[r]);
    i = l;
    for (int j=l; j<=r-1; j++) {
        if (arr[j]<=x) {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[r]);
    return i;
}

int median(int arr[], int l, int r) { //O(n)
    int n = r-l+1;
    int medians[(n+4)/5];
    int i;
    for(i=0; i<n/5; i++) {
        sort(arr+l+i*5, arr+l+i*5+5);
        medians[i] = arr[l+i*5+2]; //2 = 5/2
    }
    if (i*5<n) { //special handling for last group as this may have less than 5 elems
        sort(arr+l+i*5, arr+l+i*5+n%5);
        medians[i] = arr[l+i*5+(n%5)/2];
        i++;
    }
    int medianMedian = (i==1)?i:median(medians, 0, i-1);
    int pos = partitionNLogN(arr, l, r, medianMedian);
    if (pos-l == (n/2)-1)
        return arr[pos];
    else if (pos-l > (n/2)-1)
        return median(arr, l, pos-1);
    else
        return median(arr, pos+1, r);
}

void quickSortNLogN(int arr[], int l, int r) {
    if (l<r) {
        int med = median(arr, l, r);
        int p = partitionNLogN(arr, l, r, med);
        quickSortNLogN(arr, l, p-1);
        quickSortNLogN(arr, p+1, r);
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

void partition3way(int a[], int l, int r, int &i, int &j) {
    i = l-1, j = r;
    int p = l-1, q = r;
    int v = a[r];
    while (true) {
        while (a[++i] < v); //find the first element greater than or equal to v from left
        while (v < a[--j]) //find the first element smaller than or equal to v from right
            if (j == l)
                break;
        if (i >= j) //we are done if i and j cross
            break;
        swap(a[i], a[j]); //smaller goes on left greater goes on right
        if (a[i] == v) { //move all same left occurrence of pivot to beginning of array and keep count using p
            p++;
            swap(a[p], a[i]);
        }
        if (a[j] == v) { //move all same right occurrence of pivot to end of array and keep count using q
            q--;
            swap(a[j], a[q]);
        }
    }
    swap(a[i], a[r]); //move pivot element to its correct index
    j = i-1;
    for (int k = l; k < p; k++, j--)
        swap(a[k], a[j]); //move all left same occurrences from beginning to adjacent to arr[i]
    i = i+1;
    for (int k = r-1; k > q; k--, i++)
        swap(a[i], a[k]); //move all right same occurrences from end to adjacent to arr[i]
}

void quickSort3way(int a[], int l, int r) {
    if (r>l) {
        int i, j;
        partition3way(a, l, r, i, j);
        quickSort3way(a, l, j);
        quickSort3way(a, i, r);
    }
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
    int a3[] = {10, 7, 8, 9, 1, 5};
    int n3 = sizeof(a3)/sizeof(a3[0]);
    cout<<"Input Array :";
    printArray(a3, n3);
    quickSortHoare(a3, 0, n3-1);
    cout<<"Sorted Array :";
    printArray(a3, n3);
    int a4[] = {10, 7, 8, 9, 1, 5};
    int n4 = sizeof(a4)/sizeof(a4[0]);
    cout<<"Input Array :";
    printArray(a4, n4);
    quickSortRandomized(a4, 0, n4-1);
    cout<<"Sorted Array :";
    printArray(a4, n4);
    int a5[] = {10, 7, 8, 9, 1, 5};
    int n5 = sizeof(a5)/sizeof(a5[0]);
    cout<<"Input Array :";
    printArray(a5, n5);
    quickSortNLogN(a5, 0, n5-1);
    cout<<"Sorted Array :";
    printArray(a5, n5);
    int a6[] = {10, 7, 8, 9, 1, 5};
    int n6 = sizeof(a6)/sizeof(a6[0]);
    cout<<"Input Array :";
    printArray(a6, n6);
    quickSort3way(a6, 0, n6-1);
    cout<<"Sorted Array :";
    printArray(a6, n6);
    return 0;
}
