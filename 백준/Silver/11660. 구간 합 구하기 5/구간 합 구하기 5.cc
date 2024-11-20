#include <iostream>
#include <vector>
#define endl '\n';

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<vector<int> > arr(n, vector<int>(n))
                        , dp(n+1, vector<int>(n+1, 0));

    for (auto &i : arr)
        for (auto &j : i)
            cin >> j;
    
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            dp[i][j] = dp[i][j-1] + dp[i-1][j] + arr[i-1][j-1] - dp[i-1][j-1];
    
    while (m--) {
        int x1, y1, x2, y2;
        cin >> y1 >> x1 >> y2 >> x2;
        cout << dp[y2][x2] - dp[y2][x1-1] - dp[y1-1][x2] + dp[y1-1][x1-1] << endl;
    }
}