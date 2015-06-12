//to print itinerary
//Using features of C++ Standard (2011) Compile using g++ -std=c++11
#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<cassert>
#include<string>
#include<unordered_map>
using namespace std;

void printItinerary(unordered_map<string, string> tickets) {
    unordered_map<string, string> reverse;
    for(unordered_map<string, string>::iterator it=tickets.begin(); it != tickets.end(); it++)
        reverse[it->second] = it->first;
    string start = "";
    for(unordered_map<string, string>::iterator it=tickets.begin(); it != tickets.end(); it++) {
        string curr = it->first;
        if (reverse.find(curr) == reverse.end()) {
            start = curr;
            break;
        }
    }
    assert(start != "");
    cout<<"Itinerary :\n";
    unordered_map<string, string>::iterator it = tickets.find(start);
    while (it!=tickets.end()) {
        cout<<it->first<<"->"<<it->second<<endl;
        it = tickets.find(it->second);
    }
}


int main () {
    unordered_map<string, string> tickets;
    tickets["Chennai"] = "Bengaluru";
    tickets["Mumbai"] = "Delhi";
    tickets["Goa"] = "Chennai";
    tickets["Delhi"] = "Goa";
    printItinerary(tickets);
    return 0;
}
