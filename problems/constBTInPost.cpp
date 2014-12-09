//construct BT from inorder and postorder traversal
#include<iostream>
#include<cstdlib>
using namespace std;

struct node {
    char data;
    struct node* left;
    struct node* right;
};
 
struct node * getNode(char key) { //allocate memory and initialize
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

struct node* buildTreeUtil(char in[], char post[], int start, int end, int *ind) {
    if(start > end)
        return NULL;
    struct node *temp = getNode(post[(*ind)--]);
    if(start == end)
        return temp;
    int inIndex = search(in, start, end, temp->data);
    temp->right = buildTreeUtil(in, post, inIndex+1, end, ind);
    temp->left = buildTreeUtil(in, post, start, inIndex-1, ind);
    return temp;
}

struct node *buildTree(char in[], char post[], int size) {
    int postIndex = size-1;
    return buildTreeUtil(in, post, 0, size-1, &postIndex);
}

int main() {
    char in[] = {'D', 'B', 'E', 'A', 'F', 'C'};
    char post[] = {'B', 'E', 'D', 'F', 'C', 'A'};
    struct node *root = buildTree(in, post, sizeof(in)/sizeof(in[0]));
    cout<<"Tree :", printTree(root), cout<<endl;
    return 0;
}
