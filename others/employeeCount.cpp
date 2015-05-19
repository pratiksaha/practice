//to find the reporting chain of a employee
//Using features of C++ Standard (2011) Compile using g++ -std=c++11
#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

unordered_map<string, vector<string>> employeeCount(unordered_map<string, string> emp_mgr) {
    unordered_map<string, vector<string>> mgr_emp;
    for (unordered_map<string, string>::iterator it = emp_mgr.begin(); it != emp_mgr.end(); it++) {
        string emp = it->first;
        string mgr = it->second;
        if (emp.compare(mgr) != 0) {
            vector<string> emp_list;
            unordered_map<string, vector<string>>:: iterator ti;
            ti = mgr_emp.find(mgr);
            if (ti != mgr_emp.end())
                emp_list.assign(ti->second.begin(), ti->second.end());
            emp_list.push_back(emp);
            mgr_emp[mgr] = emp_list;
        }
    }
    return mgr_emp;
}

int main() {
    unordered_map<string, string> inData;
    inData.insert(make_pair("A", "C"));
    inData.insert(make_pair("B", "C"));
    inData.insert(make_pair("C", "F"));
    inData.insert(make_pair("D", "E"));
    inData.insert(make_pair("E", "F"));
    inData.insert(make_pair("F", "F"));
    cout<<"Emp-----Mgr:\n";
    for (unordered_map<string, string>::iterator it = inData.begin(); it != inData.end(); it++) {
        cout<<it->first<<"----------"<<it->second<<endl;
    }
    unordered_map<string, vector<string>> outData = employeeCount(inData);
    cout<<"Employees with reportings\n";
    for (unordered_map<string, vector<string>>:: iterator it = outData.begin(); it != outData.end(); it++) {
        cout<<"Employee "<<it->first<<" has "<<it->second.size()<<" report(s) :";
        for (vector<string>::iterator i = it->second.begin(); i != it->second.end(); i++)
            cout<<" "<<*i;
        cout<<endl;
    }
    return 0;
}
