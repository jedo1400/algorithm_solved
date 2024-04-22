#include <iostream>
#include <limits.h>

using namespace std;

int main() {
    short input, max = SHRT_MIN, idx;

    for (short i = 0; i < 9; ++i) {
        cin >> input;
        if (input > max) max = input, idx = i+1;
    } cout << max << endl << idx;
}