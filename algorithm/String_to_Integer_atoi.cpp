#include <iostream>
#include <limits.h>
using namespace std;

int myAtoi(string str) {
    int index = 0;
    while (str[index] == ' ' || str[index] == '\t') {
        ++index;
    }
    int flag = 0;
    if (str[index] == '-' || str[index] == '+') {
        flag = (str[index++] == '-')? -1 : 1;
    }
    int result = 0, length = str.length();
    for (; index < length && str[index] >= '0' && str[index] <= '9'; ++index) {
        if (result > INT_MAX / 10 || (result == INT_MAX / 10 && str[index] - '0' > 7)) {
            if (flag == 0 || flag == 1) {
                return INT_MAX;
            } else {
                return INT_MIN;
            }
        }
        result = result * 10 + (str[index] - '0' );
    }
    return ((flag == 0)? 1 : flag) * result;
}

int main(int argc, const char *argv[]) {
    string a;
    while (cin >> a) {
        cout << myAtoi(a) << endl;
    }
    return 0;
}
