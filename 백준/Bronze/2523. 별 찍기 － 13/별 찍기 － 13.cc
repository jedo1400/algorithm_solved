#include <iostream>

using namespace std;

int main() {
    short n;
    cin >> n;

    for (short i = 1; i <= n; ++i) {
        for (short j = 1; j <= i; ++j)
            cout << '*';
        cout << '\n';
    }

    for (short i = n-1; i >= 1; --i) {
        for (short j = 0; j < i; ++j)
            cout << '*';
        cout << '\n';
    }
}