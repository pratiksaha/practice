//given a node, find the closest leaf to the node
#include<iostream>
#include<cstdlib>
#include<climits>
using namespace std;

struct node {
    int data;
    struct node* left;
    struct node* right;
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

int closestDown(struct node *node) {
    if (node == NULL)
        return INT_MAX;
    if (node->left == NULL && node->right == NULL)
        return 0;
    return 1 + min(closestDown(node->left), closestDown(node->right));
}

int closestLeafUtil(struct node *node, int k, struct node *ancestors[], int index) {
    if (node) {
        if (node->data == k) {
            int res = closestDown(node);
            for (int i = index-1; i>=0; i--)
                res = min(res, index-i+closestDown(ancestors[i]));
            return res;
        } else {
            ancestors[index] = node;
            return min(closestLeafUtil(node->left, k, ancestors, index+1), closestLeafUtil(node->right, k, ancestors, index+1));
        }
    } else {
        return INT_MAX;
    } 
}

int closestLeaf(struct node *root, int k) {
    struct node *ancestors[100];
    return closestLeafUtil(root, k, ancestors, 0);
}

int main() {
    struct node *root = getNode(1);
    root->left = getNode(2);
    root->right = getNode(3);
    root->right->left = getNode(5);
    root->right->right = getNode(6);
    root->right->left->left = getNode(7);
    root->right->left->left->left = getNode(9);
    root->right->left->left->right = getNode(10);
    root->right->right->right = getNode(8);
    root->right->right->right->left = getNode(11);
    cout<<"Distace of the closest key from 8 is "<<closestLeaf(root, 8)<<endl;
    cout<<"Distace of the closest key from 3 is "<<closestLeaf(root, 3)<<endl;
    cout<<"Distace of the closest key from 5 is "<<closestLeaf(root, 5)<<endl;
    cout<<"Distace of the closest key from 2 is "<<closestLeaf(root, 2)<<endl;
    return 0;
}
