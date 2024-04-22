#include <iostream>

using namespace std;

int main() {
    short chess[6] = {1, 1, 2, 2, 2, 8};
    short input;
    for (short i = 0; i < 6; ++i) {
        cin >> input;
        if (input > chess[i]) cout << '-' << input - chess[i];
        else if (input < chess[i]) cout << chess[i] - input;
        else cout << 0;
        cout << ' ';
    }
}