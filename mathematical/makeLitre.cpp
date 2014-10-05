//Given two vessels measure one litre of water
 
#include <iostream>
using namespace std;
 
int gcd(int a, int b) 
{ 
    return b? gcd(b,a%b) : a;
}
 

struct vessel
{
    // A vessel has capacity, and current amount of water in it
    int capacity; 
    int current = 0; //initially vessels are empty
};

int transfer(int amount, struct vessel *v)
{
    // If the vessel can accommodate the given amount
    if ( (v->current+amount)<(v->capacity) )
    {
        v->current += amount;
        return amount;
    } 
    // If the vessel cannot accommodate the given amount, then store the amount of water transferred
    int transferred = (v->capacity)-(v->current); 
    // Since the vessel becomes full, make the vessel empty so that it can be filled again
    v->current = 0; 
    return transferred;
}    

void  makeOneLitre(struct vessel *v1, struct vessel *v2)
{
    // solution exists iff a and b are co-prime
    if (gcd(v1->capacity, v2->capacity) != 1)
        return; 
    while (v1->current != 1)
    {
        // fill A (smaller vessel)
        if (v1->current == 0)
            v1->current = v1->capacity;
        cout<<"Vessel1: " <<v1->current<< " Vessel2: "<<v2->current<<endl; 
        // Transfer water from V1 to V2 and reduce current of V1 by the amount equal to transferred water
        v1->current = v1->current-transfer(v1->current, v2);
    } 
    // Finally, there will be 1 litre in vessel 1
    cout<< "Vessel1: "<<v1->current<<" Vessel2: "<<v2->current<<endl;
}
 



int main()
{
    struct vessel v1, v2;
    v1.capacity = 3;
    v2.capacity = 7;
    makeOneLitre(&v1, &v2); 
    return 0;
}
