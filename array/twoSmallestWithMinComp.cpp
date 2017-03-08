//to find minimum and second minimum using minimum number of comparisons
#include<bits/stdc++.h>
using namespace std;

struct node {
    int idx;
    node *left, *right;
};

struct node *getNode(int idx) {
    struct node *t = new node;
    t->left = t->right = NULL;
    t->idx = idx;
    return t;
}

void traverseHeight(struct node *root, int arr[], int &res) {
    if (root == NULL || (root->left == NULL && root->right == NULL))
        return;
    if (res > arr[root->left->idx] && root->left->idx != root->idx) {
        res = arr[root->left->idx];
        traverseHeight(root->right, arr, res);
    } else if (res > arr[root->right->idx] && root->right->idx != root->idx) {
        res = arr[root->right->idx];
        traverseHeight(root->left, arr, res);
    }
}

void twoSmallestWithMinComp(int arr[], int n) {
    list<struct node *> li;
    struct node *root = NULL;
    for (int i = 0; i < n; i += 2) {
        struct node *t1 = getNode(i);
        struct node *t2 = NULL;
        if (i + 1 < n) {
            t2 = getNode(i + 1);
            root = (arr[i] < arr[i + 1])? getNode(i) : getNode(i + 1);
            root->left = t1;
            root->right = t2;
            li.push_back(root);
        } else {
            li.push_back(t1);
        }
    }
    int lsize = li.size();
    while (lsize != 1) {
        int last = (lsize & 1)? (lsize - 2) : (lsize - 1);
        for (int i = 0; i < last; i += 2) {
            node *f1 = li.front();
            li.pop_front();
            node *f2 = li.front();
            li.pop_front();
            root = (arr[f1->idx] < arr[f2->idx])? getNode(f1->idx) : getNode(f2->idx);
            root->left = f1;
            root->right = f2;
            li.push_back(root);
        }
        if (lsize & 1) {
            li.push_back(li.front());
            li.pop_front();
        }
        lsize = li.size();
    }
    int res = INT_MAX;
    traverseHeight(root, arr, res);
    cout<<"Minimum : "<<arr[root->idx]<<" , Second minimum : "<<res<<endl;
}

int main() {
    int arr[] = {61, 6, 100, 9, 10, 12, 17};
    int n = sizeof(arr)/sizeof(arr[0]);
    twoSmallestWithMinComp(arr, n);
    return 0;
}
