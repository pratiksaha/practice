//Program to add in base 14
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cassert>
using namespace std;
 
int getNumeralValue(char num)
{
    if( num >= '0' && num <= '9')
        return (num - '0');
    if( num >= 'A' && num <= 'D')  
        return (num - 'A' + 10);
    assert(0);// If we reach this line caller is giving invalid character so we assert and fail
}
 
char getNumeral(int val)
{
    if( val >= 0 && val <= 9)
        return (val + '0');
    if( val >= 10 && val <= 14)  
        return (val + 'A' - 10);
    assert(0);// If we reach this line caller is giving invalid no. so we assert and fail
}
 
char *sumBase14(char *num1,  char *num2)
{
    int l1 = strlen(num1);
    int l2 = strlen(num2);
    
    int max = (l1>l2)?l1:l2;
    int carry = 0;
    
    char *t1 = new char[max+1];
    char *t2 = new char[max+1];
    char *res = new char[max+2]; 
    //cout<<l1<<" "<<l2<<" "<<max<<endl;
    int i, nml1, nml2, res_nml;
    i=l1;
    
    //below logic is to pad with zeroes in case of unequal lengths
    while(i<max){
        //cout<<"while1 "<<i<<" "<<max-i-1<<endl;
        *(t1+max-i-1) = '0';
        i++;
    }
    i=l2;
    while(i<max){
        //cout<<"while2 "<<i<<" "<<max-i-1<<endl;
        *(t2+max-i-1) = '0';
        i++;
    }
    for(i=0; i<l1; i++){
        //cout<<"for1 "<<i<<" "<<i+max-l1<<endl;
        *(t1+i+max-l1) = *(num1+i);
    }
    for(i=0; i<l2; i++){
        //cout<<"for2 "<<i<<" "<<i+max-l2<<endl;
        *(t2+i+max-l2) = *(num2+i);
    }
    i = max;
    *(t1+i) = '\0';
    *(t2+i) = '\0';
    //cout<<t1<<endl;
    //cout<<t2<<endl;
    
    for(i = max-1; i >= 0; i--) {    
        nml1 = getNumeralValue(t1[i]);
        nml2 = getNumeralValue(t2[i]);
        res_nml = carry + nml1 + nml2;
        if(res_nml >= 14) {
            carry = 1;
            res_nml -= 14;
        } else {
            carry = 0;     
        }     
        res[i+1] = getNumeral(res_nml);
    }
    delete[] t1;
    delete[] t2;
    if(carry == 0)
        return (res + 1);   
    res[0] = '1';
    
    return res;
}

int main()
{
    char *num1 = "DC2";
    char *num2 = "A3";
    cout<<"Result is "<<sumBase14(num1, num2)<<endl;        
    return 0;
}
