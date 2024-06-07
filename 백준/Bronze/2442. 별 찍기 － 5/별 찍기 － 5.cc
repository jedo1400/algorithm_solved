#include <iostream>

using namespace std;

int main() {
    short n;
    cin >> n;

    for (short i = 0; i <= n-1; ++i) {
        for (short j = 0; j < n+i; ++j)
            cout << (j >= n-i-1 ? '*' : ' ');
        cout << endl;
    }
}