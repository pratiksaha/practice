//to print all distinct permutations of a given string
#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<cstring>
using namespace std;

void distinctPermutations(char *str, int l, int r) {
    if (l == r) {
        cout<<" "<<str;
    } else {
        for (int i=l; i<=r; i++) {
            if (i!=l && str[i]==str[l])
                continue;
            swap(*(str+l), *(str+i));
            distinctPermutations(str, l+1, r);
            swap(*(str+l), *(str+i));
        }
    }
}

void distinctPermutations(char str[]) {
    int n = strlen(str);
    sort(str, str+n);
    distinctPermutations(str, 0, n-1);
    cout<<endl;
}

int main() {
    char str[] = "ABCA";
    distinctPermutations(str);
    return 0;
}
