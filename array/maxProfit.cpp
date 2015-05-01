//to find maximum possible profit with at most two transactions
#include<iostream>
using namespace std;

int maxProfit(int price[], int n) {
    int profit[n];
    for (int i=0; i<n; i++)
        profit[i] = 0;
    int max_price = price[n-1]; //max_price has max of price[i..n-1]
    for (int i=n-2;i>=0;i--) {
        if (price[i] > max_price)
            max_price = price[i];
        profit[i] = max(profit[i+1], max_price-price[i]); //max of previous max profit & profit by buying at price[i] and selling at max_price
    }
    int min_price = price[0]; // min_price is min price in price[0..i]
    for (int i=1; i<n; i++) {
        if (price[i] < min_price)
            min_price = price[i];
        profit[i] = max(profit[i-1], profit[i] + (price[i]-min_price)); //max of previous max profit & profit by buy at min_price & sell at price[i] and profit of other trans
    }
    return profit[n-1];
}

int main() {
    int price[] = {2, 30, 15, 10, 8, 25, 80};
    int n = sizeof(price)/sizeof(price[0]);
    cout<<"Maximum Profit = "<<maxProfit(price,sizeof(price)/sizeof(price[0]))<<endl;
    return 0;
}
