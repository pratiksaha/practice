//to find k most frequent word
#include<iostream>
#include<cstring>
#include<cctype>
#include<cstdlib>
using namespace std;
#define MAX_CHARS 26
 
struct TrieNode {
    bool isEnd;
    int frequency;
    int indexMinHeap;
    struct TrieNode* child[MAX_CHARS];
};

struct MinHeapNode {
    TrieNode* root; 
    int frequency;
    char* word;
};

struct MinHeap {
    unsigned capacity;
    int count;
    MinHeapNode* array;
};

struct TrieNode* getTrieNode() {
    struct TrieNode* trieNode = new TrieNode;
    trieNode->isEnd = 0;
    trieNode->frequency = 0;
    trieNode->indexMinHeap = -1;
    for(int i=0; i<MAX_CHARS; i++ )
        trieNode->child[i] = NULL;
    return trieNode;
}

struct MinHeap* createMinHeap(int size) {
    struct MinHeap* minHeap = new MinHeap;
    minHeap->array = new MinHeapNode[size];
    minHeap->capacity = size;
    minHeap->count = 0;
    return minHeap;
}

void minHeapify(struct MinHeap* minHeap, int idx ) {
    int left = 2*idx + 1;
    int right = 2*idx + 2;
    int smallest = idx;
    if (left < minHeap->count && minHeap->array[left].frequency < minHeap->array[smallest].frequency)
        smallest = left;
    if (right < minHeap->count && minHeap->array[right].frequency < minHeap->array[smallest].frequency)
        smallest = right;
    if(smallest != idx) {
        minHeap->array[smallest].root->indexMinHeap = idx;
        minHeap->array[idx].root->indexMinHeap = smallest;
        swap(minHeap->array[smallest], minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

void buildMinHeap(struct MinHeap* minHeap) {
    int n = minHeap->count - 1;
    for(int i=(n-1)/2; i>=0; i--)
        minHeapify(minHeap, i);
}

void insertMinHeap(struct MinHeap* minHeap, struct TrieNode** root, char* word) {
    if((*root)->indexMinHeap != -1) { //word is already present in min heap
        minHeap->array[(*root)->indexMinHeap].frequency += 1;
        minHeapify(minHeap, (*root)->indexMinHeap); //increase the frequency and maintain heap property
    } else if( minHeap->count < minHeap->capacity ) { //word is not present & heap is not full
        int count = minHeap->count;
        minHeap->array[count].frequency = (*root)->frequency;
        minHeap->array[count].word = new char [strlen(word)+1];
        strcpy(minHeap->array[count].word, word);
        minHeap->array[count].root = *root;
        (*root)->indexMinHeap = minHeap->count;
        minHeap->count += 1;
        buildMinHeap(minHeap); //insert into heap and build the heap
    } else if ((*root)->frequency > minHeap->array[0].frequency) { //word is not present & heap is full & is more than root 
        minHeap->array[0].root->indexMinHeap = -1;
        minHeap->array[0].root = *root;
        minHeap->array[0].root->indexMinHeap = 0;
        minHeap->array[0].frequency = (*root)->frequency;
        delete [] minHeap->array[0].word;
        minHeap->array[0]. word = new char [strlen(word)+1];
        strcpy(minHeap->array[0].word, word);
        minHeapify(minHeap, 0); //replace the root of the heap with word and maintain heap property
    }
}
 
void insertTrieAndHeap(struct TrieNode** root, struct MinHeap* minHeap, char* word, char* dupWord) {
    if (!(*root))
        *root = getTrieNode();
    if (*word) { //recur for remainning word
        insertTrieAndHeap(&((*root)->child[tolower(*word)-97]), minHeap, word+1, dupWord);
    } else { //reached end of word
        if ((*root)->isEnd) { //increase the frequency if word is already present in trie
            (*root)->frequency += 1;
        } else { //mark as a word and set frequency to 1
            (*root)->isEnd = true;
            (*root)->frequency = 1;
        }
        insertMinHeap(minHeap, root, dupWord);
    }
}

void displayMinHeap(struct MinHeap* minHeap ) {
    for(int i=0; i<minHeap->count; i++)
        cout<<minHeap->array[i].word<<" : "<<minHeap->array[i].frequency<<endl;
}

void kMostFrequentWord(char *str, int k) {
    struct MinHeap* minHeap = createMinHeap(k);
    struct TrieNode* root = NULL;
    char *ptr = strtok(str, " ,.?!");
    while (ptr) {
        //cout<<ptr<<" "<<sizeof(ptr)<<endl;
        insertTrieAndHeap(&root, minHeap, ptr, ptr);
        ptr = strtok(NULL, " ,.?!");
    }
    displayMinHeap(minHeap);
}
 
int main() {
    char str[] = "A programming language is a formal constructed language designed to communicate instructions to a machine, particularly a computer. Programming languages can be used to create programs to control the behavior of a machine or to express algorithms.The earliest programming languages preceded the invention of the digital computer and were used to direct the behavior of machines such as Jacquard looms and player pianos. Thousands of different programming languages have been created, mainly in the computer field, and many more still are being created every year. Many programming languages require computation to be specified in an imperative form i.e., as a sequence of operations to perform, while other languages utilize other forms of program specification such as the declarative form i.e. the desired result is specified, not how to achieve it.";
    kMostFrequentWord(str, 5);
    return 0;
}
