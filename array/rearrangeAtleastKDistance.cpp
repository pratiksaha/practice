//to rearrange a string so that all same chars become atleast d distance away
#include<bits/stdc++.h>
#define MAX_CHAR 256
using namespace std;
 
int nextChar(int freq[], int dist[]) {
    int max = INT_MIN;
    for (int i = 0; i < MAX_CHAR; i++)
        if (dist[i] <= 0 && freq[i] > 0 && (max == INT_MIN || freq[i] > freq[max]))
            max = i;
    return max;
}

int rearrangeAtleastKDistance(char str[], char out[], int d) {
    int n = strlen(str);
    int freq[MAX_CHAR] = { 0 };
    for (int i = 0; i < n; i++)
        freq[str[i]]++;
    int dist[MAX_CHAR] = { 0 };
    for (int i = 0; i < n; i++) {
        int j = nextChar(freq, dist);
        if (j == INT_MIN)
            return 0;
        out[i] = j;
        freq[j]--;
        dist[j] = d;
        for (int i = 0; i < MAX_CHAR; i++)
            dist[i]--;
    }
    out[n] = '\0';
    return 1;
}

int main() {
    char str[] = "aaaabbbcc";
    int n = strlen(str);
    char out[n];
    cout<<str<<" ";
    if (rearrangeAtleastKDistance(str, out, 2))
        cout<<out;
    else
        cout<<"cannot be rearranged";
    cout<<endl;
    return 0;
}
