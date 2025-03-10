#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, t;
    cin >> n >> t;
    vector<pair<int, int>> chapter(n);
    vector<vector<int>> dp(n+1, vector<int>(t+1, 0));

    for (auto &i : chapter)
        cin >> i.first >> i.second;
    
    for (int i = 1; i <= n; ++i) {
        auto [w, v] = chapter[i-1];
        for (int j = 0; j <= t; ++j) {
            if (w <= j)
                dp[i][j] = max(dp[i-1][j], v + dp[i-1][j-w]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }

    cout << dp[n][t];
}