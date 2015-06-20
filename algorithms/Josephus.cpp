//josephus problem
#include<iostream>
using namespace std;
 
int Josephus(int n, int k) {
    if (n == 1)
        return 1;
    else
        return (Josephus(n-1, k) + k-1)%n + 1;
}

int main() {
    int n = 14;
    int k = 2;
    cout<<"For n = "<<n<<" and k = "<<k<<" chosen place is : "<<Josephus(n, k)<<endl;
    return 0;
}
