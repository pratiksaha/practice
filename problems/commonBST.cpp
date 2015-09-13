//to find common elements in two BSTs
#include<iostream>
#include<stack>
#include<cstdlib>
using namespace std;

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node * getNode(int key) { //allocate memory
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

struct node* insert(struct node* node, int key) {
    if (node == NULL)
        return getNode(key);
    if (key < node->data)
        node->left = insert(node->left, key);
    else if (key > node->data)
        node->right = insert(node->right, key);
    return node;
}

void printTree(struct node *node) { //print the tree inorder
    if(node != NULL) {
        printTree(node->left);
        cout<<" "<<node->data;
        printTree(node->right);
    }
}

void commonBST(struct node *root1, struct node *root2) {
    stack<struct node *> s1, s2;
    while(1) {
        if (root1) {
            s1.push(root1);
            root1 = root1->left;
        } else if (root2) {
            s2.push(root2);
            root2 = root2->left;
        } else if (!s1.empty() && !s2.empty()) { //both root1 and root2 are NULL here
            root1 = s1.top();
            root2 = s2.top();
            if (root1->data == root2->data) {
                cout<<" "<<root1->data;
                s1.pop();
                s2.pop();
                root1 = root1->right; //move to the inorder successor
                root2 = root2->right; //move to the inorder successor
            } else if (root1->data < root2->data) {
                s1.pop();
                root1 = root1->right;
                root2 = NULL;
            } else if (root1->data > root2->data) {
                s2.pop();
                root2 = root2->right;
                root1 = NULL;
            }
        } else { //both roots and hence both stacks are empty
            break;
        }
    }
}

int main() {
    struct node *root1 = NULL;
    root1 = insert(root1, 5);
    root1 = insert(root1, 1);
    root1 = insert(root1, 10);
    root1 = insert(root1, 0);
    root1 = insert(root1, 4);
    root1 = insert(root1, 7);
    root1 = insert(root1, 9);
    struct node *root2 = NULL;
    root2 = insert(root2, 10);
    root2 = insert(root2, 7);
    root2 = insert(root2, 20);
    root2 = insert(root2, 4);
    root2 = insert(root2, 9);
    cout<<"Tree 1 :";
    printTree(root1);
    cout<<endl;
    cout<<"Tree 2 :";
    printTree(root2);
    cout<<endl;
    cout<<"Common Nodes:";
    commonBST(root1, root2);
    cout<<endl;
    return 0;
}
