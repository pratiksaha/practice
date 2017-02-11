//to print even length binary sequences whose sum of first and second half bits is same
#include<bits/stdc++.h>
using namespace std;

void evenLengthBInarySequenceWithSameBitsInBothHalves(int diff, char* out, int start, int end) {
    if (abs(diff) > (end - start + 1) / 2)
        return;
    if (start > end) {
        if (diff == 0)
            cout<<" "<<out;
        return;
    }
    out[start] = '0', out[end] = '1';
    evenLengthBInarySequenceWithSameBitsInBothHalves(diff + 1, out, start + 1, end - 1);
    out[start] = out[end] = '1';
    evenLengthBInarySequenceWithSameBitsInBothHalves(diff, out, start + 1, end - 1);
    out[start] = out[end] = '0';
    evenLengthBInarySequenceWithSameBitsInBothHalves(diff, out, start + 1, end - 1);
    out[start] = '1', out[end] = '0';
    evenLengthBInarySequenceWithSameBitsInBothHalves(diff - 1, out, start + 1, end - 1);
}
 
int main() {
    int n = 2;
    char out[2 * n + 1];
    out[2 * n] = '\0';
    cout<<"binary sequences whose sum of first and second half bits is same of length "<<2*n<<" are :";
    evenLengthBInarySequenceWithSameBitsInBothHalves(0, out, 0, 2*n - 1);
    cout<<endl;
    return 0;
}
