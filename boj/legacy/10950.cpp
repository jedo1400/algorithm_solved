#include <iostream>

using namespace std;

int main() {
    short t, temp;
    cin >> t;
    int* result = new int[t]{};
    for (short i = 0; i < t; ++i)
        for (short j = 0; j < 2; ++j) {
            cin >> temp;
            result[i] += temp;
        }
    for (short i = 0; i < t; ++i)
        cout << result[i] << endl;
}