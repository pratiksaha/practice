//to find the next lexicographically greater permutation of a word without using next_permutation of STL
#include<bits/stdc++.h>
using namespace std;

void rev(string &s,int l,int r) {
    while(l<r)
        swap(s[l++], s[r--]);
}
 
int search(string &s,int l,int r,int key) {
    int index = -1;
    while(l<=r) {
        int mid = l+(r-l)/2;
        if(s[mid]<=key) {
            r=mid-1;
        } else {
            l=mid+1;
            if(index = -1 || s[index]<=s[mid])
                index = mid;
        }
    }
    return index;
}
 
bool nextpermutation(string &s) {
    int len = s.length();
    int i = len-2;
    while(i >= 0 && s[i] >= s[i+1])
       i--;
    if(i<0) {
        return false;
    } else {
        int index = search(s, i+1, len-1, s[i]);
        swap(s[i],s[index]);
        rev(s,i+1,len-1);
        return true;
    }
}
int main () {
    string s = "gfg";
    cout<<"For "<<s;
    bool val = nextpermutation(s);
    if (val == false)
        cout<<" no next permutation"<<endl;
    else
        cout<<" next permutation is "<<s<<endl;
    return 0;
}
