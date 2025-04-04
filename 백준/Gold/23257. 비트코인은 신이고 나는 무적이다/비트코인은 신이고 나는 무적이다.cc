#include <unordered_set>
#include <iostream>
#include <vector>

using namespace std;

void ref_abs(int &n) {
	n = n < 0 ? -n : n;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;	
	vector<unordered_set<int>> dp(m+1);
	vector<int> item(n);
	dp[0].insert(0);

	for (auto &i : item) {
		cin >> i;
		ref_abs(i);
		dp[1].insert(i);
	}

	for (int i = 2; i <= m; ++i)
		for (auto &j : dp[i-1]) // 이전 회차에 시도한 값들
			for (int k = 0; k < n; ++k)
				dp[i].insert(j ^ item[k]); // i번 회차에 j에 

	int result{};
	for (auto &i : dp[m])
		result = max(result, i);
	
	cout << result;
}