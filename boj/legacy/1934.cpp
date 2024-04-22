#include <iostream>

using namespace std;

int gcd(int a, int b) {
    return ((a % b) ? gcd(b, a % b) : b);
}

int main() {
    short t;
    int a, b, swap, tmp;
    cin >> t;
    for (short i = 0; i < t; ++i) {
        cin >> a >> b;
        cout << a*b/gcd(a, b) << '\n';
    }
}