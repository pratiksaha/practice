//level order traversal for perfect binary tree
#include<iostream>
#include<cstdlib>
#include<queue>
#include<cassert>
using namespace std;

struct node {
    int data;
    struct node *left, *right;
};
 
struct node *getNode(int data) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    assert(temp);
    temp->data = data;
    temp->right = temp->left = NULL;
    return temp;
}

void levelOrderPerfect(struct node *node) {
    if (node) {
        cout<<" "<<node->data;
        if (node->left)
            cout<<" "<<node->left->data<<" "<<node->right->data; //perfect tree
        if (node->left->left) {
            queue<struct node *> q;
            q.push(node->left);
            q.push(node->right);
            struct node *first = NULL, *second = NULL;
            while (!q.empty()) {
                struct node *first = q.front();
                q.pop();
                struct node *second = q.front();
                q.pop();
                cout<<" "<<first->left->data<<" "<<second->right->data;
                cout<<" "<<first->right->data<<" "<<second->left->data;
                if (first->left->left) {
                    q.push(first->left);
                    q.push(second->right);
                    q.push(first->right);
                    q.push(second->left);
                }
            }
        }
    }
}

int main() {
    struct node *root = getNode(1);
    root->left = getNode(2);
    root->right = getNode(3);
    root->left->left = getNode(4);
    root->left->right = getNode(5);
    root->right->left = getNode(6);
    root->right->right = getNode(7);
    root->left->left->left = getNode(8);
    root->left->left->right = getNode(9);
    root->left->right->left = getNode(10);
    root->left->right->right = getNode(11);
    root->right->left->left = getNode(12);
    root->right->left->right = getNode(13);
    root->right->right->left = getNode(14);
    root->right->right->right = getNode(15);
    root->left->left->left->left = getNode(16);
    root->left->left->left->right = getNode(17);
    root->left->left->right->left = getNode(18);
    root->left->left->right->right = getNode(19);
    root->left->right->left->left = getNode(20);
    root->left->right->left->right = getNode(21);
    root->left->right->right->left = getNode(22);
    root->left->right->right->right = getNode(23);
    root->right->left->left->left = getNode(24);
    root->right->left->left->right = getNode(25);
    root->right->left->right->left = getNode(26);
    root->right->left->right->right = getNode(27);
    root->right->right->left->left = getNode(28);
    root->right->right->left->right = getNode(29);
    root->right->right->right->left = getNode(30);
    root->right->right->right->right = getNode(31);
    cout<<"Level Order Traversal for Perfect binary tree is :";
    levelOrderPerfect(root);
    cout<<endl;
    return 0;
}
