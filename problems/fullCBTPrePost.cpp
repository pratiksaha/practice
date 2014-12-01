//from preorder & postorder traversal construct full complete binary tree
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

struct node* buildTreeUtil(int pre[], int post[], int* preIndex, int l, int h, int size) {
    if (*preIndex >= size || l > h)
        return NULL;
    struct node* root = getNode(pre[*preIndex]);
    ++*preIndex;
    if (l == h)
        return root;
    int i;
    for (i = l; i <= h; ++i)
        if (pre[*preIndex] == post[i])
            break;
    if (i <= h) {
        root->left = buildTreeUtil(pre, post, preIndex, l, i, size);
        root->right = buildTreeUtil(pre, post, preIndex, i + 1, h, size);
    }
    return root;
}

struct node *buildTree(int pre[], int post[], int size) {
    int preIndex = 0;
    return buildTreeUtil(pre, post, &preIndex, 0, size-1, size);
}

int main () {
    int pre[] = {1, 2, 4, 8, 9, 5, 3, 6, 7};
    int post[] = {8, 9, 4, 5, 2, 6, 7, 3, 1};
    struct node *root = buildTree(pre, post, sizeof(pre)/sizeof(pre[0]));
    cout<<"Tree :", printTree(root), cout<<endl;
    return 0;
}
