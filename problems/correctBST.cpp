//fix two swapped nodes in a bst
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

void correctBSTUtil(struct node *root, struct node **first, struct node **second, struct node **ancestor, struct node **prev) {
    if (root) {
        correctBSTUtil(root->left, first, second, ancestor, prev); //recur left subtree
        if(*prev && root->data < (*prev)->data) {//if data is not in ascending oredr in inorder traversal
            if (*first) {
                *second = root;
            } else {
                *first = *prev;
                *ancestor = root; 
            }
        }
        *prev = root;
        correctBSTUtil(root->right, first, second, ancestor, prev); //recur right subtree
    }
}

void correctBST(struct node *root) { //fix swapped nodes
    struct node *first, *second, *ancestor, *prev;
    first = second = ancestor = prev = NULL;
    correctBSTUtil(root, &first, &second, &ancestor, &prev);
    if (first) { //at least one violation
        if (second) { //if there is a second violation
            swap(first->data, second->data);
        } else {
            swap(first->data, ancestor->data);
        }
     } else {
        cout<<"Input BST is proper\n";
     }
}

int main () {
    struct node *root = getNode(6);
    root->left = getNode(2);
    root->right = getNode(10);
    root->left->left = getNode(1);
    root->left->right = getNode(3);
    root->right->right = getNode(12);
    root->right->left = getNode(7);
    cout<<"Original Tree "; printTree(root); cout<<endl;
    correctBST(root);
    cout<<"Modified Tree "; printTree(root); cout<<endl;
    root->left->data = 10;
    root->right->data = 2;
    cout<<"Original Tree "; printTree(root); cout<<endl;
    correctBST(root);
    cout<<"Modified Tree "; printTree(root); cout<<endl;
    root->right->left->data = 11;
    cout<<"Original Tree "; printTree(root); cout<<endl;
    correctBST(root);
    cout<<"Modified Tree "; printTree(root); cout<<endl;
    root->right->left->left = getNode(4);
    cout<<"Original Tree "; printTree(root); cout<<endl;
    correctBST(root);
    cout<<"Modified Tree "; printTree(root); cout<<endl;
    return 0;
}
