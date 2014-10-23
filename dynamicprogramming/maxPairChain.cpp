#include<iostream>
#include<cstdlib>
#include<algorithm>
using namespace std;

struct pair_str {
    int a;
    int b;
};

typedef struct pair_str Pair;

int compare(const void* x, const void* y) {//Used by qsort
    Pair *p1 = (Pair *)x;
    Pair *p2 = (Pair *)y;
    return (p1->a - p2->a);
}

void maxChainLength(Pair inp[], int n) {
    int i, j;
    int *mcl = new int[n];
 
    /*
    for(i=0; i<n; i++)
        cout<<"("<<inp[i].a<<","<<inp[i].b<<")";
    cout<<endl;
    */
    
    Pair srt[n];
    for(i=0; i<n; i++)
        srt[i] = inp[i];
    qsort(srt, n, sizeof(Pair), compare);
    
    /*
    for(i=0; i<n; i++)
        cout<<"("<<srt[i].a<<","<<srt[i].b<<")";
    cout<<endl;
    */
    
    for (i=0; i<n; i++)
        mcl[i] = 1;

    for (i=1; i<n; i++)
        for (j=0; j<i; j++)
            if ( srt[i].a>srt[j].b && mcl[i] < mcl[j] + 1)
                mcl[i] = mcl[j] + 1;
 
    int max_len = 0;
    for (i=0; i<n; i++)
        if (max_len<mcl[i])
            max_len = mcl[i];
    
    cout<<"Longest chain pair length = "<<max_len<<endl;
    delete[] mcl;
}

int main() {
    Pair arr[] = { {5, 24}, {50, 60}, {15, 25}, {27, 40} };
    maxChainLength(arr, sizeof(arr)/sizeof(arr[0]));
    return 0;
}
