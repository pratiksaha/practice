//to find maximum weight transformation of a given string
#include<iostream>
#include<string>
#include<cstring>
using namespace std;

int maxWeightTransform(string &str, int i, int n, int lookup[]) {
    if (i >= n)
        return 0;
    if (lookup[i] != -1)
        return lookup[i];
    int ans = 1 + maxWeightTransform(str, i+1, n, lookup); //weight gained is 1 if we can't make pair
    if (i+1 < n) { //we can make pair
        if (str[i] != str[i+1]) //weight gained is 4 if elements are dissmilar
            ans = max(4 + maxWeightTransform(str, i+2, n, lookup), ans);
        else //weight gain is 3 when we toggle since toggle cost is 1
            ans = max(3 + maxWeightTransform(str, i+2, n, lookup), ans);
    }
    return lookup[i] = ans; //save and return maxof above cases
}

int maxWeightTransform(string str) {
    int n = str.length();
    int lookup[n];
    memset(lookup, -1, sizeof lookup);
    return maxWeightTransform(str, 0, n, lookup);
}

int main() {
    string str = "AAAAABB";
    cout<<"Maximum weight of a transformation of "<<str<<" is "<<maxWeightTransform(str)<<endl;
    return 0;
}
