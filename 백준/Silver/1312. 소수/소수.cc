#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b, n, m;
    cin >> a >> b >> n;

    a %= b;

    while (n) {
        if (a < b)
            a *= 10;
        m = a/b, a %= b;
        --n;
    }

    cout << m;
}