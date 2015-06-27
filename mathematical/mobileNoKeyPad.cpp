//Find no of possible numbers for given length and all possible chars for given nos
#include<iostream>
#include<cstring>
using namespace std;

char keypad[4][3]= {{'1','2','3'},
                    {'4','5','6'},
                    {'7','8','9'},
                    {'*','0','#'}};
char hashTable[10][5] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void  printWords(int number[], char result[], int curr, int n) {
    if (curr == n) {
        cout<<" "<<result;
    } else { //try all 3 possibilities and recur
        for (int i=0; i<strlen(hashTable[number[curr]]); i++) {
            result[curr] = hashTable[number[curr]][i];
            printWords(number, result, curr+1, n);
            if (number[curr]==0 || number[curr]==1)
                return;
        }
    }
}

void printWords(int number[], int n) {
    cout<<"All possible words with \"";
    for (int i=0; i<n; i++)
        cout<<number[i];
    cout<<"\" are :";
    char result[n+1];
    result[n] ='\0';
    printWords(number, result, 0, n);
    cout<<endl;
}

int getCount(int n) {
    if(n <= 0)
        return 0;
    if(n == 1)
        return 10;

    int odd[10], even[10];
    int i = 0, j = 0, useOdd = 0;
 
    for (i=0; i<=9; i++) //for j = 1
        odd[i] = 1;  
 
    for (j=2; j<=n; j++) { //for j = 2..n
        useOdd = 1 - useOdd;

        if(useOdd == 1) {
            even[0] = odd[0] + odd[8];
            even[1] = odd[1] + odd[2] + odd[4];
            even[2] = odd[2] + odd[1] + odd[3] + odd[5];
            even[3] = odd[3] + odd[2] + odd[6];
            even[4] = odd[4] + odd[1] + odd[5] + odd[7];
            even[5] = odd[5] + odd[2] + odd[4] + odd[8] + odd[6];
            even[6] = odd[6] + odd[3] + odd[5] + odd[9];
            even[7] = odd[7] + odd[4] + odd[8];
            even[8] = odd[8] + odd[0] + odd[5] + odd[7] + odd[9];
            even[9] = odd[9] + odd[6] + odd[8];
        } else {
            odd[0] = even[0] + even[8];
            odd[1] = even[1] + even[2] + even[4];
            odd[2] = even[2] + even[1] + even[3] + even[5];
            odd[3] = even[3] + even[2] + even[6];
            odd[4] = even[4] + even[1] + even[5] + even[7];
            odd[5] = even[5] + even[2] + even[4] + even[8] + even[6];
            odd[6] = even[6] + even[3] + even[5] + even[9];
            odd[7] = even[7] + even[4] + even[8];
            odd[8] = even[8] + even[0] + even[5] + even[7] + even[9];
            odd[9] = even[9] + even[6] + even[8];
        }
    }

    int totalCount = 0;
    if(useOdd == 1) {
        for (i=0; i<=9; i++)
            totalCount += even[i];
    } else {
        for (i=0; i<=9; i++)
            totalCount += odd[i];
    }
    return totalCount;
}

int main() {
    cout<<"Count for numbers of length 1 : "<<getCount(1)<<endl;
    cout<<"Count for numbers of length 2 : "<<getCount(2)<<endl;
    cout<<"Count for numbers of length 3 : "<<getCount(3)<<endl;
    cout<<"Count for numbers of length 4 : "<<getCount(4)<<endl;
    cout<<"Count for numbers of length 5 : "<<getCount(5)<<endl;
    cout<<"Count for numbers of length 6 : "<<getCount(6)<<endl;
    cout<<"Count for numbers of length 7 : "<<getCount(7)<<endl;
    cout<<"Count for numbers of length 8 : "<<getCount(8)<<endl;
    cout<<"Count for numbers of length 9 : "<<getCount(9)<<endl;
    cout<<"Count for numbers of length 10 : "<<getCount(10)<<endl;
    int number[] = {2, 3, 4};
    printWords(number, sizeof(number)/sizeof(number[0]));
    return 0;
}
