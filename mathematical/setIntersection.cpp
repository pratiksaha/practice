//to find intersection of n sets
//Using features of C++ Standard (2011) Compile using g++ -std=c++11
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

vector <int> setIntersection(vector <vector <int> > &sets) {
    vector<int> result;
    int smallSetInd = 0;
    int minSize = sets[0].size();
    for (int i=1; i<sets.size(); i++) {
        sort(sets[i].begin(), sets[i].end());
        if (minSize > sets[i].size()) {
            minSize = sets[i].size();
            smallSetInd = i;
        }
    }
    unordered_map<int,int> elementsMap;
    for (int i=0; i<sets[smallSetInd].size(); i++) {
        if (elementsMap.find(sets[smallSetInd][i] ) == elementsMap.end())
            elementsMap[sets[smallSetInd][i]] = 1;
        else
            elementsMap[sets[smallSetInd][i]]++;
    }
    for (unordered_map<int,int>::iterator it=elementsMap.begin(); it!=elementsMap.end(); it++) {
        int elem = it->first;
        int freq = it->second;
        bool bFound = true;
        for (int j=0; j<sets.size(); j++) {
            if (j != smallSetInd) {
                if (binary_search(sets[j].begin(), sets[j].end(), elem)) {
                   int lInd = lower_bound(sets[j].begin(), sets[j].end(), elem) - sets[j].begin();
                   int rInd = upper_bound(sets[j].begin(), sets[j].end(), elem) - sets[j].begin();
                   if ((rInd - lInd) < freq)
                       freq = rInd - lInd;
                } else {
                    bFound = false;
                    break;
                }
            }
        }
        if (bFound) {
            for (int k=0; k<freq; k++)
                result.push_back(elem);
        }
    }
    return result;
}

int main() {
    vector<int> set1;
    set1.push_back(1);
    set1.push_back(2);
    set1.push_back(4);
    set1.push_back(5);
    set1.push_back(6);
    vector<int> set2;
    set2.push_back(1);
    set2.push_back(10);
    set2.push_back(4);
    set2.push_back(3);
    set2.push_back(5);
    set2.push_back(9);
    vector<int> set3;
    set3.push_back(1);
    set3.push_back(4);
    set3.push_back(2);
    set3.push_back(3);
    set3.push_back(5);
    set3.push_back(6);
    vector<vector <int> > sets;
    sets.push_back(set1);
    sets.push_back(set2);
    sets.push_back(set3);
    vector<int> r = setIntersection(sets);
    cout<<"Set Intersection :";
    for (vector<int>::iterator it=r.begin(); it!=r.end(); it++)
        cout<<" "<<*it;
    cout<<endl;
    return 0;
}
