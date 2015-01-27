//construct balanced bst from sorted array
#include<iostream>
#include<cstdlib>
using namespace std;

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node * getNode(int key) { //allocate memory and initialize
    struct node * temp = (struct node *)malloc(sizeof(struct node));
    if(temp == NULL) {
        cout<<"Memory full\n";
        exit(1);
    }
    temp->data = key;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void printTree(struct node *node) { //print the tree inorder
    if (node) {
        printTree(node->left);
        cout<<" "<<node->data;
        printTree(node->right);
    }
}

struct node * getBalBSTSortArr(int arr[], int start, int end) {
    if (start <= end) {
        int mid = (start + end)/2;
        struct node *root = getNode(arr[mid]);
        root->left = getBalBSTSortArr(arr, start, mid-1);
        root->right = getBalBSTSortArr(arr, mid+1, end);
        return root;
    } else {
        return NULL;
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    struct node *root = getBalBSTSortArr(arr, 0, sizeof(arr)/sizeof(arr[0])-1);
    cout<<"Tree :", printTree(root), cout<<endl;
    return 0;
}
