//generate probabilities
#include<iostream>
#include<ctime>
#include<cstdlib>
#include<cassert>
using namespace std;

int findCeil(int *a, int key, int l, int h) { //find ceiling of key in sorted array a b/w l and h
    while (l<h) {
        int mid = (l+h)/2;
        if (key>a[mid])
            l = mid+1;
        else 
            h = mid;
    }
    return (a[l]>=key) ? l : -1;
}

int randomFrequency(int *arr, int *freq, int n) { //generate random nos from arr according to freq
    int prefix[n]; //sum of all freq's till i
    prefix[0] = freq[0];
    for (int i=1; i<n; i++)
        prefix[i] = prefix[i-1] + freq[i];
    int r = (rand() % prefix[n-1]) + 1; //generate a random number with value from 1 to prefix[n-1]
    int idx = findCeil(prefix, r, 0, n-1);
    assert(idx != -1);
    return arr[idx];
}

int randomProbablity(int x, int y, int z, int px, int py, int pz) { //generate one of x,y,z with probability px,py,pz       
        int r = (rand() % 100) + 1;
        if (r <= px) //r < px with probability px/100
            return x; 
        else if (r <= (px+py)) //px < r <= px+py with probability py/100
            return y;
        else //px+py < r <= 100 with probability pz/100
            return z;
}

int random1to5() { //generate a no b/w 1 and 5 randomly
   return ((rand() % 5) + 1);
}

int rand1to7using1to5() { //returns 1 to 7 with equal probability using random1to5
    int i = 5*random1to5() + random1to5() - 5;
    if (i < 22)
        return i%7 + 1;
    return rand1to7using1to5();
}

int biasedCoin() { //mimic a biased that geneartes tail(0) 60% and head(1) 40% of the time 
    int r = (rand() % 100) + 1;;
    if (r<= 60)
        return 0;
    else
        return 1;
}

int unbiasedCoinFromBiasedCoin() { //make a fair coin using biasedCoin
    int val1 = biasedCoin();
    int val2 = biasedCoin();
    if (val1 == 0 && val2 == 1)
        return 0; //will reach here with 0.24 probability
    if (val1 == 1 && val2 == 0)
        return 1; //will reach here with 0.24 probability
    return unbiasedCoinFromBiasedCoin();
} 

int main() {
    srand (time(NULL));
    int arr[]  = {1, 2, 3, 4};
    int freq[] = {10, 5, 20, 100};
    int n = sizeof(arr)/sizeof(arr[0]);
    int N = 100;
    int x = 1, y = 2, z = 3, px = 40, py = 25, pz = 35;  
    cout<<"Generating nos from {";
    for (int i=0; i<n; i++)
        cout<<" "<<arr[i];
    cout<<" } acc to freq {";
    for (int i=0; i<n; i++)
        cout<<" "<<freq[i];
    cout<<" } :";
    for (int i=0; i<N; i++)
        cout<<" "<<randomFrequency(arr, freq, n);
    cout<<endl;
    cout<<"Generating "<<x<<" "<<y<<" "<<z<<" with prob "<<px<<" "<<py<<" "<<pz<<" :";
    for (int i=0; i<N; i++)
        cout<<" "<<randomProbablity(x, y, z, px, py, px);
    cout<<endl;
    cout<<"Generating nos from 1 to 7 using a random function for 1 to 5 :";
    for (int i=0; i<N; i++)
        cout<<" "<<rand1to7using1to5();
    cout<<endl;
    cout<<"Tossing a biased coin with head = 0.4 and tail = 0.6 in an unbiased manner :";
    for (int i=0; i<N; i++)
        cout<<" "<<unbiasedCoinFromBiasedCoin();
    cout<<endl;
    return 0;
}
