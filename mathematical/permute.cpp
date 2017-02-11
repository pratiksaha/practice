//permute
#include <bits/stdc++.h>
using namespace std;
 
void permute(string str, string out) {
    if (str.size() == 0) {
        cout<<out<<endl;
        return;
    }
    for (int i = 0; i < str.size(); i++) {
        permute(str.substr(1), out + str[0]);
        rotate(str.begin(), str.begin() + 1, str.end());
    }
}

void permute(string str) {
    sort(str.begin(), str.end());
    do {
       cout<<str<<endl;
    } while (next_permutation(str.begin(), str.end()));
}

void previous_permutaion(string str){
    cout<<"For "<<str;
    if ( prev_permutation(str.begin(), str.end()) )
        cout<< " Previous permutation is "<<str<<endl;
    else
        cout<<"Previous permutation doesn't exist\n";
}

int main() {
    cout<<"Permutations using rotate:\n";
    permute("ABC");
    cout<<"Permutations using next_permutation:\n";
    permute("CBA");
    previous_permutaion("ABC");
    previous_permutaion("CBA");
    return 0;
}
