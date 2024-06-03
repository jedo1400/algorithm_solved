#include <iostream>

using namespace std;

short gcd(short n, short m) {
    if (!(n % m))
        return m;
    return gcd(m, n % m);
}

int main() {
    short a, b, swap;
    cin >> a >> b;
    if (a < b)
        swap = b
        , b = a
        , a = swap;
    short m = gcd(a, b);
    cout << gcd(a, b) << '\n' << m*(a/m)*(b/m);
}