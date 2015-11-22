//to find maximum occurring digit
#include <iostream>
using namespace std;

int countOccurrences(long int x, int d) {
    int count = 0;
    while (x) {
        if (x%10 == d)
            count++;
        x = x/10;
    }
    return count;
}

int maxOccurring(long int x) {
   if (x < 0)
      x = -x;
   int result = 0;
   int max_count = 1;
   for (int d=0; d<=9; d++) {
        int count = countOccurrences(x, d);
        if (count >= max_count) {
            max_count = count;
            result = d;
        }
    }
    return result;
}

int main() {
    long int x = 1223355;
    cout<<"Max occurring digit in "<<x<<" is "<<maxOccurring(x)<<endl;
    return 0;
}
