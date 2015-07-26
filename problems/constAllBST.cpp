//to construct all unique BSTs for keys from 1 to n
#include<iostream>
#include<cstdlib>
#include<vector>
using namespace std;

struct node {
    int key;
    struct node *left, *right;
};
 
struct node *getNode(int data) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->key = data;
    temp->left = temp->right = NULL;
    return temp;
}

void printTree(struct node *node) {
    if (node) {
        cout<<" "<<node->key;
        printTree(node->left);
        printTree(node->right);
    }
}

vector<struct node *> constAllBST(int start, int end) {
    vector<struct node *> list;
    if (start > end) {
        list.push_back(NULL);
        return list;
    } else {
        for (int i=start; i<=end; i++) {
            vector<struct node *> leftSubtree  = constAllBST(start, i-1);
            vector<struct node *> rightSubtree = constAllBST(i+1, end);
            for (int j=0; j<leftSubtree.size(); j++) {
                struct node *left = leftSubtree[j];
                for (int k=0; k<rightSubtree.size(); k++) {
                    struct node *right = rightSubtree[k];
                    struct node *node = getNode(i);
                    node->left = left;
                    node->right = right;
                    list.push_back(node);
                }
            }
        }
    }
    return list;
}

int main() {
    vector<struct node *> all = constAllBST(1, 3);
    cout<<"Preorder traversal of all constructed BSTs are :\n";
    for (int i = 0; i < all.size(); i++) {
        printTree(all[i]);
        cout<<endl;
    }
    return 0;
}
