#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b, rsa{};
    cin >> a >> b;
    for (int i = a; i <= b; ++i) {
        int divisor = 2; // 자기자신, 1
        for (int j = 2; j <= i/2 && divisor <= 4; ++j)
            if (!(i % j))
                ++divisor;

        if (divisor == 4)
            ++rsa;
    }

    cout << "The number of RSA numbers between " << a << " and " << b << " is " << rsa;
}