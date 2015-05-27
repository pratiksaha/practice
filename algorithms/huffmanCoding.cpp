//huffman coding
#include<iostream>
#include<cstdlib>
#include<cassert>
using namespace std;

struct minHeapNode {
    char data;
    int freq;
    struct minHeapNode *left, *right;
};

struct minHeap {
    int size, capacity;
    struct minHeapNode **nodes;
};

struct minHeapNode* getMinHeapNode(char data, int freq) {
    struct minHeapNode *temp = (struct minHeapNode *)malloc(sizeof(minHeapNode));
    assert(temp);
    temp->data = data;
    temp->freq = freq;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

struct minHeap* createMinHeap(int n) {
    struct minHeap* temp = (struct minHeap*)malloc(sizeof(struct minHeap));
    assert(temp);
    temp->nodes = (struct minHeapNode**)malloc(n*sizeof(struct minHeapNode*));
    assert(temp->nodes);
    temp->size = 0;
    temp->capacity = n;
    return temp;
}

void minHeapify(struct minHeap* heap, int idx) {
    int smallest = idx;
    int left = 2*idx + 1;
    int right = 2*idx + 2;
    if (left < heap->size && heap->nodes[left]->freq < heap->nodes[smallest]->freq)
        smallest = left;
    if (right < heap->size && heap->nodes[right]->freq < heap->nodes[smallest]->freq)
        smallest = right; 
    if (smallest != idx) {
        swap(heap->nodes[smallest], heap->nodes[idx]);
        minHeapify(heap, smallest);
    }
}

void buildMinHeap(struct minHeap* heap) {
    int n = heap->size - 1;
    for (int i=(n-1)/2; i>=0; i--)
        minHeapify(heap, i);
}

struct minHeap* createAndBuildMinHeap(char *data, int *freq, int n) {
    struct minHeap* temp = createMinHeap(n);
    for (int i=0; i<n; i++)
        temp->nodes[i] = getMinHeapNode(*(data+i), *(freq+i));
    temp->size = n;
    buildMinHeap(temp);
    return temp;
}

void insertMinHeap(struct minHeap* heap, struct minHeapNode* node) {
    int i = heap->size;
    while (i && node->freq < heap->nodes[(i-1)/2]->freq) {
        heap->nodes[i] = heap->nodes[(i-1)/2];
        i = (i-1)/2;
    }
    heap->nodes[i] = node;
    heap->size += 1;
}

struct minHeapNode* extractMin(struct minHeap* heap) {
    struct minHeapNode* temp = heap->nodes[0];
    heap->nodes[0] = heap->nodes[heap->size - 1];
    heap->size -= 1;
    minHeapify(heap, 0);
    return temp;
}

struct minHeapNode* buildHuffmanTree(char *data, int *freq, int n) {
    struct minHeap *root = createAndBuildMinHeap(data,freq, n);
    while (root->size != 1) { //until we have only one node in the huffman tree 
        struct minHeapNode *left = extractMin(root);
        struct minHeapNode *right = extractMin(root);
        struct minHeapNode *top = getMinHeapNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        insertMinHeap(root, top);
    }
    return extractMin(root);
}

void printHuffmanCode(struct minHeapNode *node, int *code, int idx) {
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

int height(struct minHeapNode* node) {
    if (node)
        return height(node->left) + height(node->right) + 1;
    else
        return 0;  
}

void huffmanCoding(char *data, int *freq, int n) {
    struct minHeapNode *root = buildHuffmanTree(data, freq, n);
    int code[height(root)];
    printHuffmanCode(root, code, 0);
} 


int main() {
    char data[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    huffmanCoding(data, freq, sizeof(data)/sizeof(data[0]));
    return 0;
}
