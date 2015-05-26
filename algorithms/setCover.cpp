//set cover problem
//Using features of C++ Standard (2011) Compile using g++ -std=c++11
#include<iostream>
#include<cfloat>
#include<unordered_set>
#include<unordered_map>
using namespace std;
#define N 3

int minIndex(float *arr, int n) {
    float currMin = arr[0];
    int idxMin = 0;
    for(int i=1; i<n; i++) {
        if (arr[i] < currMin) {
            currMin = arr[i];
            idxMin = i;
        }
    }
    return idxMin;
}

int diffCount(unordered_set<int> a,unordered_set<int> b) { //gives no of elements in set a-b
    int count = 0;
    for (unordered_set<int>::iterator ita = a.begin(); ita != a.end(); ita++) {
        unordered_set<int>::iterator itb = b.find(*ita);
        if (itb == b.end())
            count++;
    }
    return count++;
}

void setCover(unordered_set<int> *sets, int *costs) {
    unordered_set<int> U; //universe
    cout<<"Given Sets :\n";
    for (int i=0; i<N; i++) {
        cout<<"Set "<<i+1<<" :";
        for (unordered_set<int>::iterator it = sets[i].begin(); it != sets[i].end(); it++) {
            cout<<" "<<*it;
            U.insert(*it);
        }
        cout<<" Cost = "<<costs[i]<<endl;
    }
    unordered_set<int> I;
    unordered_map<int, int> hash;
    while (I != U) {
        float ratios[N];
        for (int i=0; i<N; i++) {
            unordered_map<int, int>::iterator it = hash.find(i);
            if (it != hash.end()) { //set is already included
                ratios[i] = FLT_MAX;
            } else {
                int diff = diffCount(sets[i], I);
                if (diff == 0) //escape division by zero error
                    ratios[i] = FLT_MAX;
                else
                    ratios[i] = costs[i]/diff;
            }
        }
        int idx = minIndex(ratios, N);
        for (unordered_set<int>::iterator it = sets[idx].begin(); it != sets[idx].end(); it++) {
            I.insert(*it);
        }
        hash.insert(make_pair(idx, costs[idx]));
    }
    cout<<"Set Cover Contains:\n";
    int cost = 0;
    for (unordered_map<int, int>::iterator it = hash.begin(); it != hash.end(); it++) {
        cout<<"Set "<<it->first+1<<" with cost "<<it->second<<endl;
        cost += it->second;
    }
    cout<<"Total Cost = "<<cost<<endl;
}

int main () {
    int n = 3;
    unordered_set<int> sets[N] = {  {4,1,3},
                                    {2,5},
                                    {1,4,3,2},
                                };
    int costs[N] = {5, 10, 3};
    setCover(sets, costs);
    return 0;
}
