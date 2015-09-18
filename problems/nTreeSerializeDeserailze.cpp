//serialize and deserialize an N-ary tree
#include<iostream>
#include<vector>
using namespace std;
#define N 5

struct node {
   int data;
   struct node *child[N];
};

struct node *getNode(int key) {
    struct node *temp = new node;
    temp->data = key;
    for (int i=0; i<N; i++)
        temp->child[i] = NULL;
    return temp;
}

void serialize(struct node *node, vector<int> *res) {
    if (node == NULL)
        return;
    res->push_back(node->data);
    for (int i=0; i<N && node->child[i]; i++)
         serialize(node->child[i], res);
    res->push_back(-1);
}

int deserialize(struct node **node, vector<int> res, int *pos=0) {
    if(res[*pos] == -1 || *pos >= res.size()) {
        (*pos)++;
        return 1;
    }
    *node = getNode(res[*pos]);
    (*pos)++;
    for (int i = 0; i < N; i++)
        if (deserialize(&((*node)->child[i]), res, pos))
            break;
    return 0;
}

struct node *createDummyTree() {
    struct node *root = getNode(1);
    root->child[0] = getNode(2);
    root->child[1] = getNode(3);
    root->child[2] = getNode(4);
    root->child[0]->child[0] = getNode(5);
    root->child[0]->child[1] = getNode(6);
    root->child[2]->child[0] = getNode(7);
    root->child[2]->child[1] = getNode(8);
    root->child[2]->child[2] = getNode(9);
    root->child[2]->child[3] = getNode(10);
    root->child[0]->child[1]->child[0] = getNode(11);
    return root;
}

void printTree(struct node *root) {
    if (root) {
        cout<<" "<<root->data;
        for (int i=0; i<N; i++)
            printTree(root->child[i]);
    }
}

int main() {
    struct node* t = createDummyTree();
    cout<<"Original tree ", printTree(t), cout<<endl;
    vector<int> result;
    serialize(t, &result);
    struct node *r = NULL;
    int pos = 0;
    deserialize(&r, result, &pos);
    cout<<"After reconstruction of tree from serialized data ",printTree(r), cout<<endl;
    cout<<"Serialized Data :";
    for(vector<int>::iterator it=result.begin(); it != result.end(); it++)
        cout<<" "<<*it;
    cout<<endl;
    return 0;
}
