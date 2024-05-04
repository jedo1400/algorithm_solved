#include <iostream>
#include <string>

using namespace std;

int main() {
    char input;
    short n = 0;

    for (short i = 1; i <= 8; ++i)
        for (short j = 1; j <= 8; ++j) {
            cin >> input;
            if (input == 'F') {
                if (!(i % 2) && !(j % 2)) ++n;
                if (i % 2 && j % 2) ++n;
            }
        }
    cout << n;
}