#include <iostream>

using namespace std;

int main() {
    short n, k, count = 0;
    cin >> n >> k;
    for (short i = 1; count <= k && i <= n; ++i) {
        if (n % i == 0) {
            count++;
            if (count == k) {
                cout << i;
                return 0;
            }
        }
    } cout << 0;
}