//interval tree and its application
#include<iostream>
#include<cstdlib>
using namespace std;

struct interval {
    int low, high;
};

struct node {
    struct interval *i;
    int max;
    struct node *left, *right;
};

struct node* getNode(struct interval i) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    struct interval *intval = (struct interval *)malloc(sizeof(struct interval));
    *intval = i;
    temp->i = intval;
    temp->max = i.high;
    temp->left = temp->right = NULL;
};

void printTree(struct node *root) {
    if (root) {
        printTree(root->left);
        cout<<"["<<root->i->low<<", "<<root->i->high<<"]"<<" max="<<root->max<<endl;
        printTree(root->right);
    }
}

struct node* insert(struct node* root, struct interval i) { //TODO: update with balanced tree insertion
    if (root) {
        if (i.low < root->i->low) //new interval goes to left subtree if root's low value is smaller
            root->left = insert(root->left, i);
        else //new node goes to right subtree otherwise
            root->right = insert(root->right, i);
        if (root->max < i.high) //update the max value of the ancestor if required
            root->max = i.high;
        return root;
    } else {
        return getNode(i);
    }
}

bool checkOverlap(struct interval i1, struct interval i2) {
    if (i1.low <= i2.high && i2.low <= i1.high)
        return true;
    else
        return false;
}

struct interval* searchOverlap(struct node* root, struct interval i) {
    if (root) {
        if (checkOverlap(*(root->i), i)) //i overlaps with root
            return root->i;
        else if (root->left != NULL && root->left->max >= i.low)
            return searchOverlap(root->left, i);
        else
            return searchOverlap(root->right, i);
    } else {
        return NULL;
    }
}

int main() {
    //struct interval ints[] = {{15, 20}, {10, 30}, {17, 19}, {5, 20}, {12, 15}, {30, 40}};
    struct interval ints[] = {{1, 5}, {3, 7}, {2, 6}, {10, 15}, {5, 6}, {4, 100}};
    int n = sizeof(ints)/sizeof(ints[0]);
    struct node *root = NULL;
    root = insert(root, ints[0]);
    for (int i=1; i<n; i++) {
        struct interval *result = searchOverlap(root, ints[i]);
        if (result)
            cout<<"["<<ints[i].low<<","<<ints[i].high<<"] conflicts with ["<<result->low<<","<<result->high<<"]\n";
        root = insert(root, ints[i]);
    }
    cout<<"Interval Tree is :\n";
    printTree(root);
    return 0;
}
