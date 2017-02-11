//to find min number from digits of given number
#include<iostream>
using namespace std;
 
int minNumberByRearrangement(int num) {
    int freq[10] = {0};
    while (num) {
        int d = num % 10;
        freq[d]++;
        num = num / 10;
    }
    int result = 0;
    for (int i = 1 ; i <= 9 ; i++) {
        if (freq[i]) {
            result = i;
            freq[i]--;
            break;
        }
    }
    for (int i = 0 ; i <= 9 ; i++)
        while (freq[i]--)
            result = result * 10 + i;
    return result;
}

int main() {
    int n = 570107;
    cout<<"min number from digits of "<<n<<" is "<<minNumberByRearrangement(n)<<endl;
    return 0;
}
