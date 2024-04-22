#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int biggest[2] = { -10000, -10000 }, smallest[2] = { 10001, 10001 };
    int points, x, y;
    cin >> points;
    for (int i = 0; i < points; ++i) {
        cin >> x >> y;
        if (x > biggest[0]) biggest[0] = x;
        if (x < smallest[0]) smallest[0] = x;
        if (y > biggest[1]) biggest[1] = y;
        if (y < smallest[1]) smallest[1] = y;
    } cout <<  (biggest[0] - smallest[0]) * (biggest[1] - smallest[1]);
}