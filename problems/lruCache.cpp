//LRU cache
#include<iostream>
#include<cstdlib>
#include<vector>
using namespace std;
#define CACHE_SIZE 4

struct page {
    int pageNo;
    char address;
};

void lruCache(vector<struct page *> *cache, int pageNumber) {
    vector<struct page *>::iterator reqPage = cache->end();
    for (vector<struct page *>::iterator it = cache->begin(); it != cache->end(); it++)
        if ((*it)->pageNo == pageNumber)
           reqPage = it;
    if (cache->size() >= CACHE_SIZE) { //if cache is full
        if (reqPage != cache->end()) //delete the page temporarily if page is in cache
            cache->erase(reqPage);
        else //delete the least recently used if page is not in cache
            cache->pop_back();
    }
    struct page* currPage = (struct page*)malloc(sizeof(struct page));
    currPage->pageNo = pageNumber;
    currPage->address = (char)(pageNumber+97);
    cache->insert(cache->begin(), currPage); //always insert into the front
}

int main() {
    vector<struct page *> pageTable;
    lruCache(&pageTable, 1);
    lruCache(&pageTable, 2);
    lruCache(&pageTable, 3);
    lruCache(&pageTable, 1);
    lruCache(&pageTable, 4);
    lruCache(&pageTable, 5);
    for (vector<struct page *>::iterator it = pageTable.begin(); it != pageTable.end(); it++)
        cout<<(*it)->pageNo<<" : "<<(*it)->address<<endl;
    return 0;
}
