//to compare two integers
#include<bits/stdc++.h>
using namespace std;
 
bool equalNumber(int a, int b){
   return !( a^b ) ;
}

int main(){
  int a = 5, b = 6; 
  cout<<a<<" & "<<b<<" are"<<(equalNumber(a, b) ? " " : " not ")<<"equal\n";
  a = 9, b = 9;
  cout<<a<<" & "<<b<<" are"<<(equalNumber(a, b) ? " " : " not ")<<"equal\n";
  return 0;
} 
