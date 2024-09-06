#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<short> dp(1001, 0);
    dp[1] = 1, dp[2] = 2;
    short n;
    cin >> n;

    if (n < 3) {
        cout << dp[n];
        return 0;
    }

    for (short i = 3; i <= n; ++i)
        dp[i] = dp[i-1]%10007 + dp[i-2]%10007;

    cout << dp[n]%10007;
}