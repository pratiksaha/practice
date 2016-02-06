//number
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

void printArray(int *a, int n) {
    for (int i=0; i<n; i++)
        cout<<" "<<*(a+i);
}

void printSequence(int n, int k, int len, int arr[]) {
    if (k == 0) {
        cout<<" {";
        printArray(arr, len);
        cout<<" }";
    } else if (k > 0) {
        for(int i=1; i<=n; i++) {
            arr[len] = i;
            printSequence(n, k-1, len+1, arr);
        }
    }
}

void printSequence(int n, int k) {
    int arr[k];
    cout<<"Sequences of size "<<k<<" till "<<n<<" :";
    printSequence(n, k, 0, arr);
    cout<<endl;
}

void printIncreasingSequence(int n, int k, int &len, int arr[]) {
    if (len == k) {
        cout<<" {";
        printArray(arr, k);
        cout<<" }";
    } else {
        int i = (len == 0)? 1 : arr[len-1] + 1;
        len++;
        while (i<=n) {
            arr[len-1] = i;
            printIncreasingSequence(n, k, len, arr);
            i++;
        }
        len--;
    }
}

void printIncreasingSequence(int n, int k) {
    int arr[k];
    int len = 0;
    cout<<"Increasing Sequences of size "<<k<<" till "<<n<<" :";
    printIncreasingSequence(n, k, len, arr);
    cout<<endl;
}

int reverse(int n) { //reverse n
    int rn = 0;
    bool neg = false;
    if (n<0) {
        neg = true;
        n = -n;
    }
    while(n>0) {
        rn = rn*10 + n%10;
        n = n/10;
    }
    if (neg)
        return -rn;
    else
        return rn;
}

bool checkPalindrome(int n) { //check n is palindrome
    int rn = reverse(n);
    return (rn == n);
}

int oneDigit(int n){ //check if n is only of one digit
    return (n>=0 && n<10);
}

bool isPalindrome(int num, int *dup) {
    if (oneDigit(num))
        return (num == (*dup) % 10);
    if (!isPalindrome(num/10, dup))
        return false;
    *dup = *dup/10;
    return (num%10 == (*dup)%10);
}

bool isPalindrome(int n) { //check if a number is palindrome
    if (n<0)
        n = -n;
    int dup = n;
    int rn = isPalindrome(n, &dup);
}

void squares(int n) { //squares of all nos till n
    cout<<"Squares :";
    int square = 0, prev = 0;
    for (int i=0; i<=n; i++) {
        square = square + i + prev;
        cout<<" "<<i<<"->"<<square;
        prev = i;
    }
    cout<<endl;
}

string all1mulofend3(int n) { //find the least multiple with all 1s for a n ending with 3
    int count=1, rem=1;
    while (rem) {
        rem= (rem*10+1)%n;
        count++;
    }
    string res = "";
    while (count--)
        res.push_back('1');
    return res;
}

int gcd(int a,int b) {
    if (b==0)
        return a;
    return gcd(b,a%b);
}

void smallestAxBy(int a, int b) { //smallest values of x and y that satisfy ax=by
    int g = gcd(a, b);
    int lcm = (a*b)/g;
    cout<<"x = "<<lcm/a<<" y = "<<lcm/b<<endl;
    cout<<"x = "<<b/g<<" y = "<<a/g<<endl;
}

int main() {
    int m = 5, k = 3;
    printSequence(m, k);
    printIncreasingSequence(m, k);
    int a = 23985, b = 43534;
    cout<<"No = "<<a<<endl;
    cout<<"Reversed No "<<reverse(a)<<endl;
    cout<<a<<(checkPalindrome(a)?" is palindrome":" is not palindrome")<<endl;
    cout<<b<<(checkPalindrome(b)?" is palindrome":" is not palindrome")<<endl;
    cout<<a<<(isPalindrome(a)?" is palindrome":" is not palindrome")<<endl;
    cout<<b<<(isPalindrome(b)?" is palindrome":" is not palindrome")<<endl;
    int n = 43;
    squares(n);
    cout<<"Least multiple with all 1s for "<<n<<" : "<<all1mulofend3(n)<<endl;
    int p = 25, q = 35;
    smallestAxBy(p,q);
    return 0;
}
