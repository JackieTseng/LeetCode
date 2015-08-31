#include <iostream>
#include <string>
using namespace std;

bool isNumber(string s) {
    int i = 0, length = s.length();
    while (s[i] == ' ') {
        ++i;
    }
    if (s[i] == '+' || s[i] == '-') {
        ++i;
    }
    int num, point;
    for (num = 0, point = 0; i < length && (isdigit(s[i]) || s[i] == '.'); ++i) {
        s[i] == '.' ? ++point : ++num; 
    }
    if (point > 1 || num < 1) {
        return false;
    }
    if (s[i] == 'e') {
        ++i;
        if (s[i] == '+' || s[i] == '-') {
            ++i;
        }
        for (num = 0; i < length && isdigit(s[i]) ; ++i, ++num) {
        }
        if (num < 1) {
            return false;
        }
    }
    while (s[i] == ' ') {
        ++i;
    }
    return i == length;
}

int main(int argc, const char *argv[]) {
    string t;
    while (cin >> t) {
        cout << (isNumber(t) ? "Yes" : "No") << endl;
    } 
    return 0;
}
