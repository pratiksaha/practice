//construct BT from inorder and preorder traversal
#include<iostream>
#include<cstdlib>
using namespace std;

struct node {
    char data;
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

int search(char arr[], int start, int end, char value) {
    for(int i=start; i<=end; i++)
        if(arr[i] == value)
            return i;
    return -1;
}

struct node* buildTreeUtil(char in[], char pre[], int start, int end, int *ind) {
    if(start > end)
        return NULL;
    struct node *temp = getNode(pre[(*ind)++]);
    if(start == end)
        return temp;
    int inIndex = search(in, start, end, temp->data);
    temp->left = buildTreeUtil(in, pre, start, inIndex-1, ind);
    temp->right = buildTreeUtil(in, pre, inIndex+1, end, ind);
    return temp;
}

struct node *buildTree(char in[], char pre[], int size) {
    int preIndex = 0;
    return buildTreeUtil(in, pre, 0, size-1, &preIndex);
}


int main() {
    char in[] = {'D', 'B', 'E', 'A', 'F', 'C'};
    char pre[] = {'A', 'B', 'D', 'E', 'C', 'F'};
    struct node *root = buildTree(in, pre,sizeof(in)/sizeof(in[0]));
    cout<<"Tree :", printTree(root), cout<<endl;
    return 0;
}
