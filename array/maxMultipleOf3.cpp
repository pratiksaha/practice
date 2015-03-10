//to find the largest multiple of 3 possible from an array
#include<iostream>
#include<cstdlib>
#include<queue>
using namespace std;

void printArray(int* arr, int n) {
    for (int i=0; i<n; i++)
        cout<<" "<<arr[i];
}

int compareAsc( const void* a, const void* b ) {
    return *(int*)a > *(int*)b;
}

int compareDesc( const void* a, const void* b ) {
    return *(int*)a < *(int*)b;
}

void populateAux(int* aux, queue<int> q0, queue<int> q1, queue<int> q2, int* top ) {
    while ( !q0.empty() ) {
        aux[(*top)++] = q0.front();
        q0.pop();
    }
    while ( !q1.empty() ) {
        aux[(*top)++] = q1.front();
        q1.pop();
    }
    while ( !q2.empty() ) {
        aux[(*top)++] = q2.front();
        q2.pop();
    }
}

bool maxMultipleOf3( int* arr, int n) {
    qsort(arr, n, sizeof(int), compareAsc); //sort in increasing order
    queue<int> q0, q1, q2; //3 queues to store nos with remainder 0, 1 & 2
    int i, sum;
    for (i=0, sum=0; i<n; i++) { //get the sum of nos and place them in corresponding queues
        sum += arr[i];
        if ((arr[i]%3) == 0)
            q0.push(arr[i]);
        else if ((arr[i]%3) == 1)
            q1.push(arr[i]);
        else
            q2.push(arr[i]);
    }
    if ((sum%3) == 1) { //sum produces remainder 1
        if (!q1.empty()) { // either remove one item from q1
            q1.pop();
        } else { // or remove two items from queue2
            if (!q2.empty())
                q2.pop();
            else
                return false;
            if (!q2.empty())
                q2.pop();
            else
                return false;
        }
    } else if ((sum % 3) == 2) { //sum produces remainder 2
        if (!q2.empty()) { // either remove one item from q2
            q2.pop();
        } else { // or remove two items from queue1
            if (!q1.empty())
                q1.pop();
            else
                return false;
            if (!q1.empty())
                q1.pop();
            else
                return false;
        }
    }
    int aux[n], top = 0;
    populateAux(aux, q0, q1, q2, &top); //empty all the queues into an auxiliary array.
    qsort (aux, top, sizeof(int), compareDesc); //sort in decreasing order
    printArray(aux, top);
    return top;
}

int main() {
    int n;
    int a1[] = {8, 1, 7, 6, 0};
    int a2[] = {2, 2};
    n = sizeof(a1)/sizeof(a1[0]);
    cout<<"Max multiple of 3 formed by {"; 
    printArray(a1, n); cout<<" } is";
    cout<<(maxMultipleOf3(a1, n)?"":" Not Possible")<<endl;
    n = sizeof(a2)/sizeof(a2[0]);
    cout<<"Max multiple of 3 formed by {"; 
    printArray(a2, n); cout<<" } is";
    cout<<(maxMultipleOf3(a2, n)?"":" Not Possible")<<endl;
    return 0;
}
