//to match wildcard
#include<iostream>
using namespace std;

bool wildcardMatching(char *pattern, char *text) {
    if (*pattern == '\0' && *text == '\0')
        return true;
    if (*pattern == '*' && *(pattern+1) != '\0' && *text == '\0')
        return false;
    if (*pattern == '?' || *pattern == *text)
        return wildcardMatching(pattern+1, text+1);
    if (*pattern == '*')
        return wildcardMatching(pattern+1, text) || wildcardMatching(pattern, text+1);
    return false;
}

int main() {
    wildcardMatching("p*k*s*", "pratiksaha") ? cout<<"Yes\n" : cout<<"No\n";
    wildcardMatching("p*k?a*", "pratiksaha") ? cout<<"Yes\n" : cout<<"No\n";
    wildcardMatching("s*a", "sah") ? cout<<"Yes\n" : cout<<"No\n";
    wildcardMatching("*pqrs", "pqrst") ? cout<<"Yes\n" : cout<<"No\n";
    wildcardMatching("abc*bcd", "abcdhghgbcd") ? cout<<"Yes\n" : cout<<"No\n";
    wildcardMatching("abc*c?d", "abcd") ? cout<<"Yes\n" : cout<<"No\n";
    wildcardMatching("*c*d", "abcd") ? cout<<"Yes\n" : cout<<"No\n";
    wildcardMatching("*?c*d", "abcd") ? cout<<"Yes\n" : cout<<"No\n";
    return 0;
}
