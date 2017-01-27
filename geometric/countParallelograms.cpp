//to count number of parallelograms formed by given points on a plane
//Using features of C++ Standard (2011) Compile using g++ -std=c++11
#include<bits/stdc++.h>
#include<boost/functional/hash.hpp>
using namespace std;
using namespace boost;

struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1,T2> &p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);
        size_t seed = 0;
        hash_combine(seed, h1);
        hash_combine(seed, h2);
        return seed;  
    }
};


int countParallelograms(int x[], int y[], int N) {
    unordered_map<pair<int, int>, int, pair_hash> count;
    
    for (int i=0; i<N; i++) {
        for (int j=i+1; j<N; j++) {
            // division by 2 is ignored, to get rid of doubles
            int midX = x[i] + x[j];
            int midY = y[i] + y[j];
            unordered_map<pair<int, int>, int, pair_hash>::iterator it = count.find(make_pair(midX, midY));
            if (it == count.end())
                count.insert(make_pair(make_pair(midX, midY), 1));
            else
                it->second = it->second+1;
        }
    }
    int res = 0;
    for (unordered_map<pair<int, int>, int, pair_hash>::iterator it = count.begin(); it != count.end(); it++)
        res += it->second*(it->second - 1)/2; //increase the count of Parallelograms by applying function on frequency of mid point
    return res;
}

int main() {
    int x[] = {0, 0, 2, 4, 1, 3};
    int y[] = {0, 2, 2, 2, 4, 4};
    int N = sizeof(x) / sizeof(int);
    cout<<"No of parallelograms : "<<countParallelograms(x, y, N)<<endl;
    return 0;
}
