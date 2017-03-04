//to print all subarrays in the array which has sum 0
//Using features of C++ Standard (2011) Compile using g++ -std=c++11
#include<bits/stdc++.h>
using namespace std;

vector< pair<int, int> > printZeroSumSubarrays(int arr[], int n) {
    unordered_map<int, vector<int> > map;
    vector <pair<int, int>> out;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        if (sum == 0)
            out.push_back(make_pair(0, i));
        if (map.find(sum) != map.end()) {
            vector<int> vc = map[sum];
            for (vector<int>::iterator it = vc.begin(); it != vc.end(); it++)
                out.push_back(make_pair(*it + 1, i));
        }
        map[sum].push_back(i);
    }
    return out;
}
 
void print(vector<pair<int, int>> out) {
    for (vector<pair<int, int>>::iterator it = out.begin(); it != out.end(); it++)
        cout<<"Subarray found from Index "<<it->first<<" to "<<it->second<<endl;
}

int main() {
    int arr[] = {6, 3, -1, -3, 4, -2, 2, 4, 6, -12, -7};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<pair<int, int> > out = printZeroSumSubarrays(arr, n);
    if (out.size() == 0)
        cout<<"No subarray exists\n";
    else
        print(out);
    return 0;
}
