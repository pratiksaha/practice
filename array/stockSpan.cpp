//to calculate stock span values where we have a series of n daily price quotes for a stock and we need to calculate span of stock’s price for all n days. 
//The span Si of the stock’s price on a given day i is defined as the maximum number of consecutive days just before the given day for which the price of the stock on the current day is less than or equal to its price on the given day
#include<iostream>
#include<stack>
using namespace std;
 
// A brute force method to calculate stock span values
void stockSpan(int *in, int *out, int n) {
    stack<int> st;
    st.push(0);
    out[0] = 1; //span value of first element is always 1
    for (int i=1; i<n; i++) {
        while (!st.empty() && in[st.top()] < in[i]) //pop while stack is not empty and top is smaller than in[i]
            st.pop(); 
        out[i] = (st.empty())? (i + 1) : (i - st.top()); //in[i] is greater than all elems on left of it if stack becomes empty else in[i] is greater than elems after top
        st.push(i); //push this elem to stack
    }
}

void printArray(int arr[], int n) {
    for (int i=0; i<n; i++)
        cout<<" "<<arr[i];
}

int main() {
    int price[] = {10, 4, 5, 90, 120, 80};
    int n = sizeof(price)/sizeof(price[0]);
    int span[n];
    stockSpan(price, span, n);
    cout<<"For :"; printArray(price, n); cout<<" Stock Span is :";printArray(span, n);cout<<endl;
    return 0;
}
