#include <iostream>
#include <vector>

using namespace std;

int main() {
    short tmp, largest = -1;
    short pos[2];
    for (short i = 0; i < 9; ++i)
        for (short j = 0; j < 9; ++j) {
            cin >> tmp;
            if (tmp > largest) largest = tmp, pos[0] = i, pos[1] = j;
        }
    cout << largest << endl << pos[0]+1 << ' ' << pos[1]+1;
}