#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int getResistance(string &c, bool flag = 0) {
    int result;
    if (c == "black") result = 0;
    else if (c == "brown") result = 1;
    else if (c == "red") result = 2;
    else if (c == "orange") result = 3;
    else if (c == "yellow") result = 4;
    else if (c == "green") result = 5;
    else if (c == "blue") result = 6;
    else if (c == "violet") result = 7;
    else if (c == "grey") result = 8;
    else result = 9;

    return flag ? pow(10, result) : result;
}

int main() {
    string input;
    long long result = 0;
    
    for (short i = 1; i > -1; --i) {
        cin >> input;
        result += getResistance(input) * pow(10, i);
    } cin >> input;
    cout << result * getResistance(input, 1);
}