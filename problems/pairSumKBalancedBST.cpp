//Find a pair with given sum in a Balanced BST
#include<iostream>
#include<cstdlib>
#include<climits>
#include<stack>
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

void deleteTree(struct node **node) { //free all space used by the tree
    if((*node) != NULL) {
        deleteTree(&((*node)->right));
        deleteTree(&((*node)->left));
        struct node *temp = *node;
        *node = NULL;
        free(temp);
    }
}

bool pairSumK(struct node *node, int target) {
    stack<struct node *> s1;
    stack<struct node *> s2;
    bool done1 = false, done2 = false;
    int val1 = 0, val2 = 0;
    struct node *curr1 = node, *curr2 = node;
    while (1) { //loop will break when we either find a pair or one of the two traversals is complete
        while (done1 == false) { //inorder traversal
            if (curr1) {
                s1.push(curr1);
                curr1 = curr1->left;
            } else {
                if (s1.empty()) {
                    done1 = true;
                } else {
                    curr1 = s1.top();
                    s1.pop();
                    val1 = curr1->data;
                    curr1 = curr1->right;
                    done1 = true;
                }
            }
        }
        while (done2 == false) { //reverse inorder traversal
            if (curr2) {
                s2.push(curr2);
                curr2 = curr2->right;
            } else {
                if (s2.empty()) {
                    done2 = true;
                } else {
                    curr2 = s2.top();
                    s2.pop();
                    val2 = curr2->data;
                    curr2 = curr2->left;
                    done2 = true;
                }
            }
        }
        if ((val1 != val2) && (val1 + val2) == target) {
            cout<<"Pair Found: "<<val1<<" + "<<val2<<" = "<<target<<endl;
            return true;
        } else if ((val1 + val2) < target) { //move to next node in normal inorder traversal if sum of curr values is smaller
            done1 = false; 
        } else if ((val1 + val2) > target) { //move to next node in reverse inorder traversal if sum of curr values is greater
            done2 = false;
        }
        if (val1 >= val2) //there is no pair if any of the inorder traversals is over 
            return false;
    }
}

int main() {
    struct node *root =  getNode(15);
    root->left = getNode(10);
    root->right = getNode(20);
    root->left->left = getNode(8);
    root->left->right = getNode(12);
    root->right->left = getNode(16);
    root->right->right = getNode(25);
    if(!pairSumK(root, 33))
        cout<<"No such values are found\n";
    deleteTree(&root);
    return 0;
}
