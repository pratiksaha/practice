//largest independent set TODO:print the set
#include<iostream>
#include<cstdlib>
#include<cassert>
using namespace std;

struct node {
    int data, liss;
    struct node *left, *right;
};

struct node* getNode(int data) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    assert(temp);
    temp->data = data;
    temp->left = temp->right = NULL;
    temp->liss = 0;
    return temp;
}

int largestIndependentSet(struct node *node) {
    if (node) {
        if (node->liss)
            return node->liss;
        if (node->left == NULL && node->right == NULL)
            return (node->liss = 1);
        int liss_excl = largestIndependentSet(node->left) + largestIndependentSet(node->right);
        int liss_incl = 1;
        if (node->left)
            liss_incl += largestIndependentSet(node->left->left) + largestIndependentSet(node->left->right);
        if (node->right)
            liss_incl += largestIndependentSet(node->right->left) + largestIndependentSet(node->right->right);
        node->liss = max(liss_incl, liss_excl);
        return node->liss;
    } else {
        return 0;
    }
}

int main() {
    struct node *root = getNode(10);
    root->left = getNode(20);
    root->left->left = getNode(40);
    root->left->right = getNode(50);
    root->left->right->left = getNode(70);
    root->left->right->right  = getNode(80);
    root->right = getNode(30);
    root->right->right = getNode(60);
    cout<<largestIndependentSet(root)<<endl;
    return 0;
}
