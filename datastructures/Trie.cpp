// Trie or Digital Tree or Prefix Tree
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

bool checkLeaf(struct node* curr) { //check if curr is a leaf node
    return (curr->value != 0); //curr is leaf if value is non zero
}

bool checkDelete(struct node* curr) { //check if curr can be deleted
    for (int i=0; i<ALPHABET_SIZE; i++)
        if (curr->children[i])
            return false;
    return true; //curr can be deleted if all its children are NULL
}

void insertTrie(struct node* root, char* key) {
    int len = strlen(key);
    struct node* temp = root;
    for (int level=0; level<len; level++) {
        int idx = CHAR_TO_INDEX(key[level]);
        if (!temp->children[idx]) //add a new child only if it is not yet seen
            temp->children[idx] = getNode();
        temp = temp->children[idx]; //move to the child for next iteration
    }
    temp->value = 1; //can be any non-zero value to indicate leaf node
}

bool deleteTrie(struct node* curr, char* key, int level, int len) {
    if (curr) {
        if (level==len) { //we have found the leaf node of the key in trie
            if (curr->value) { //if it is actually a leaf node 
                curr->value = 0; //mark as internal node
                if (checkDelete(curr))
                    return true;
                else
                    return false;
            } else { //key is not in trie
                return false;
            }
        } else {
            int idx = CHAR_TO_INDEX(key[level]);
            if (deleteTrie(curr->children[idx], key, level+1, len)){
                free(curr->children[idx]); //free the memory
                curr->children[idx] = NULL; //mark as NUll
                return (!checkLeaf(curr) && checkDelete(curr)); //recursively delete if curr is not leaf and can be deleted
            } else {
                return false;
            }
        }
    } else {
        return false;
    }
}

void deleteTrie(struct node* root, char* key) {
    int n = strlen(key);
    if (n>0)
        deleteTrie(root, key, 0, n);
}

bool searchTrie(struct node* root, char* key) {
    int len = strlen(key);
    struct node* temp = root;
    for (int level=0; level<len; level++) {
        int idx = CHAR_TO_INDEX(key[level]);
        if (!temp->children[idx]) //child for the alphabet is NULL means key is not present
            return false;
        temp = temp->children[idx]; //move to the child for next iteration
    }
    return (temp && (temp->value != 0)); //key is present if temp is not NULL and is a leaf node
}

int main() {
    char* keys[] = {"the", "a", "there", "answer", "any", "by", "bye", "their", "she", "sells", "sea", "shore", "the", "sheer"};
    struct node* t = getNode(); //dummy first node of trie
    for (int i=0; i<sizeof(keys)/sizeof(keys[0]); i++)
        insertTrie(t, keys[i]);
    cout<<"Key \'th\': "<<(searchTrie(t, "th")?"Found":"Not found")<<endl;
    cout<<"Key \'the\': "<<(searchTrie(t, "the")?"Found":"Not found")<<endl;
    cout<<"Key \'their\': "<<(searchTrie(t, "their")?"Found":"Not found")<<endl;
    cout<<"Key \'she\': "<<(searchTrie(t, "she")?"Found":"Not found")<<endl;
    cout<<"Key \'sh\': "<<(searchTrie(t, "sh")?"Found":"Not found")<<endl;
    cout<<"Key \'sho\': "<<(searchTrie(t, "sho")?"Found":"Not found")<<endl;
    deleteTrie(t, "the");
    cout<<"Key \'th\': "<<(searchTrie(t, "th")?"Found":"Not found")<<endl;
    cout<<"Key \'the\': "<<(searchTrie(t, "the")?"Found":"Not found")<<endl;
    cout<<"Key \'their\': "<<(searchTrie(t, "their")?"Found":"Not found")<<endl;
    cout<<"Key \'by\': "<<(searchTrie(t, "by")?"Found":"Not found")<<endl;
    cout<<"Key \'bye\': "<<(searchTrie(t, "bye")?"Found":"Not found")<<endl;
    cout<<"Key \'byo\': "<<(searchTrie(t, "byo")?"Found":"Not found")<<endl;
    return 0;
}
