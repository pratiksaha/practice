//efficient data structure
#include<iostream>
#include<cstdlib>
#include<climits>
#include<algorithm>
using namespace std;

struct DLLNode {
    int data;
    int minHeapIndex;
    int maxHeapIndex;
    struct DLLNode *next, *prev;
};

struct List {
    struct DLLNode *head;
};

struct MinHeap {
    int size;
    int capacity;
    struct DLLNode* *array;
};

struct MaxHeap {
    int size;
    int capacity;
    struct DLLNode* *array;
};

struct EffDS {
    struct MinHeap* minHeap;
    struct MaxHeap* maxHeap;
    struct List* list;
};

struct DLLNode* getDLLNode(int data) {
    struct DLLNode* node = (struct DLLNode*) malloc(sizeof(struct DLLNode));
    node->minHeapIndex = node->maxHeapIndex = -1;
    node->data = data;
    node->prev = node->next = NULL;
    return node;
}

struct MaxHeap* createMaxHeap(int capacity) {
    struct MaxHeap* maxHeap = (struct MaxHeap*) malloc(sizeof(struct MaxHeap));
    maxHeap->size = 0;
    maxHeap->capacity = capacity;
    maxHeap->array = (struct DLLNode**) malloc(maxHeap->capacity * sizeof(struct DLLNode*));
    return maxHeap;
}

