#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<vector<long long>> dp(65, vector<long long>(10, 0));

    for (int i = 0; i <= 9; ++i)
        dp[1][i] = 1;
    
    for (int i = 2; i <= 64; ++i)
        for (int j = 0; j <= 9; ++j)
            for (int k = j; k <= 9; ++k)
                dp[i][j] += dp[i-1][k];

    int t;
    cin >> t;

    while (t--) {
        int n;
        long long result{};
        cin >> n;

        for (int i{}; i <= 9; ++i)
            result += dp[n][i];
        
        cout << result << '\n';
    }
}