//to generate next terms of a given polynomial sequence
#include<bits/stdc++.h>
using namespace std;

void nextTermsInPolynomialSequence(int sequence[], int N, int terms) {
    int diff[N + terms];
    for (int i = 0; i < N; i++)
        diff[i] = sequence[i];
    bool more = false;
    vector<int> first;
    int len = N;
    while (len > 1) {
        first.push_back(diff[0]);
        len--;
        for (int i = 0; i < len; i++)
            diff[i] = diff[i + 1] - diff[i];
        int i;
        for (i = 1; i < len; i++)
            if (diff[i] != diff[i - 1])
                break;
        if (i != len)
            break;
    }
    int iteration = N - len;
    for (int i = len; i < len + terms; i++)
        diff[i] = diff[i - 1];
    len += terms;
    for (int i = 0; i < iteration; i++) {
        len++;
        for (int j = len - 1; j > 0; j--)
            diff[j] = diff[j - 1];
        diff[0] = first[first.size() - i - 1];
        for (int j = 1; j < len; j++)
            diff[j] = diff[j - 1] + diff[j];
    }
    for (int i = 0; i < len; i++)
        cout<<" "<<diff[i];
    cout<<endl;
}

int main() {
    int sequence[] = {8, 11, 16, 23};
    int N = sizeof(sequence) / sizeof(int);
    int terms = 3;
    nextTermsInPolynomialSequence(sequence, N, terms);
    return 0;
}
