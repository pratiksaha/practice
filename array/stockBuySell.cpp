//find best buying and selling days given prices of stock over a period
#include<iostream>
using namespace std;

typedef struct {
    int buy;
    int sell;
}Interval;

void stockBuySell(int price[], int n) {
    if(n <= 1) // Prices must be given for at least two days
        return;
 
    int count = 0;
    Interval sol[n/2 + 1];
    
    int i = 0;
    while (i<n-1) { 
        while ((i < n-1) && (price[i+1] <= price[i])) //find local minima
            i++;
        
        if (i == n-1) //no further sols possible
            break;  
        sol[count].buy = i;
        
        i++;

        while ((i < n) && (price[i] >= price[i-1])) //find local maxima
            i++;
        sol[count].sell = i-1;
        count++;
    }

    if (count == 0) {
        cout<<"There is no day when buying the stock will make profit\n";
    } else {
       for(i=0; i<count; i++)
          cout<<"Buy on day: "<<sol[i].buy<<" Sell on day: "<<sol[i].sell<<endl;
    }
}

int main() {
    int price[] = {100, 180, 260, 310, 40, 535, 695};
    stockBuySell(price, sizeof(price)/sizeof(price[0]));
    return 0;
}
