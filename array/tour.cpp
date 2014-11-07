//find circular tour for a truck
#include<iostream>
using namespace std;

typedef struct {
  int petrol, distance;
}petrolPump;

int tour(petrolPump arr[], int n) {
    int start = 0;
    int end =  1;
    int curr_petrol = arr[start].petrol - arr[start].distance;

    while (end != start || curr_petrol < 0) {//while all pumps are not visited & we have reached first pump again with 0 or more petrol
        while (curr_petrol < 0 && start != end) {// If curr petrol in truck becomes less than 0 remove the starting pump from tour
            curr_petrol -= arr[start].petrol - arr[start].distance;
            start = (start + 1)%n;
            if (start == 0) //if 0 is being considered as start again, then there is no possible solution
               return -1;
        }   
        curr_petrol += arr[end].petrol - arr[end].distance;
        end = (end + 1)%n;
    }
    return start;
}

int main() {
    petrolPump arr[] = {{6, 4}, {3, 6}, {7, 3}};
    int res = tour(arr, sizeof(arr)/sizeof(arr[0]));
    (res == -1)?(cout<<"No solution\n"):(cout<<"Start = "<<res<<endl);
    return 0;
}
