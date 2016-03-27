//programs related to containing zero
#include<bits/stdc++.h>
using namespace std;

int toInt(char c) {
    return int(c)-48;
}

int countWithDZero(int d) { //count of nos with d digits that contain atleast one zero
    return 9*(pow(10,d-1) - pow(9,d-1));
}

int countUptoDZero(int d) { //count of nos upto d digits that contain atleast one zero
    return 9*((pow(10,d)-1)/9 - (pow(9,d)-1)/8);
}

int countNosWithZero(string num) {
    int k = num.length();
    int total = countUptoDZero(k-1);
    int non_zero = 0;
    for (int i=0; i<k; i++) {
        if (num[i] == '0') {
            non_zero--;
            break;
        }
        non_zero += (toInt(num[i])-1) * (pow(9,k-1-i));
    }
 
    int no = 0, remaining = 0,calculatedUpto=0;
    for (int i=0; i<k; i++) {
        no = no*10 + (toInt(num[i]));
        if (i != 0)
            calculatedUpto = calculatedUpto*10 + 9;
    }
    remaining = no-calculatedUpto;
    return countUptoDZero(k-1) + (remaining-non_zero-1);
}

int main() {
    int d = 1;
    cout<<"Count of nos with "<<d<<"digits that contain atleast one zero is "<<countWithDZero(d)<<endl;
    cout<<"Count of nos upto "<<d<<"digits that contain atleast one zero is "<<countUptoDZero(d)<<endl;
    d = 2;
    cout<<"Count of nos with "<<d<<"digits that contain atleast one zero is "<<countWithDZero(d)<<endl;
    cout<<"Count of nos upto "<<d<<"digits that contain atleast one zero is "<<countUptoDZero(d)<<endl;
    d = 4;
    cout<<"Count of nos with "<<d<<"digits that contain atleast one zero is "<<countWithDZero(d)<<endl;
    cout<<"Count of nos upto "<<d<<"digits that contain atleast one zero is "<<countUptoDZero(d)<<endl;
    string num = "107";
    cout<< "Count of numbers from 1"<<" to "<<num<<" having zero as a digit is "<<countNosWithZero(num)<<endl;
    num = "1264";
    cout<< "Count of numbers from 1"<<" to "<<num<<" having zero as a digit is "<<countNosWithZero(num)<<endl;
    return 0;
}
