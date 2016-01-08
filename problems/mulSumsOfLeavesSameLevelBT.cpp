//to find sum of data of all leaves of a binary tree on same level and then multiply sums
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

void printTree(struct node *node) { //print the tree inorder
    if (node) {
        printTree(node->left);
        cout<<" "<<node->data;
        printTree(node->right);
    }
}

bool isLeaf(struct node *root) {
    return (!root->left && !root->right);
}

int mulSumsOfLeavesSameLevel(struct node *root) {
    if (!root)
        return 0;
    int mul = 1;
    queue<struct node *> q;
    q.push(root);
    while (1) {
        int NodeCount = q.size();
        if (NodeCount == 0)
            break;
        int levelSum = 0;
        bool leafFound = false;
        while (NodeCount > 0) {
            struct node *temp = q.front();
            if (isLeaf(temp)) {
                 leafFound = true;
                 levelSum += temp->data;
            }
            q.pop();
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
            NodeCount--;
        }
        if (leafFound)
           mul *= levelSum;
    }
    return mul;
}

int main() {
    struct node *root = getNode(2);
    root->left = getNode(7);
    root->right = getNode(5);
    root->left->right = getNode(6);
    root->left->left = getNode(8);
    root->left->right->left = getNode(1);
    root->left->right->right = getNode(11);
    root->right->right = getNode(9);
    root->right->right->left = getNode(4);
    root->right->right->right = getNode(10);
    cout<<"For Tree :";
    printTree(root);
    cout<<" Product of Sums of Leaves at same level = "<<mulSumsOfLeavesSameLevel(root)<<endl;
    return 0;
}
