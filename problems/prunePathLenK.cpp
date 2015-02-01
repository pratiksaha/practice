//remove all nodes which lie on root to leaf path of length<k
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

struct node *prunePathLenK(struct node *node, int level, int k) {
    if (node) {
        node->left = prunePathLenK(node->left, level + 1, k);
        node->right = prunePathLenK(node->right, level + 1, k);
        if (node->left == NULL && node->right == NULL && level < k) {
            delete node;
            return NULL;
        }
        return node;
    } else {
        return NULL;
    }
}

struct node *prune(struct node *node, int k) {
    return prunePathLenK(node, 1, k);
}

int main() {
    int k = 4;
    struct node *root = getNode(1);
    root->left = getNode(2);
    root->right = getNode(3);
    root->left->left = getNode(4);
    root->left->right = getNode(5);
    root->left->left->left = getNode(7);
    root->right->right = getNode(6);
    root->right->right->left = getNode(8);
    cout<<"Tree before pruning ", printTree(root), cout<<endl;
    root = prune(root, 4);
    cout<<"Tree after pruning ", printTree(root), cout<<endl;
    return 0;
    return 0;
}

