#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, result{};
    cin >> n;

    while (n--) {
        int a, b;
        cin >> a >> b;
        result += a * b;
    }

    cout << result;
}