//flatten a multi level list
#include<iostream>
#include<cstdlib>
using namespace std;

struct node {
    int data;
    struct node *next;
    struct node *child;
};
 
struct node* newNode(int key) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = key;
    node->next = NULL;
    node->child = NULL;
    return node;
}
 
void deleteList(struct node **head) {
    struct node* curr = *head;
    struct node* next;
    while (curr != NULL) {
        next = curr->next;
        free(curr);
        curr = next;
    }
    *head = NULL;
}

void printList(struct node *head) {
    cout<<"List :";
    while(head != NULL) {
        cout<<" "<<head->data;
        head = head->next;
    }
    cout<<endl;
}

struct node *createList(int *arr, int n) {
    struct node *head = NULL;
    struct node *temp;
    for (int i = 0; i < n; ++i) {
        if (head == NULL)
            head = temp = (struct node *)malloc(sizeof(struct node));
        else {
            temp->next = (struct node *)malloc(sizeof(struct node));
            temp = temp->next;
        }
        temp->data = arr[i];
        temp->next = temp->child = NULL;
    }
    return head;
}

struct node *createList(void) {
    int arr1[] = {10, 5, 12, 7, 11};
    int arr2[] = {4, 20, 13};
    int arr3[] = {17, 6};
    int arr4[] = {9, 8};
    int arr5[] = {19, 15};
    int arr6[] = {2};
    int arr7[] = {16};
    int arr8[] = {3};
    struct node *head1 = createList(arr1, sizeof(arr1)/sizeof(arr1[0]));
    struct node *head2 = createList(arr2, sizeof(arr2)/sizeof(arr2[0]));
    struct node *head3 = createList(arr3, sizeof(arr3)/sizeof(arr3[0]));
    struct node *head4 = createList(arr4, sizeof(arr4)/sizeof(arr4[0]));
    struct node *head5 = createList(arr5, sizeof(arr5)/sizeof(arr5[0]));
    struct node *head6 = createList(arr6, sizeof(arr6)/sizeof(arr6[0]));
    struct node *head7 = createList(arr7, sizeof(arr7)/sizeof(arr7[0]));
    struct node *head8 = createList(arr8, sizeof(arr8)/sizeof(arr8[0]));
    head1->child = head2;
    head1->next->next->next->child = head3;
    head3->child = head4;
    head4->child = head5;
    head2->next->child = head6;
    head2->next->next->child = head7;
    head7->child = head8;
    return head1;
}

void flattenList(struct node *head) {
    if (head) {
        struct node *tail = head;
        while (tail->next != NULL)
            tail = tail->next;
        struct node *curr = head;
        while (curr != tail) {
            if (curr->child) {
                tail->next = curr->child;
                struct node *temp = curr->child;
                while (temp->next)
                    temp = temp->next;
                tail = temp;
            }
            curr = curr->next;
        }
    }
}

int main() {
    struct node *head = NULL;
    head = createList();
    flattenList(head);
    printList(head);
    deleteList(&head);
    return 0;
}
