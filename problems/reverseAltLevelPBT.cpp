//reverse alternate levels of a perfect binary tree
#include<iostream>
#include<cstdlib>
using namespace std;

struct node {
    char data;
    struct node *left;
    struct node *right;
};

struct node *newNode(char item) {
    struct node *temp =  new node;
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}

void printTree(struct node *root) {
    if (root) {
        printTree(root->left);
        cout<<" "<<root->data;
        printTree(root->right);
    }
}

void deleteTree(struct node **node) {
    if((*node) != NULL) {
        deleteTree(&((*node)->right));
        deleteTree(&((*node)->left));
        struct node *temp = *node;
        *node = NULL;
        delete temp;
    }
}

void storeAlternate(struct node *root, char arr[], int *index, int l) {
    if (root) {
        storeAlternate(root->left, arr, index, l+1);
        if (l%2 != 0) {
            arr[*index] = root->data;
            (*index)++;
        }
        storeAlternate(root->right, arr, index, l+1);
    }
}

void modifyTree(struct node *root, char arr[], int *index, int l) {
    if (root) {
        modifyTree(root->left, arr, index, l+1);
        if (l%2 != 0) {
            root->data = arr[*index];
            (*index)++;
        }
        modifyTree(root->right, arr, index, l+1);
    }
}

void reverse(char arr[], int n) {
    int l = 0, r = n-1;
    while (l < r) {
        swap(arr[l], arr[r]);
        l++; r--;
    }
}

void reverseAltLevel(struct node *root) {
    char *arr = new char[100];
    int index = 0;
    storeAlternate(root, arr, &index, 0);
    reverse(arr, index);
    index = 0;
    modifyTree(root, arr, &index, 0);
    delete[] arr;
}

int main() {
    struct node *root = newNode('a');
    root->left = newNode('b');
    root->right = newNode('c');
    root->left->left = newNode('d');
    root->left->right = newNode('e');
    root->right->left = newNode('f');
    root->right->right = newNode('g');
    root->left->left->left = newNode('h');
    root->left->left->right = newNode('i');
    root->left->right->left = newNode('j');
    root->left->right->right = newNode('k');
    root->right->left->left = newNode('l');
    root->right->left->right = newNode('m');
    root->right->right->left = newNode('n');
    root->right->right->right = newNode('o');
    cout<<"Tree :", printTree(root), cout<<endl;
    reverseAltLevel(root);
    cout<<"Tree :", printTree(root), cout<<endl;
    deleteTree(&root);
    return 0;
}
