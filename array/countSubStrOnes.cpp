//to count number of substrings starting and ending with 1
#include<iostream>
#include<cstring>
using namespace std;
 
int countSubStrOnes(char *str) {
    int n = strlen(str);
    int m = 0; //count of 1s
    for (int i=0; i<n; i++) {
        if (str[i] == '1')
            m++;
   }
   return m*(m-1)/2;
}

int main() {
    char str[] = "00100101";
    cout<<"No of substrings start & end with 1s: "<<countSubStrOnes(str)<<endl;
    return 0;
}
