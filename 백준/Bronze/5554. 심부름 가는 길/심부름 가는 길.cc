#include <iostream>

using namespace std;

int main() {
    short sec, result = 0;
    for (short i = 0; i < 4; ++i) {
        cin >> sec;
        result += sec;
    }
    cout << result / 60 << endl << result % 60;
}