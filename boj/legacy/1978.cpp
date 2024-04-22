#include <iostream>

using namespace std;

int main() {
    short n, m, o = 0;
    bool is_prime;
    cin >> n;
    for (short i = 0; i < n; ++i) {
        is_prime = 1;
        cin >> m;
        if (m <= 2) {
            if (m == 2) o++;
            continue;
        }
        else if (m != 1)
            for (short i = 2; i < m; ++i)
                if (m % i == 0) {
                    is_prime = 0;
                    break;
                }
        if (is_prime) o++;
        } cout << o;
}