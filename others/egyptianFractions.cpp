//greedy algorithm to print egyptian fractions
#include <iostream>
using namespace std;
 
void egyptianFractions(int nr, int dr) {
    if (nr != 0 && dr != 0) {
        if (nr%dr == 0) { //given number is not fraction if dr divides nr
            cout<<nr/dr;
        } else if (dr%nr == 0) { //simple division makes the fraction in 1/n form if nr divides dr
            cout<<"1/"<<dr/nr;
        } else if (nr > dr) { //if nr > dr
            cout<<nr/dr<<" + ";
            egyptianFractions(nr%dr, dr);
        } else { //if dr>nr and dr%nr is non-zero
            int n = dr/nr + 1; //find ceiling of dr/nr and print it as first fraction
            cout<<"1/"<<n<<" + ";
            egyptianFractions(nr*n-dr, dr*n); //recur for remaining part
        }
    }    
}

int main() {
    cout<<"Egyptian Fraction Representation of 3/7 is "; egyptianFractions(3, 7); cout<<endl;
    return 0;
}
