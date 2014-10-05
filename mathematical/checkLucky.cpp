//Program to check lucky nos
//buggy will fix later
#include<iostream>
using namespace std;

bool isLucky(int num){
    
    int counter = 2;
    /*
    while(num >= counter){
        //cout<<counter<<" "<<num<<endl;
        if(num%counter == 0)
            return false;
        num = num - num/counter;
        counter++;
    }*/
	return true;   
}

int main(){
    int num;
    cin>>num;
    cout<<num<<(isLucky(num)?" is lucky":" is not lucky")<<endl;
    return 0;
}
