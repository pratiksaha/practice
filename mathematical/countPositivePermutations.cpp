// count of permutations that produce positive result
#include<bits/stdc++.h>
using namespace std;

int countPositivePermutations(int number[], int n) {
    sort(number, number+n);
    int count = 0;
    do {
        int curr_result = number[0] + number[1];
        int operation = 1;
        for (int i=2; i<n; i++) {
            switch (operation) {
                case 0:
                    curr_result += number[i];
                    break;
                case 1:
                    curr_result -= number[i];
                    break;
                case 2:
                    curr_result *= number[i];
                    break;
            }
            operation = (operation + 1) % 3;
        }
        if (curr_result > 0)
            count++;
    } while(next_permutation(number, number+n));
    return count;
}
 
int main() {
    int number[] = {1, 2, 3};
    int n = sizeof(number)/sizeof(number[0]);
    cout<<countPositivePermutations(number, n)<<endl;
    return 0;
}
