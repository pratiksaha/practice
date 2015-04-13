// to approximate number of people in Birthday Paradox problem
#include<iostream>
#include<cmath>
using namespace std;

int birthdayParadox(double p) {
    return ceil(sqrt(2*365*log(1/(1-p))));
}

int main() {
   cout<<"No of persons required to have 0.70 probability of 2 persons having same birthday is "<<birthdayParadox(0.70)<<endl;
}
