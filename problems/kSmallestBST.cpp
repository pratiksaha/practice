//to find kth smallest element in BST
#include<iostream>
#include<cstdlib>
#include<climits>
using namespace std;

struct node {
    int key;
    struct node *left, *right;
};

struct node *getNode(int data) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->key = data;
    temp->left = temp->right = NULL;
    return temp;
}

struct node* insert(struct node* node, int data) {
    if (node == NULL)
        return getNode(data);
    if (data < node->key)
        node->left  = insert(node->left, data);
    else if (data > node->key)
        node->right = insert(node->right, data);
    return node;
}

int kSmallestBST(struct node *root, int k) {
    int count = 0;
    int ksmall = INT_MIN;
    struct node *curr = root;
    while (curr) {
        if (curr->left == NULL) {
            count++;
            if (count == k)
                ksmall = curr->key;
            curr = curr->right;
        } else {
            struct node *pre = curr->left;
            while (pre->right != NULL && pre->right != curr)
                pre = pre->right;
            if (pre->right == NULL) {
                pre->right = curr;
                curr = curr->left;
            } else {
                pre->right = NULL;
                count++;
                if (count == k)
                    ksmall = curr->key;
                curr = curr->right;
            }
        }
    }
    return ksmall;
}

int main() {
    struct node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    for (int k=1; k<=7; k++)
        cout<<k<<"th smallest node = "<<kSmallestBST(root, k)<<endl;
    return 0;
}
