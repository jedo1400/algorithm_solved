#include <iostream>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int DP[41] = {0, 1, 1};
    for (short i = 2; i <= 40; ++i)
        DP[i] = DP[i-1] + DP[i-2];

    int t;
    cin >> t;
    while (t--) {
        short n;
        cin >> n;
        cout << (!n ? 1 : DP[n-1]) << ' ' << DP[n] << '\n';
    }
}