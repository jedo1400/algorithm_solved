#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

#define INF 101
#define PII pair<int, int>

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
	cin >> n >> k;
	vector<int> coffee(n), dp(k+1, INF);
	dp[0] = 0;
	
	for (auto &i : coffee)
		cin >> i;

	sort(coffee.begin(), coffee.end());

	for (auto &c : coffee)
		for (int i = k; i >= c; --i)
			if (dp[i-c] != INF)
				dp[i] = min(dp[i], dp[i-c] + 1);

	cout << (dp[k] == INF ? -1 : dp[k]);
}