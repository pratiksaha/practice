//from inorder traversal construct tree in which key of every node is greater than keys in left and right children
#include<iostream>
#include<cstdlib>
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

int max(int arr[], int start, int end) {
    int max = arr[start];
    int maxind = start;
    for(int i = start+1; i <= end; i++) {
        if(arr[i] > max) {
            max = arr[i];
            maxind = i;
        }
    }
    return maxind;
}

struct node* buildTree(int inorder[], int start, int end) {
    if (start > end)
        return NULL;
    int i = max(inorder, start, end);
    struct node *root = getNode(inorder[i]);
    if (start == end)
        return root;
    root->left = buildTree(inorder, start, i-1);
    root->right = buildTree(inorder, i+1, end);
    return root;
}

int main() {
    int inorder[] = {5, 10, 40, 30, 28};
    struct node *root = buildTree(inorder, 0, sizeof(inorder)/sizeof(inorder[0]) - 1);
    cout<<"Tree :", printTree(root), cout<<endl;
    return 0;
}
