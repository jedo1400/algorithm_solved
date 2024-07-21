#include <iostream>

using namespace std;

int main() {
    short n;
    cin >> n;

    for (short i = 0; i < n; ++i) {
        for (short j = 1; j < 2*n-i; ++j)
            cout << (i < j ? '*' : ' ');
        cout << '\n';
    }

    for (short i = 1; i < n; ++i) {
        for (short j = 1; j <= n+i; ++j)
            cout << (n-i <= j ? '*' : ' ');
        cout << '\n';
    }
}