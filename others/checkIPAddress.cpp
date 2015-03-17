//to check if a given string is valid IPv4 address
#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;

bool allDigits(char *token) {
    while (*token) {
        if (*token >= '0' && *token <= '9')
            token++;
        else
            return false;
    }
    return true;
}

bool checkIPAddress(char *inp) {
    char IP[strlen(inp)+1]; //to store inp so that the original input value is preserved
    strcpy(IP, inp);
    if (IP) {
        char *ptr = strtok(IP, ".");
        if (ptr) {
            int tokens = 1;
            while (ptr) {
                if (allDigits(ptr)) {
                    int num = atoi(ptr); //http://www.cplusplus.com/reference/cstdlib/atoi/
                    if (num >= 0 && num <= 255) {
                        ptr = strtok(NULL, "."); // http://www.cplusplus.com/reference/cstring/strtok/
                        if (ptr != NULL)
                            tokens++;
                    } else { //each token not between 0 and 255
                        return false;
                    }
                } else { //not all chars in current token are digits
                    return false;
                }
            }
            if (tokens == 4) //IPv4 address will have exactly 4 tokens
                return true;
            else
                return false;
        } else { //if IP could not be tokenized by . 
            return false;
        }
    } else { //input is NULL
        return false;
    }
}

int main() {
    char ip1[] = "128.0.0.1";
    char ip2[] = "125.16.100.1";
    char ip3[] = "125.512.100.1";
    char ip4[] = "125.12.100.abc";
    char ip5[] = "12534567";
    char ip6[] = "125.16.100.1.13";
    cout<<ip1<<(checkIPAddress(ip1)?" is a valid":" is not a valid")<<" IP address\n";
    cout<<ip2<<(checkIPAddress(ip2)?" is a valid":" is not a valid")<<" IP address\n";
    cout<<ip3<<(checkIPAddress(ip3)?" is a valid":" is not a valid")<<" IP address\n";
    cout<<ip4<<(checkIPAddress(ip4)?" is a valid":" is not a valid")<<" IP address\n";
    cout<<ip5<<(checkIPAddress(ip5)?" is a valid":" is not a valid")<<" IP address\n";
    cout<<ip6<<(checkIPAddress(ip6)?" is a valid":" is not a valid")<<" IP address\n";
    return 0;
}
