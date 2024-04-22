#include <iostream>
#include <limits.h>

using namespace std;

int getDiffrent(int* input) {
    short type[1001] = {0,};
    int index[2] = { 0, INT_MAX };
    for (short i = 0; i < 3; ++i) {
        if (index[1] > input[i]) index[1] = input[i];
        if (index[0] < input[i]) index[0] = input[i];
        type[input[i]]++;
    }
    for (short i = 0; i < 2; ++i)
        if (type[index[i]] == 1)
            return index[i];
    return -1;
}

int main() {
    int pos[2][3];
    for (short i = 0; i < 3; ++i)
        cin >> pos[0][i] >> pos[1][i];
    for (short i = 0; i < 2; ++i)
        cout << getDiffrent(pos[i]) << ' ';
}