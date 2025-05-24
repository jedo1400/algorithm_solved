#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define INF 1e9

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<vector<int>> rgb(n, vector<int>(3));
    
    for (auto &i : rgb) 
        for (auto &j : i)
            cin >> j;

    int result = INF;

    for (int s = 0; s < 3; ++s) {
        vector<vector<int>> dp(n, vector<int>(3, INF));
        dp[0][s] = rgb[0][s]; // 1번 집의 색 고르기

        for (int i = 1; i < n; ++i)
            dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + rgb[i][0]
            , dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + rgb[i][1]
            , dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + rgb[i][2];

        // cout << '\n';
        // for (auto &i : dp) {
        //     for (auto &j : i)
        //         cout << (j >= INF ? -1 : j) << '\t';
        //     cout << '\n';
        // }

        for (int i = 0; i < 3; ++i)
            if (i != s)
                result = min(result, dp[n-1][i]);
    }

    cout << result;
}