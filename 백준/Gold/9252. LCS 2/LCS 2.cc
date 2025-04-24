#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string a, b;
	int n, m;
	cin >> a >> b;

	n = a.length(), m = b.length()
	, a = '\0' + a, b = '\0' + b; // 패딩

	vector<vector<int>> dp(a.length(), vector<int>(b.length(), 0));

	for (int i = 1; i < a.length(); ++i)
		for (int j = 1; j < b.length(); ++j) {
			if (a[i] == b[j])
				dp[i][j] = dp[i-1][j-1] + 1;
			else
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	
	vector<int> result;
	while (n && m) {
		if (a[n] == b[m]) {
			result.push_back(n);
			--n, --m;
		}

		else
			if (dp[n-1][m] == dp[n][m]) // 그 줄에는 공통 문자가 없음
				--n;
			else
				--m;
	}

	cout << result.size() << '\n';
	for (int i = result.size()-1; i >= 0; --i)
		cout << a[result[i]];
}