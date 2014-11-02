#include<iostream>
using namespace std;

void getOddOccurrence(int arr[], int size) {
    int i;
    int res = 0;
    for (i=0; i<size; i++)    
        res = res^arr[i];
    //after xor ing all nos the result is the no occuring odd no of times    
    cout<<"No occuring odd no of time is "<<res<<endl;
}

void get2NonRepeatingNos(int arr[], int size) {
    int res = 0; 
    int set_bit_no;
    int i;
    int x =0;
    int y = 0;

    for(i = 0; i < size; i++)
        res ^= arr[i];//res contains the xor of all elements
 
    set_bit_no = res & ~(res-1);//get the righrmost setbit in the xor of all elements
     
    for(i = 0; i < size; i++)
    {
        if(arr[i] & set_bit_no)
            x = x ^ arr[i]; //XOR of first set 
        else
            y = y ^ arr[i]; //XOR of second set
    }
    cout<<"The two ODD elements are "<<x<<" & "<<y<<endl;
}

void getTwoElements(int arr[], int n) {
    int res = 0; 
    int set_bit_no;
    int i;
    int x =0;
    int y = 0;

    for (i=0; i<n; i++)
        res = res^arr[i];//res contains the xor of all elements

    for (i=1; i<=n; i++)//XOR the previous result with numbers from 1 to n
        res = res^i;
        
    set_bit_no = res & ~(res-1);//get the righrmost setbit in the xor of all elements

    for (i = 0; i < n; i++) {
        if(arr[i] & set_bit_no)
            x = x ^ arr[i]; // arr[i] belongs to first set
        else
            y = y ^ arr[i]; // arr[i] belongs to second set
    }
    for (i = 1; i <= n; i++) {
        if(i & set_bit_no)
            x = x ^ i; // i belongs to first set
        else
            y = y ^ i; // i belongs to second set
    }
    cout<<"The two elements are "<<x<<" & "<<y<<endl;
}
 

int main(){
    int a[] = {2, 3, 5, 4, 5, 2, 4, 3, 5, 2, 4, 4, 2};
    int b[] = {2, 3, 7, 9, 11, 2, 3, 11};
    int c[] = {1, 3, 4, 5, 5, 7, 2};
    getOddOccurrence(a, sizeof(a)/sizeof(a[0]));
    get2NonRepeatingNos(b, sizeof(b)/sizeof(b[0]));
    getTwoElements(c, sizeof(c)/sizeof(c[0]));
    return 0;
}
