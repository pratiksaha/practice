//print the elements of 2 BSTs in sorted form
#include<iostream>
#include<cstdlib>
#include<stack>
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

void printMerge(struct node *root1, struct node *root2) {
    stack<struct node *> s1, s2;
    struct node *curr1 = root1;
    struct node *curr2 = root2; 
    if (root1 == NULL) {
        printTree(root2);
    } else if (root2 == NULL) {
        printTree(root1);
    } else {
        while (curr1 || !s1.empty() || curr2 || !s2.empty()) {
            if (curr1 || curr2 ) {
                if (curr1) {
                    s1.push(curr1);
                    curr1 = curr1->left;
                }
                if (curr2) {
                    s2.push(curr2);
                    curr2 = curr2->left;
                }
            } else {
                if (s1.empty()) {
                    while (!s2.empty()) {
                        curr2 = s2.top();
                        s2.pop();
                        curr2->left = NULL;
                        printTree(curr2);
                    }
                    return;
                } 
                if (s2.empty()) {
                    while (!s1.empty()) {
                        curr1 = s1.top();
                        s1.pop();
                        curr1->left = NULL;
                        printTree(curr1);
                    }
                    return ;
                }
                curr1 = s1.top();
                s1.pop();
                curr2 = s2.top();
                s2.pop();
                if (curr1->data < curr2->data) {
                    cout<<" "<<curr1->data;
                    curr1 = curr1->right;
                    s2.push(curr2);
                    curr2 = NULL;
                } else {
                    cout<<" "<<curr2->data;
                    curr2 = curr2->right;
                    s1.push(curr1);
                    curr1 = NULL;
                }
            }
        }
    }
}

int main() {
    struct node *root1 = NULL, *root2 = NULL;
    root1 = getNode(3);
    root1->left = getNode(1);
    root1->right = getNode(5);
    root2 = getNode(4);
    root2->left = getNode(2);
    root2->right = getNode(6);
    printMerge(root1, root2), cout<<endl;
    return 0;
}
