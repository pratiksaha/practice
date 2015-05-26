//DP based solution for vertex cover problem for a binary tree TODO: update to print vertex cover
#include<iostream>
#include<cstdlib>
#include<cassert>
using namespace std;

struct node {
    int data, vc;
    struct node *left, *right;
};

struct node* getNode(int key) {
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    assert(temp);
    temp->data = key;
    temp->left = NULL;
    temp->right = NULL;
    temp->vc = 0; //set vertex cover as 0
    return temp;
}

int vertexCover(struct node *node) {
    if (node) {
        if (node->left || node->right) {
            if (node->vc != 0) {//save recomputation
                return node->vc;
            } else {
                int size_incl = 1 + vertexCover(node->left) + vertexCover(node->right);
                int size_excl = 0;
                if (node->left)
                    size_excl += 1 + vertexCover(node->left->left) + vertexCover(node->left->right);
                if (node->right)
                    size_excl += 1 + vertexCover(node->right->left) + vertexCover(node->right->right);
                node->vc =  min(size_incl, size_excl);
                return node->vc;
            }
        } else { //size of minimum vertex cover is zero if tree has only one node
            return 0;
        }
    } else { //size of minimum vertex cover is zero if tree is empty
        return 0;
    }
}

int main() {
    struct node *root = getNode(20);
    root->left = getNode(8);
    root->left->left = getNode(4);
    root->left->right = getNode(12);
    root->left->right->left = getNode(10);
    root->left->right->right = getNode(14);
    root->right = getNode(22);
    root->right->right = getNode(25);
    cout<<"Size of the smallest vertex cover is "<<vertexCover(root)<<endl;
    return 0;
}
