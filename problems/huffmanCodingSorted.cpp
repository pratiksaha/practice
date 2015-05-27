//huffman coding for sorted input in linear time
#include<iostream>
#include<cstdlib>
#include<cassert>
#include<queue>
using namespace std;

struct node {
    char data;
    int freq;
    struct node *left, *right;
};

struct node* getNode(char data, unsigned freq) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    assert(temp);
    temp->data = data;
    temp->freq = freq;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

struct node* getMinNode(queue<struct node *> *fq, queue<struct node *> *sq){
    struct node* temp;
    if (fq->size() == 0 && sq->size() == 0) {
        assert(0); //something wrong
    } else if (fq->size() == 0) {
        temp = sq->front();
        sq->pop();
    } else if (sq->size() == 0) {
        temp = fq->front();
        fq->pop();
    } else {
        if (fq->front()->freq < sq->front()->freq) {
            temp = fq->front();
            fq->pop();
        } else {
            temp = sq->front();
            sq->pop();
        }
    }
    return temp;
}

struct node* buildHuffmanTree(char *data, int *freq, int n) {
    queue<struct node *> fq;
    queue<struct node *> sq;
    for (int i=0; i<n; i++) //push everything to first queue
        fq.push(getNode(*(data+i), *(freq+i)));
    while (!(fq.size() == 0 && sq.size() == 1)) {
        struct node *left = getMinNode(&fq, &sq);
        struct node *right = getMinNode(&fq, &sq);
        struct node *top = getNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        sq.push(top);
    }
    struct node *temp = sq.front();
    sq.pop();
    return temp;
}

void printHuffmanCode(struct node *node, int *code, int idx) {
    if (node->left) {
        *(code+idx) = 0;
        printHuffmanCode(node->left, code, idx+1);
    }
    if (node->right) {
        *(code+idx) = 1;
        printHuffmanCode(node->right, code, idx+1);
    }
    if (!(node->right || node->left)) { //node is a leaf
        cout<<node->data<<" : ";
        for (int i=0; i<idx; i++)
            cout<<*(code+i);
        cout<<endl;
    }  
}

int height(struct node* node) {
    if (node)
        return height(node->left) + height(node->right) + 1;
    else
        return 0;  
}

void huffmanCoding(char *data, int *freq, int n) {
    struct node *root = buildHuffmanTree(data, freq, n);
    int code[height(root)];
    printHuffmanCode(root, code, 0);
} 

int main() {
    char data[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    huffmanCoding(data, freq, sizeof(data)/sizeof(data[0]));
    return 0;
}
