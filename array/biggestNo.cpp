//rearrange nos in container to form the biggest no
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int compare(string X, string Y) { //used by qsort
    string XY = X.append(Y);
    string YX = Y.append(X);
    return XY.compare(YX) > 0 ? 1: 0;
}

void biggestNo(vector<string> arr) {
    vector<string> temp = arr;
    sort(temp.begin(), temp.end(), compare); 
    for (int i=0; i<temp.size(); i++ )
        cout<<temp[i];
    cout<<endl;
}

int main() {
    vector<string> arr1, arr2, arr3;
 
    arr1.push_back("54");
    arr1.push_back("546");
    arr1.push_back("548");
    arr1.push_back("60");

    arr2.push_back("7");
    arr2.push_back("776");
    arr2.push_back("7");
    arr2.push_back("7");
    
    arr3.push_back("1");
    arr3.push_back("34");
    arr3.push_back("3");
    arr3.push_back("98");
    arr3.push_back("9");
    arr3.push_back("76");
    arr3.push_back("45");
    arr3.push_back("4");
    
    biggestNo(arr1);
    biggestNo(arr2);
    biggestNo(arr3);
    return 0;
}
