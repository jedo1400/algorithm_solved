#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    unsigned short a, b, c, i;
    cin >> a >> b >> c;
    for (i = 1; b/i > 9; i *= 10)
        continue;
    cout << a+b-c << '\n' << (int)(a*i*10)+b-c;
}