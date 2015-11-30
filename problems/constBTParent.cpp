//to construct a binary tree from parent array
#include<iostream>
#include<cstdlib>
using namespace std;
 
struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node * getNode(int key) {
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

void printTree(struct node *node) {
    if (node) {
        printTree(node->left);
        cout<<" "<<node->data;
        printTree(node->right);
    }
}

void buildNode(int parent[], int i, struct node *created[], struct node **root) {
    if (created[i] != NULL)
        return;
    created[i] = getNode(i);
    if (parent[i] == -1) {
        *root = created[i];
        return;
    }
    if (created[parent[i]] == NULL)
        buildNode(parent, parent[i], created, root);
    struct node *p = created[parent[i]];
    if (p->left == NULL)
        p->left = created[i];
    else
        p->right = created[i];
}

struct node *buildTree(int parent[], int n) {
    struct node *created[n];
    for (int i=0; i<n; i++)
        created[i] = NULL;
    struct node *root = NULL;
    for (int i=0; i<n; i++)
        buildNode(parent, i, created, &root);
    return root;
}

int main() {
    int parent[] =  {-1, 0, 0, 1, 1, 3, 5};
    int n = sizeof(parent)/sizeof(parent[0]);
    struct node *root = buildTree(parent, n);
    cout<<"Tree :";
    printTree(root);
    cout<<endl;
    return 0;
}
