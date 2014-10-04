#include<iostream>
using namespace std;

struct ret_pair{
    int first;
    int second;
};

int getOddOccurrence(int arr[], int size)
{
    int i;
    int res = 0;
    for (i=0; i<size; i++)    
        res = res^arr[i];
    //after xor ing all nos the result is the no occuring odd no of times    
    return res;
}

struct ret_pair get2NonRepeatingNos(int arr[], int size)
{
    int res = 0; 
    int set_bit_no;
    int i;
    struct ret_pair rep;
    rep.first =0;
    rep.second = 0;

    for(i = 0; i < size; i++)
        res ^= arr[i];//res contains the xor of all elements
 
    set_bit_no = res & ~(res-1);//get the righrmost setbit in the xor of all elements
     
    for(i = 0; i < size; i++)
    {
        if(arr[i] & set_bit_no)
            rep.first = rep.first ^ arr[i]; //XOR of first set 
        else
            rep.second = rep.second ^ arr[i]; //XOR of second set
    }
    return rep;
}

int main(){
    int a[] = {2, 3, 5, 4, 5, 2, 4, 3, 5, 2, 4, 4, 2};
    int b[] = {2, 3, 7, 9, 11, 2, 3, 11};
    cout<<"No occuring odd no of time is "<<getOddOccurrence(a, sizeof(a)/sizeof(a[0]))<<endl;
    struct ret_pair ret = get2NonRepeatingNos(b, sizeof(b)/sizeof(b[0]));
    cout<<"Two non repeating nos are "<<ret.first<<" and "<<ret.second<<endl;
    return 0;
}
