//to mirror an Nary tree
#include<bits/stdc++.h>
using namespace std;

struct node {
    int data;
    vector<struct node *> children;
};

struct node * getNode(int key) {;
    struct node *temp = new struct node;
    assert(temp!=NULL);
    temp->data = key;
    return temp;
}

void printTree(struct node *node) {
    if (node) {
        queue<struct node *>q;
        q.push(node);
        while (!q.empty()) {
            int n = q.size();
            while (n>0) {
                struct node *p = q.front();
                q.pop();
                cout<<" "<<p->data;
                for (vector<struct node*>::iterator it = p->children.begin(); it != p->children.end(); it++)
                    q.push(*it);
                n--;
            }
        cout<<endl;
        }
    }
}

void mirror(struct node * node) {
    if (node) {
        for (vector<struct node*>::iterator it = node->children.begin(); it != node->children.end(); it++)
            mirror(*it);
        reverse(node->children.begin(), node->children.end());
    }
}

struct node *createTree() {
    struct node *r = getNode(10);
    (r->children).push_back(getNode(2));
    (r->children).push_back(getNode(34));
    (r->children).push_back(getNode(56));
    (r->children).push_back(getNode(100));
    (r->children[2]->children).push_back(getNode(1));
    (r->children[3]->children).push_back(getNode(7));
    (r->children[3]->children).push_back(getNode(8));
    (r->children[3]->children).push_back(getNode(9));
    return r;
}

int main() {
    struct node *root = createTree();
    cout<<"Tree Before Mirroring :\n";
    printTree(root);
    mirror(root);
    cout<<"Tree After Mirroring :\n";
    printTree(root);
    return 0;
}
