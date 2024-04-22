#include <iostream>

using namespace std;

int main() {
    short temp;
    short result = 1;

    while (result != 0) {
        if (result != 1)
            cout << result << endl;
        result = 0;
        for (short j = 0; j < 2; ++j) {
            cin >> temp;
            result += temp;
        }
    }
}