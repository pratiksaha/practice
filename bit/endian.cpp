#include<iostream>
#include<cstdio>
using namespace std;

void checkEndian(){
    unsigned int i = 1;
    char *c = (char*)&i;
    if (*c)   
       cout<<"Little Endian"<<endl;
    else
       cout<<"Big Endian"<<endl;
}

void show_mem_rep(char *start, int n)
{
    int i;
    for (i = 0; i < n; i++)
         printf(" %.2x", start[i]);
    printf("\n");
}

int main(){
    checkEndian();
    int a = 0x01234567;
    show_mem_rep((char *)&a, sizeof(a));
    return 0;
}
