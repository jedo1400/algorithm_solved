#include <iostream>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    long long DP[101] = {0, 1, 1, 1, 2, 2};

    for (short i = 6; i <= 100; ++i)
        DP[i] = DP[i-1] + DP[i-5];

    int t;
    cin >> t;
    while (t--) {
        short n;
        cin >> n;
        cout << DP[n] << '\n';
    }
}