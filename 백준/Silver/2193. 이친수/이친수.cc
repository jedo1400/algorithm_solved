#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long dp[91] = { 0, 1 };

    for (int i = 2; i <= 90; ++i)
        dp[i] = dp[i-1] + dp[i-2];
        
    int n;
    cin >> n;
    cout << dp[n];
}