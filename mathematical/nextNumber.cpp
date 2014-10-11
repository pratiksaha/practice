// C++ program to find the smallest number which greater than a given number and has same set of digits as given number
#include<iostream>
#include<algorithm>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
 
void findNext(int num[], int n)
{
    int i, j;
 
    //Start from the right most digit and find the first digit that is smaller than the digit next to it.
    for (i = n-1; i > 0; i--) {
        if (num[i] > num[i-1]) {
           break;
        }
    }
    
    // If no such digit is found, then all digits are in descending order means there cannot be a greater number with same set of digits
    if (i==0)
    {
        cout<<"Not possible";
        return;
    }
 
    //Find the smallest digit on right side of (i-1)'th digit that is greater than number[i-1]
    int x = num[i-1], smallest = i;
    for (j = i+1; j < n; j++) {
        if (num[j] > x && num[j] < num[smallest]) {
            smallest = j;
        }
    }
 
    //Swap the above found smallest digit with number[i-1]
    swap(&num[smallest], &num[i-1]);
 
    //Sort the digits after (i-1) in ascending order
    sort(num+i, num+n);
 
    cout<<"Next number with same set of digits is ";
    for(i=0; i<n; i++)
        cout<<num[i];
    cout<<endl;
}

int main()
{
    int digits[] = {5,3,4,9,7,6};
    findNext(digits, sizeof(digits)/sizeof(digits[0]));
    return 0;
}
