//datastructure with insert delete search and getrandom in theta(1)
//Using features of C++ Standard (2011) Compile using g++ -std=c++11
#include<iostream>
#include<unordered_map>
#include<cstdlib>
#include<ctime>
#include<unistd.h> //only on unix used for usleep while getting random number
using namespace std;

template <class T>
class DS {
private:
    unordered_map<T, int> elem;
public:
    void insertDS(T);
    void deleteDS(T);
    T searchDS(T);
    T getRandomDS();
    void printDS();
};

template <class T>
void DS<T>:: insertDS(T key) {
    typename unordered_map<T, int>::iterator it = elem.find(key);
    if (it != elem.end()) {
        cout<<key<<" is already present in data structure\n";
    } else {
        elem.insert(make_pair(key, 1));   
    }
}

template <class T>
void DS<T>:: deleteDS(T key) {
    typename unordered_map<T, int>::iterator it = elem.find(key);
    if (it != elem.end()) {
        elem.erase(key);
    } else {
        cout<<key<<" is not present in data structure\n";   
    }
}

template <class T>
T DS<T>:: searchDS(T key) {
    typename unordered_map<T, int>::iterator it = elem.find(key);
    if (it != elem.end()) {
        return it->first;
    } else {
        return NULL;  
    }
}

template <class T>
T DS<T>:: getRandomDS() {
    typename unordered_map<T, int>::iterator it = elem.begin();
    srand(time(0));
    int i = rand()%(elem.size());
    advance(it, i);
    usleep(2000000); //sleep for 2 seconds
    return it->first;
}

template <class T>
void DS<T>:: printDS() {
    cout<<"Contents :";
    for (typename unordered_map<T, int>::iterator it = elem.begin(); it != elem.end(); it++)
        cout<<" "<<it->first;
    cout<<endl;
}

int main() {
    DS<int> intDS;
    intDS.insertDS(1);
    intDS.insertDS(5);
    intDS.insertDS(4);
    intDS.insertDS(8);
    intDS.insertDS(9);
    intDS.insertDS(1);
    intDS.deleteDS(4);
    intDS.deleteDS(4);;
    intDS.printDS();
    int a = intDS.searchDS(1);
    (a!=NULL) ? cout<<"1 Found\n" : cout<<"1 Not Found\n";
    int b = intDS.searchDS(4);
    (b!=NULL) ? cout<<"4 Found\n" : cout<<"4 Not Found\n";
    cout<<"Getting Random Integer "<<intDS.getRandomDS()<<endl;
    cout<<"Getting Random Integer "<<intDS.getRandomDS()<<endl;
    cout<<"Getting Random Integer "<<intDS.getRandomDS()<<endl;
    cout<<"Getting Random Integer "<<intDS.getRandomDS()<<endl;
    DS<char> charDS;
    charDS.insertDS('a');
    charDS.insertDS('b');
    charDS.insertDS('c');
    charDS.insertDS('d');
    charDS.insertDS('e');
    charDS.insertDS('f');
    charDS.printDS();
    return 0;
}
