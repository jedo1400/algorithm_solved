#include <iostream>

using namespace std;

int main() {
    short n;
    cin >> n;
    for (short i = 0; i < n; ++i) {
        for (short j = 1; j <= n+i; ++j)
            cout << (j >= n-i ? '*' : ' ');
        cout << endl;
    }
    for (short i = 0; i < n-1; ++i) {
        for (short j = 1; j < 2*n-1-i; ++j)
            cout << (j <= i+1 ? ' ' : '*');
        cout << endl;
    }
}