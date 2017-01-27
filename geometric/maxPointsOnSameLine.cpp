//to find maximum number of points which lie on same line
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

int maxPointsOnSameLine(vector< pair<int, int> > points) {
    int n = points.size();
    if (n < 2)
        return n;
    int maxPoint = 0;
    int curMax, overlapPoints, verticalPoints;

    unordered_map<pair<int, int>, int, pair_hash> slopeMap;
    
    for (int i=0; i<n; i++) {
        curMax = overlapPoints = verticalPoints = 0;
        for (int j=i+1; j<n; j++) {
            if (points[i] == points[j]) {
                overlapPoints++;
            } else if (points[i].first == points[j].first) {
                verticalPoints++;
 
            } else {
                int yDif = points[j].second - points[i].second;
                int xDif = points[j].first - points[i].first;
                int g = __gcd(xDif, yDif);
                yDif /= g;
                xDif /= g;
                slopeMap[make_pair(yDif, xDif)]++;
                curMax = max(curMax, slopeMap[make_pair(yDif, xDif)]);
            }
            curMax = max(curMax, verticalPoints);
        }
        maxPoint = max(maxPoint, curMax + overlapPoints + 1);
        slopeMap.clear();
    }
    return maxPoint;
}

int main(){
    const int N = 6;
    int arr[N][2] = {{-1, 1}, {0, 0}, {1, 1}, {2, 2}, {3, 3}, {3, 4}};
    vector< pair<int, int> > points;
    for (int i = 0; i < N; i++)
        points.push_back(make_pair(arr[i][0], arr[i][1]));
    cout<<"Max no of points that lie on the same line is "<<maxPointsOnSameLine(points)<<endl;
    return 0;
}
