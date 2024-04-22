#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<bool> remain(1000, 0);
    short temp, cnt = 0;

    for (short i = 0; i < 10; ++i) {
        cin >> temp;
        if (remain[temp%42] == 0)
            remain[temp%42] = 1, ++cnt;
    } cout << cnt;
}