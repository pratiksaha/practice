//construct BT from inorder and levelorder traversal
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

int search(int arr[], int start, int end, char value) {
    for(int i=start; i<=end; i++)
        if(arr[i] == value)
            return i;
    return -1;
}

int *extractKeys(int in[], int level[], int m, int n) {
    int *newlevel = new int[m];
    int j = 0;
    for (int i = 0; i < n; i++)
        if (search(in, 0, m-1, level[i]) != -1)
            newlevel[j] = level[i], j++;
    return newlevel;
}

struct node* buildTree(int in[], int level[], int start, int end, int n) {
    if (start > end)
        return NULL;
    struct node *temp = getNode(level[0]);
    if (start == end)
        return temp;
    int inIndex = search(in, start, end, temp->data);
    int *llevel  = extractKeys(in, level, inIndex, n);
    int *rlevel  = extractKeys(in+inIndex+1, level, n-inIndex-1, n);
    temp->left = buildTree(in, llevel, start, inIndex-1, n);
    temp->right = buildTree(in, rlevel, inIndex+1, end, n);
    delete[] llevel;
    delete[] rlevel;
    return temp;
}


int main() {
    int in[] = {4, 8, 10, 12, 14, 20, 22};
    int level[] = {20, 8, 22, 4, 12, 10, 14};
    int n = sizeof(in)/sizeof(in[0]);
    struct node *root = buildTree(in, level, 0, n-1, n);
    cout<<"Tree :", printTree(root), cout<<endl;
    return 0;
}
