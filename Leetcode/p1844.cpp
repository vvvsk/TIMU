#include "bits/stdc++.h"

using namespace std;
char shift(char c,int x){
    return (int)c+x-'0';
}
string replaceDigits(string s) {
    for(int i=1;i<s.size();i+=2){
        s[i] = shift(s[i-1],s[i]);
    }
    return  s;
}
int main() {
    string s = "a1b1c1e1";
    auto ret = replaceDigits(s);
    return 0;
}