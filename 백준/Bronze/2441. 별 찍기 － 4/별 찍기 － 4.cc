#include <iostream>

using namespace std;

int main() {
    short n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            cout << (i <= j ? '*' : ' ');
        cout << '\n';
    }
}