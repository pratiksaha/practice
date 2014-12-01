//construct BST from preorder traversal
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

struct node* buildTreeUtil( int pre[], int* preIndex, int key, int min, int max, int size ) {
    if(*preIndex>=size)
        return NULL;
    struct node* root = NULL;
    if (key>min && key<max) {
        root = getNode(key);
        *preIndex = *preIndex + 1;
        if (*preIndex<size) {
            root->left = buildTreeUtil(pre, preIndex, pre[*preIndex], min, key, size);
            root->right = buildTreeUtil(pre, preIndex, pre[*preIndex], key, max, size);
        }
    }
    return root;
}

struct node *buildTree(int pre[], int size) {
    int preIndex = 0;
    return buildTreeUtil(pre, &preIndex, pre[0], INT_MIN, INT_MAX, size );
}

int main () {
    int pre[] = {10, 5, 1, 7, 40, 50};
    struct node *root = buildTree(pre, sizeof(pre)/sizeof(pre[0]));
    cout<<"Tree :", printTree(root), cout<<endl;
    return 0;
}
