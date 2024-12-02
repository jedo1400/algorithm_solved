#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int LCS(const string &a, const string &b) {
    vector<vector<int>> dp(a.length()+1, vector<int>(b.length()+1, 0));

    for (int i = 1; i <= a.length(); ++i) {
        int y = i-1;
        for (int j = 1; j <= b.length(); ++j) {
            int x = j-1;
            if (a[y] == b[x])
                dp[i][j] = dp[y][x] + 1;
            else
                dp[i][j] = max(dp[i][x], dp[y][j]);
        }
    }

    return dp.back().back();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string a, b;
    cin >> a >> b;

    cout << LCS(a, b);
}