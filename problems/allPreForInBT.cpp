//to find preorder traversals of all BTs with given inorder traversal
#include<bits/stdc++.h>
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

void inOrder(struct node *node) { //print the tree inorder
    if (node) {
        inOrder(node->left);
        cout<<" "<<node->data;
        inOrder(node->right);
    }
}

void preOrder(struct node *node) { //print the tree preorder
    if (node) {
        cout<<" "<<node->data;
        preOrder(node->left);
        preOrder(node->right);
    }
}

vector<struct node *> getTrees(int arr[], int start, int end) {
    vector<struct node *> trees;
    if (start > end) {
        trees.push_back(NULL);
        return trees;
    }
    for (int i=start; i<=end; i++) {
        vector<struct node *> ltrees = getTrees(arr, start, i-1);
        vector<struct node *> rtrees = getTrees(arr, i+1, end);
        for (int j=0; j<ltrees.size(); j++) {
            for (int k=0; k<rtrees.size(); k++) {
                struct node * node = getNode(arr[i]);
                node->left = ltrees[j];
                node->right = rtrees[k];
                trees.push_back(node);
            }
        }
    }
    return trees;
}

int main() {
    int in[] = {4, 5, 7};
    int n = sizeof(in) / sizeof(in[0]);
    vector<struct node *> trees = getTrees(in, 0, n-1);
    cout<<"Preorder traversals of different possible Binary Trees are :\n";
    for (int i=0; i<trees.size(); i++) {
        cout<<"Inorder :";
        inOrder(trees[i]);
        cout<<" Preorder :";
        preOrder(trees[i]);
        cout<<endl;
    }
    return 0;
}
