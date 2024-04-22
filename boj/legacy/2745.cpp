#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
    string input;
    short base;
    int decimal = 0;
    
    cin >> input >> base;

    cout << fixed;
    cout.precision(0);
    for (short i = 1; i <= input.size(); ++i) {
        if ((int)input[i-1] > 64) decimal += (((int)input[i-1])-55)*pow(base, input.size()-i);
        else decimal += (((int)input[i-1])-48)*pow(base, input.size()-i);
    } cout << decimal;
}