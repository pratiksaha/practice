//remove all nodes which don’t lie in any path with sum>=k. 
#include<iostream>
#include<cstdlib>
#include<algorithm>
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

struct node *pruneSumPathK(struct node *node, int k, int *sum) {
    if (node) {
        int lsum = *sum + (node->data);
        int rsum = lsum;
        node->left = pruneSumPathK(node->left, k, &lsum);
        node->right = pruneSumPathK(node->right, k, &rsum);
        *sum = max(lsum, rsum);
        if (*sum < k) {
            free(node);
            node = NULL;
        }
        return node;
    } else {
        return NULL;
    }
}

struct node *prune(struct node *node, int k) {
    int sum = 0;
    return pruneSumPathK(node, k, &sum);
}

int main() {
    struct node *root = getNode(1);
    root->left = getNode(2);
    root->right = getNode(3);
    root->left->left = getNode(4);
    root->left->right = getNode(5);
    root->right->left = getNode(6);
    root->right->right = getNode(7);
    root->left->left->left = getNode(8);
    root->left->left->right = getNode(9);
    root->left->right->left = getNode(12);
    root->right->right->left = getNode(10);
    root->right->right->left->right = getNode(11);
    root->left->left->right->left = getNode(13);
    root->left->left->right->right = getNode(14);
    root->left->left->right->right->left = getNode(15);
    cout<<"Tree before pruning ", printTree(root), cout<<endl;
    root = prune(root, 45);
    cout<<"Tree after pruning ", printTree(root), cout<<endl;
    return 0;
}

