#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
    int input;
    short base;
    string result;
    cin >> input >> base;

    while(input >= 1) {
        result.push_back((char)(input%base+(input%base < 10 ? 48 : 55)));
        input = input/base;
    } for (short i = result.size()-1; i >= 0; --i)
        cout << result[i];
}