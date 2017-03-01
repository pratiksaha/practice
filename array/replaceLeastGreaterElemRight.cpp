//to replace every element with the least greater element on its right
#include<bits/stdc++.h>
using namespace std;

void printArray(int arr[], int n) {
    for (int i=0; i<n; i++)
        cout<<" "<<arr[i];
    cout<<endl;
}

struct node {
    int data;
    struct node *left, *right;
};

struct node* getNode(int item) {
    struct node* temp = (struct node *)malloc(sizeof(struct node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}
 
void insert(struct node **node, int data, struct node **succ) {
    if ((*node) == NULL)
        (*node) = getNode(data);
    if (data < (*node)->data) {
        *succ = *node;
        insert(&((*node)->left), data, succ);
    } else if (data > (*node)->data) {
        insert(&((*node)->right), data, succ);
    }
}

void replaceLeastGreaterElemRight(int arr[], int n) {
    struct node* root = NULL;
    for (int i = n - 1; i >= 0; i--) {
        struct node* succ = NULL;
        insert(&root, arr[i], &succ);
        if (succ)
            arr[i] = succ->data;
        else
            arr[i] = -1;
    }
}

int main() {
    int arr[] = { 8, 58, 71, 18, 31, 32, 63, 92, 43, 3, 91, 93, 25, 80, 28 };
    int n = sizeof(arr)/ sizeof(arr[0]);
    cout<<"Before Replacement :";
    printArray(arr, n);
    replaceLeastGreaterElemRight(arr, n);
    cout<<"After Replacement :";
    printArray(arr, n);
    return 0;
}
