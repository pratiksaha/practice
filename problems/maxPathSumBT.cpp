//to find max path sum in a binary tree
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

int maxPathSum(struct node* root, int *res) {
    if (root) {
        int l = maxPathSum(root->left,res);
        int r = maxPathSum(root->right,res);
        int max_single = max(max(l, r) + root->data, root->data);
        int max_top = max(max_single, l + r + root->data);
        *res = max(*res, max_top);
        return max_single;
    } else {
        return 0;
    }
}

int maxPathSum(struct node *root) {
    int res = INT_MIN;
    maxPathSum(root, &res);
    return res;
}

int main(void) {
    struct node *root = getNode(10);
    root->left = getNode(2);
    root->right = getNode(10);
    root->left->left = getNode(20);
    root->left->right = getNode(1);
    root->right->right = getNode(-25);
    root->right->right->left = getNode(3);
    root->right->right->right = getNode(4);
    cout<<"Tree :";
    printTree(root);
    cout<<endl;
    cout<<"Max path sum is "<<maxPathSum(root)<<endl;
    return 0;
}
