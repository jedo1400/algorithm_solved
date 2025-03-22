#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

#define PII pair<int, int>

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	int n, k;
	cin >> n >> k;
	vector<PII> item(k);
	vector<vector<int>> dp(k+1, vector<int>(n+1, 0));

	for (auto &i : item)
		cin >> i.first >> i.second;

	sort(item.begin(), item.end(), 
    [](pair<int, int> &a, pair<int, int> &b) -> bool {
        if (a.second != b.second)
            return a.second < b.second;
        else
            return a.first < b.first;
    });

	for (int i = 1; i <= k; ++i)
		for (int j = 1; j <= n; ++j) {
			auto [v, w] = item[i-1];
			if (j >= w)
				dp[i][j] = max(dp[i-1][j], dp[i-1][j-w] + v);
			else
				dp[i][j] = dp[i-1][j];
		}
	
	cout << dp[k][n];
}