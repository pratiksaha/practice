//clone a binary tree with arbit pointers
//Using features of C++ Standard (2011) Compile using g++ -std=c++11
#include<iostream>
#include<unordered_map>
using namespace std;
 
struct node {
    int data;
    struct node* left;
    struct node* right;
    struct node* arbit;
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
    temp->arbit = NULL;
    return temp;
}

void printTree(struct node *node) { //print the tree inorder
    if (node) {
        printTree(node->left);
        cout<<" ["<<node->data<<" ";
        if (node->arbit == NULL)
            cout<<"NULL] ";
        else
            cout<<node->arbit->data << "] ";
        printTree(node->right);
    }
}

struct node* copyLeftRightNode(struct node* treeNode, unordered_map<struct node*, struct node*> *mymap) {
    if (treeNode == NULL)
        return NULL;
    struct node* cloneNode =getNode(treeNode->data);
    (*mymap)[treeNode] = cloneNode;
    cloneNode->left  = copyLeftRightNode(treeNode->left, mymap);
    cloneNode->right = copyLeftRightNode(treeNode->right, mymap);
    return cloneNode;
}

void copyRandom(struct node* treeNode, struct node* cloneNode, unordered_map<struct node*, struct node*> *mymap) {
    if (cloneNode == NULL)
        return;
    cloneNode->arbit = (*mymap)[treeNode->arbit];
    copyRandom(treeNode->left, cloneNode->left, mymap);
    copyRandom(treeNode->right, cloneNode->right, mymap);
}

struct node* clone(struct node* tree) {
    if (tree == NULL)
        return NULL;
    unordered_map<struct node*, struct node*> *mymap = new unordered_map<struct node*, struct node*>;
    struct node* newTree = copyLeftRightNode(tree, mymap);
    copyRandom(tree, newTree, mymap);
    delete mymap;
    return newTree;
}

int main() {
    struct node *tree = getNode(1);
    tree->left = getNode(2);
    tree->right = getNode(3);
    tree->left->left = getNode(4);
    tree->left->right = getNode(5);
    tree->arbit = tree->left->right;
    tree->left->left->arbit = tree;
    tree->left->right->arbit = tree->right;
    cout<<"Input Tree :";
    printTree(tree);
    cout<<endl;
    struct node *dup = clone(tree);
    cout<<"Output Tree :";
    printTree(dup);
    cout<<endl;
    return 0;
}
