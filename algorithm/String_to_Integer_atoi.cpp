#include <iostream>
using namespace std;

int myAtoi(string str) {
    bool flag = (str[0] <= '9' && str[0] >= '0');
    int result = 0, length = str.length();
    if (!flag) {
        if (str[1] > '9' || str[1] < '0') {
            return result;
        }
    }
    for (int i = ((flag)? 0 : 1); i < length; i++) {
        result *= 10;
        result += (str[i] - '0' );
    }
    return ((flag)? 1 : ((str[0] == '-')? -1 : 1)) * result;
}

int main(int argc, const char *argv[]) {
    string a;
    while (cin >> a) {
        cout << myAtoi(a) << endl;
    }
    return 0;
}
