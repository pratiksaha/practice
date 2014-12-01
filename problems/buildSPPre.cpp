//from preorder traversal construct tree where every node has either 0 or 2 children
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

struct node *buildTreeUtil(int pre[], char preLN[], int *index_ptr, int n) {
    int index = *index_ptr;
    if (index == n)
        return NULL;
    struct node *temp =getNode(pre[index]);
    (*index_ptr)++;
    if (preLN[index] == 'N') {
        temp->left  = buildTreeUtil(pre, preLN, index_ptr, n);
        temp->right = buildTreeUtil(pre, preLN, index_ptr, n);
    }
    return temp;
}

struct node *buildTree(int pre[], char preLN[], int n) {
    int index = 0;
    return buildTreeUtil(pre, preLN, &index, n);
}

int main() {
    int pre[] = {10, 30, 20, 5, 15};
    char preLN[] = {'N', 'N', 'L', 'L', 'L'};
    struct node *root = buildTree(pre, preLN, sizeof(pre)/sizeof(pre[0]));
    cout<<"Tree :", printTree(root), cout<<endl;
    return 0;
}
