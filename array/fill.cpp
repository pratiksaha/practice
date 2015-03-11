//to fill two instances of all numbers from 1 to n such that no of elems between two instances of a no i is equal to i
#include<iostream>
using namespace std;

bool fillUtil(int res[], int curr, int n) {
    if (curr == 0) { //curr = 0 means all nos are filled
        return true;
    } else { //try placing two instances of curr at all possible locations till soln is found
        for (int i=0; i<2*n-curr-1; i++) {
            if (res[i] == 0 && res[i + curr + 1] == 0) { //two currs should be placed at curr+1 distance
                res[i] = res[i + curr + 1] = curr;
                if (fillUtil(res, curr-1, n)) //check for soln
                    return true;
                else //backtrack
                    res[i] = res[i + curr + 1] = 0;
            }
        }
        return false; //no soln possible
    }
}

void fill(int n) {
    int res[2*n], i;
    for (i=0; i<2*n; i++)
        res[i] = 0;
    cout<<"For input "<<n<<" : ";
    if (fillUtil(res, n, n)) {
        for (i=0; i<2*n; i++)
            cout<<res[i];
        cout<<endl;   
    } else {
        cout<<"Not Possible\n";
    }
}

int main() {
    fill(7);
    fill(5);
    return 0;
}
