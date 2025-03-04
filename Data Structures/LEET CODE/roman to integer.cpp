#include<bits/stdc++.h>
using namespace std;
int romanToInt(string s) {
    unordered_map<char,int>roman
    {
        {'I',1},{'V',5},{'X',10},{'L',50},
          {'C',100},{'D',500},{'M',1000}
    };
    int n = s.size(), result = 0;
    for (int i = 0 ; i < n ; i++) {
            if (roman[s[i]] < roman[s[i+1]]) {
                result = result - roman[s[i]];
            }
        else {
            result = result + roman[s[i]];
        }
    }
    return result;
}
int main() {
    string s = "XI";
    int result = romanToInt(s);
    cout << result;
    return 0;
}