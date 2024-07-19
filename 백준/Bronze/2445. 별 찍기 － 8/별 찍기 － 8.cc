#include <iostream>

using namespace std;

int main() {
    short n;
    cin >> n;

    for (short i = 0; i < 2*n-1; ++i) {
        for (short j = 0; j < 2*n; ++j) {
            if (i < n)
                cout << (n*2-i-1 <= j || i >= j ? '*' : ' ');
            else
                cout << (n*2-i-1 > j || i < j ? '*' : ' ');
        }
        cout << endl;
    }
}