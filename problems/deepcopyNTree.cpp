//to deepcopy Nary tree with back edges
//compile using --std=c++11
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

void printTree(struct node *node, unordered_set<struct node *> *hash) {
    cout<<" "<<node->data;
    for (vector<struct node *>::iterator it = node->children.begin(); it != node->children.end(); it++) {
        unordered_set<struct node *>::iterator idx = hash->find(*it);
        if (idx == hash->end()) {
            hash->insert(*it);
            printTree(*it, hash);
        } else {
            cout<<" "<<(*it)->data<<"(backedge)";
        }
    }
}

void printTree(struct node *node) {
    unordered_set<struct node *> *hash = new unordered_set<struct node *>;
    printTree(node, hash);
    delete hash;
    cout<<endl;
}

struct node* deepcopy(struct node *node, unordered_map<struct node *, struct node *> *hash) {
    struct node *copy = getNode(node->data);
    pair<struct node* , struct node*> temp_pair(node, copy);
    hash->insert(temp_pair);
    for (vector<struct node*>::iterator it = node->children.begin(); it != node->children.end(); it++) {
        unordered_map<struct node *, struct node *>::iterator idx = hash->find(*it);
        if (idx == hash->end())
            copy->children.push_back(deepcopy(*it, hash));
        else
            copy->children.push_back(idx->second);
    }
    return copy;
}

struct node* deepcopy(struct node *node) {
    if (node) {
        unordered_map<struct node *, struct node *> *hash = new unordered_map<struct node *, struct node *>;
        struct node *copy = deepcopy(node, hash);
        delete hash;
        return copy;
    } else {
        return NULL;
    }
}

struct node *createTree() {
    struct node *r = getNode(1);
    struct node *r1 = getNode(2);
    struct node *r2 = getNode(3);
    struct node *r3 = getNode(4);
    struct node *r11 = getNode(5);
    struct node *r12 = getNode(6);
    struct node *r13 = getNode(7);
    struct node *r21 = getNode(8);
    struct node *r22 = getNode(9);
    struct node *r23 = getNode(10);
    struct node *r111 = getNode(11);
    struct node *r112 = getNode(12);
    r->children.push_back(r1);
    r->children.push_back(r2);
    r->children.push_back(r3);
    r1->children.push_back(r11);
    r1->children.push_back(r12);
    r1->children.push_back(r13);
    r2->children.push_back(r21);
    r2->children.push_back(r22);
    r2->children.push_back(r23);
    r11->children.push_back(r111);
    r11->children.push_back(r112);
    r11->children.push_back(r1);
    return r;
}

int main() {
    struct node *s = createTree();
    std::cout<<"Original Tree";
    printTree(s);
    struct node *d = deepcopy(s);
    std::cout<<"Duplicate Tree";
    printTree(d);
    return 0;
}
