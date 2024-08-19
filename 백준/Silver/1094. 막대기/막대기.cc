#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    short sticks[7] = { 1, 2, 4, 8, 16, 32, 64 };
    short x, result{}, cnt{};
    cin >> x;

    for (short i = 6; result != x && i >= 0; --i)
        if (sticks[i]+result <= x)
            result += sticks[i], ++cnt;
    
    cout << cnt;
}