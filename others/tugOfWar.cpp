//Tug of War problem
#include<iostream>
#include<climits>
#include<cmath>
using namespace std;

void TOW(int* arr, int size, bool* curr, bool* soln, int sum, int selc_elem_no, int curr_sum, int curr_pos, int* min_diff) {
    if (curr_pos == size) //check bounds
        return;
 
    // checks that the numbers of elements left are not less than the number of elements required to form the solution
    if ((size/2 - selc_elem_no) > (size - curr_pos))
        return;
 
    // consider the cases when current element is not included in the solution
    TOW(arr, size, curr, soln, sum, selc_elem_no, curr_sum, curr_pos+1, min_diff);
 
    // add the current element to the solution
    selc_elem_no++;
    curr_sum = curr_sum + arr[curr_pos];
    curr[curr_pos] = true;
 
    // checks if a solution is formed
    if (selc_elem_no == size/2)
    {
        // checks if the solution formed is better than the best solution so far
        if (abs(sum/2 - curr_sum) < *min_diff)
        {
            *min_diff = abs(sum/2 - curr_sum);
            for (int i = 0; i<size; i++)
                soln[i] = curr[i];
        }
    }
    else
    {
        // consider the cases where current element is included in the solution
        TOW(arr, size, curr, soln, sum, selc_elem_no, curr_sum, curr_pos+1, min_diff);
    }
 
    // removes current element before returning to the caller of this function
    curr[curr_pos] = false;
}

void tugOfWar(int *arr, int size){
    bool* curr = new bool[size]; //Store inclusion/exclusion info of current set
    bool* soln = new bool[size]; //Store inclusion/exclusion info of solution set
    int min_diff = INT_MAX;
    int sum = 0;
    int i;
    for (i=0; i<size; i++) {
        sum += arr[i];
        curr[i] = false;
        soln[i] = false;
    }
    TOW(arr, size, curr, soln, sum, 0, 0, 0, &min_diff);
    cout<<"Input array :";
    for(i=0; i<size; i++)
        cout<<" "<<*(arr+i);
    cout<<endl;
    cout<<"\tFirst Subset :";
    for(i=0; i<size; i++)
        if(*(soln+i))
            cout<<" "<<*(arr+i);
    cout<<endl;
    cout<<"\tSecond Subset :";
    for(i=0; i<size; i++)
        if(!*(soln+i))
            cout<<" "<<*(arr+i);
    cout<<endl;
}

int main(){
    int a[] = {23, 45, -34, 12, 0, 98, -99, 4, 189, -1, 4};
    int b[] = {3, 4, 5, -3, 100, 1, 89, 54, 23, 20};
    tugOfWar(a, sizeof(a)/(sizeof(a[0])));
    tugOfWar(b, sizeof(b)/(sizeof(b[0])));
    return 0;
}
