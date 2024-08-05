#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    short n, result{};
    cin >> n;

    while (n >= 5)
        result += n/5, n /= 5; // 5에서 1, 125에서 2 더함

    cout << result;
}