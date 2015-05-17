//Trie or Digital Tree or Prefix Tree
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cassert>
using namespace std;

#define ALPHABET_SIZE 26
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')

struct node {
    struct node* children[ALPHABET_SIZE];
    int value; //non-zero for leaf node
};

struct node* getNode() {
    struct node* temp = (struct node *)malloc(sizeof(struct node));
    assert(temp); //just in case malloc fails
    temp->value = 0;
    for (int i=0; i<ALPHABET_SIZE; i++)
        temp->children[i] = NULL;
    return temp;
}

bool checkLeaf(struct node* node) { //check if node is a leaf node
    return (node->value != 0); //node is leaf if value is non zero
}

bool checkDelete(struct node* node) { //check if node can be deleted
    for (int i=0; i<ALPHABET_SIZE; i++)
        if (node->children[i])
            return false;
    return true; //node can be deleted if all its children are NULL
}

void insertTrie(struct node* node, char* key) {
    int len = strlen(key);
    for (int level=0; level<len; level++) {
        int idx = CHAR_TO_INDEX(key[level]);
        if (!node->children[idx]) //add a new child only if it is not yet seen
            node->children[idx] = getNode();
        node = node->children[idx]; //move to the child for next iteration
    }
    node->value = 1; //can be any non-zero value to indicate leaf node
}

bool deleteTrie(struct node* node, char* key, int level, int len) {
    if (node) {
        if (level==len) { //we have found the leaf node of the key in trie
            if (node->value) { //if it is actually a leaf node 
                node->value = 0; //mark as internal node
                if (checkDelete(node))
                    return true;
                else
                    return false;
            } else { //key is not in trie
                return false;
            }
        } else {
            int idx = CHAR_TO_INDEX(key[level]);
            if (deleteTrie(node->children[idx], key, level+1, len)){
                free(node->children[idx]); //free the memory
                node->children[idx] = NULL; //mark as NUll
                return (!checkLeaf(node) && checkDelete(node)); //recursively delete if node is not leaf and can be deleted
            } else {
                return false;
            }
        }
    } else {
        return false;
    }
}

void deleteTrie(struct node* node, char* key) {
    int n = strlen(key);
    if (n>0)
        deleteTrie(node, key, 0, n);
}

bool searchTrie(struct node* node, char* key) {
    int len = strlen(key);
    for (int level=0; level<len; level++) {
        int idx = CHAR_TO_INDEX(key[level]);
        if (!node->children[idx]) //child for the alphabet is NULL means key is not present
            return false;
        node = node->children[idx]; //move to the child for next iteration
    }
    return (node && (node->value != 0)); //key is present if node is not NULL and is a leaf node
}

int main() {
    char* keys[] = {"the", "a", "there", "answer", "any", "by", "bye", "their", "she", "sells", "sea", "shore", "the", "sheer"};
    struct node* root = getNode(); //dummy root node of trie
    for (int i=0; i<sizeof(keys)/sizeof(keys[0]); i++)
        insertTrie(root, keys[i]);
    cout<<"Key \'th\': "<<(searchTrie(root, "th")?"Found":"Not found")<<endl;
    cout<<"Key \'the\': "<<(searchTrie(root, "the")?"Found":"Not found")<<endl;
    cout<<"Key \'their\': "<<(searchTrie(root, "their")?"Found":"Not found")<<endl;
    cout<<"Key \'she\': "<<(searchTrie(root, "she")?"Found":"Not found")<<endl;
    cout<<"Key \'sh\': "<<(searchTrie(root, "sh")?"Found":"Not found")<<endl;
    cout<<"Key \'sho\': "<<(searchTrie(root, "sho")?"Found":"Not found")<<endl;
    deleteTrie(root, "the");
    cout<<"Key \'th\': "<<(searchTrie(root, "th")?"Found":"Not found")<<endl;
    cout<<"Key \'the\': "<<(searchTrie(root, "the")?"Found":"Not found")<<endl;
    cout<<"Key \'their\': "<<(searchTrie(root, "their")?"Found":"Not found")<<endl;
    cout<<"Key \'by\': "<<(searchTrie(root, "by")?"Found":"Not found")<<endl;
    cout<<"Key \'bye\': "<<(searchTrie(root, "bye")?"Found":"Not found")<<endl;
    cout<<"Key \'byo\': "<<(searchTrie(root, "byo")?"Found":"Not found")<<endl;
    return 0;
}
