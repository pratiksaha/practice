//generate n binary nos
#include<iostream>
#include<queue>
#include<string>
using namespace std;

void generateBinary(int n) {
    queue<string> q;
    q.push("1");
    cout<<n<<" binary nos :";
    while (n--) {
        string s1 = q.front();
        q.pop();
        cout<<" "<<s1;
        string s2 = s1;
        q.push(s1.append("0")); //append 0 and enqueue
        q.push(s2.append("1")); //append 1 and enqueue
    }
    cout<<endl;
}

int main() {
    generateBinary(7);
    generateBinary(10);
    generateBinary(15);
    return 0;
}