struct MinHeap* createMinHeap(int capacity) {
    struct MinHeap* minHeap = (struct MinHeap*) malloc(sizeof(struct MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (struct DLLNode**) malloc(minHeap->capacity * sizeof(struct DLLNode*));
    return minHeap;
}

struct List* createList() {
    struct List* list = (struct List*) malloc(sizeof(struct List));
    list->head = NULL;
    return list;
}

struct EffDS* createEffDS(int capacity) {
    struct EffDS* effDS = (struct EffDS*) malloc(sizeof(struct EffDS));
    effDS->minHeap = createMinHeap(capacity);
    effDS->maxHeap = createMaxHeap(capacity);
    effDS->list = createList();
    return effDS;
}

int isMaxHeapEmpty(struct MaxHeap* heap) {
    return (heap->size == 0);
}
 
int isMinHeapEmpty(struct MinHeap* heap) {
    return heap->size == 0;
}
 
int isMaxHeapFull(struct MaxHeap* heap) {
    return heap->size == heap->capacity;
}
 
int isMinHeapFull(struct MinHeap* heap) {
    return heap->size == heap->capacity;
}
 
int isListEmpty(struct List* list) {
    return !list->head;
}
 
int hasOnlyOneDLLNode(struct List* list) {
    return !list->head->next && !list->head->prev;
}

void minHeapify(struct MinHeap* minHeap, int index) {
    int smallest, left, right;
    smallest = index;
    left = 2*index+1;
    right = 2*index+2;
    if (minHeap->array[left] && left < minHeap->size && minHeap->array[left]->data < minHeap->array[smallest]->data)
        smallest = left;
    if (minHeap->array[right] && right < minHeap->size && minHeap->array[right]->data < minHeap->array[smallest]->data)
        smallest = right;
    if (smallest != index) {
        swap(minHeap->array[smallest]->minHeapIndex, minHeap->array[index]->minHeapIndex);
        swap(minHeap->array[smallest], minHeap->array[index]);
        minHeapify(minHeap, smallest);
    }
}

void maxHeapify(struct MaxHeap* maxHeap, int index) {
    int largest, left, right;
    largest = index;
    left = 2*index+1;
    right = 2*index+2;
    if (maxHeap->array[left] && left < maxHeap->size && maxHeap->array[left]->data > maxHeap->array[largest]->data)
        largest = left;
    if (maxHeap->array[right] && right < maxHeap->size && maxHeap->array[right]->data > maxHeap->array[largest]->data)
        largest = right;
    if (largest != index) {
        swap(maxHeap->array[largest]->maxHeapIndex, maxHeap->array[index]->maxHeapIndex);
        swap(maxHeap->array[largest], maxHeap->array[index]);
        maxHeapify(maxHeap, largest);
    }
}

void insertMinHeap(struct MinHeap* minHeap, struct DLLNode* temp) {
    if (isMinHeapFull(minHeap))
        return;
    minHeap->size += 1;
    int i = minHeap->size - 1;
    while (i && temp->data < minHeap->array[(i-1)/2]->data) {
        minHeap->array[i] = minHeap->array[(i-1)/2];
        minHeap->array[i]->minHeapIndex = i;
        i = (i-1)/2;
    }
    minHeap->array[i] = temp;
    minHeap->array[i]->minHeapIndex = i;
}

void insertMaxHeap(struct MaxHeap* maxHeap, struct DLLNode* temp) {
    if (isMaxHeapFull(maxHeap))
        return;
    maxHeap->size += 1;
    int i = maxHeap->size - 1;
    while (i && temp->data > maxHeap->array[(i-1)/2]->data) {
        maxHeap->array[i] = maxHeap->array[(i-1)/2];
        maxHeap->array[i]->maxHeapIndex = i;
        i = (i-1)/2;
    }
    maxHeap->array[i] = temp;
    maxHeap->array[i]->maxHeapIndex = i;
}

int findMin(struct EffDS* effDS) {
    if (isMinHeapEmpty(effDS->minHeap))
        return INT_MAX; 
    return effDS->minHeap->array[0]->data;
}

int findMax(struct EffDS* effDS) {
    if (isMaxHeapEmpty(effDS->maxHeap))
        return INT_MIN;
    return effDS->maxHeap->array[0]->data;
}

void removeDLLNode(struct List* list, struct DLLNode** temp) {
    if (hasOnlyOneDLLNode(list)) {
        list->head = NULL;
    } else if (!(*temp)->prev) {
        list->head = (*temp)->next;
        (*temp)->next->prev = NULL;
    } else {
        (*temp)->prev->next = (*temp)->next;
        if ((*temp)->next)
            (*temp)->next->prev = (*temp)->prev;
    }
    free(*temp);
    *temp = NULL;
}

void deleteMax(struct EffDS* effDS) {
    MinHeap *minHeap = effDS->minHeap;
    MaxHeap *maxHeap = effDS->maxHeap; 
    if (isMaxHeapEmpty(maxHeap))
        return;
    struct DLLNode* temp = maxHeap->array[0];
    maxHeap->array[0] = maxHeap->array[maxHeap->size - 1];
    maxHeap->size -= 1;
    maxHeap->array[0]->maxHeapIndex = 0;
    maxHeapify(maxHeap, 0);
    minHeap->array[temp->minHeapIndex] = minHeap->array[minHeap->size - 1];
    minHeap->size -= 1;
    minHeap->array[temp->minHeapIndex]->minHeapIndex = temp->minHeapIndex;
    minHeapify(minHeap, temp->minHeapIndex);
    removeDLLNode(effDS->list, &temp);
}

void deleteMin(struct EffDS* effDS) {
    MinHeap *minHeap = effDS->minHeap;
    MaxHeap *maxHeap = effDS->maxHeap;
    if (isMinHeapEmpty(minHeap))
        return;
    struct DLLNode* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    minHeap->size -= 1;
    minHeap->array[0]->minHeapIndex = 0;
    minHeapify(minHeap, 0);
    maxHeap->array[temp->maxHeapIndex] = maxHeap->array[maxHeap->size - 1];
    maxHeap->size -= 1;
    maxHeap->array[temp->maxHeapIndex]->maxHeapIndex = temp->maxHeapIndex;
    maxHeapify(maxHeap, temp->maxHeapIndex);
    removeDLLNode(effDS->list, &temp);
}

void insertAtHead(struct List* list, struct DLLNode* temp) {
    if (isListEmpty(list)) {
        list->head = temp;
    } else {
        temp->next = list->head;
        list->head->prev = temp;
        list->head = temp;
    }
}

void Delete(struct EffDS* effDS, int data) {
    MinHeap *minHeap = effDS->minHeap;
    MaxHeap *maxHeap = effDS->maxHeap;
    if (isListEmpty(effDS->list))
        return;
    struct DLLNode* temp = effDS->list->head;
    while (temp && temp->data != data)
        temp = temp->next;
    if (!temp || temp && temp->data != data)
        return;
    minHeap->array[temp->minHeapIndex] = minHeap->array[minHeap->size - 1];
    minHeap->size -= 1;
    minHeap->array[temp->minHeapIndex]->minHeapIndex = temp->minHeapIndex;
    minHeapify(minHeap, temp->minHeapIndex);
    maxHeap->array[temp->maxHeapIndex] = maxHeap->array[maxHeap->size - 1];
    maxHeap->size -= 1;
    maxHeap->array[temp->maxHeapIndex]->maxHeapIndex = temp->maxHeapIndex;
    maxHeapify(maxHeap, temp->maxHeapIndex);
    removeDLLNode(effDS->list, &temp);
}

void Insert(struct EffDS* effDS, int data) {
    struct DLLNode* temp = getDLLNode(data);
    insertAtHead(effDS->list, temp);
    insertMinHeap(effDS->minHeap, temp);
    insertMaxHeap(effDS->maxHeap, temp);
}

int main() {
    struct EffDS *effDS = createEffDS(10);
    Insert(effDS, 10);
    Insert(effDS, 20);
    Insert(effDS, 30);
    Insert(effDS, 40);
    Insert(effDS, 50);
    cout<<"Maximum = "<<findMax(effDS)<<endl;
    cout<<"Minimum = "<<findMin(effDS)<<endl;
    deleteMax(effDS);
    cout<<"Maximum = "<<findMax(effDS)<<endl;
    cout<<"Minimum = "<<findMin(effDS)<<endl;
    deleteMin(effDS);
    cout<<"Maximum = "<<findMax(effDS)<<endl;
    cout<<"Minimum = "<<findMin(effDS)<<endl;
    Delete(effDS, 30);
    cout<<"Maximum = "<<findMax(effDS)<<endl;
    cout<<"Minimum = "<<findMin(effDS)<<endl;
    return 0;
}
