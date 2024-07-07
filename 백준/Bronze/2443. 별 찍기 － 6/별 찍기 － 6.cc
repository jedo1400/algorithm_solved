#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    short n;
    cin >> n;

    for (short i = 0; i < n; ++i) {
        for (short j = 1; j <= n*2; ++j) {
            if (n*2-i <= j)
                break;
            cout << (i < j ? '*' : ' ');
        }
        cout << '\n';
    }
}