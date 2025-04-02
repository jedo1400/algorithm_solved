#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int bfs(vector<vector<int>> &con, vector<int> &delay, vector<int> &indegree, int e) {
	vector<int> dp(delay.size(), 0);
	queue<int> q;

	for (int i = 1; i < delay.size(); ++i)
		if (!indegree[i]) {
			q.push(i);
			dp[i] = delay[i];
		}

	while (!q.empty()) {
		int f = q.front(), t{};
		
		for (auto &i : con[f]) {
			dp[i] = max(dp[i], dp[f] + delay[i]);

			if (!--indegree[i])
				q.push(i);
		}

		q.pop();
	}

	return dp[e];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t;
	cin >> t;

	while (t--) {
		int n, k;
		cin >> n >> k;
		vector<int> delay(n+1), indegree(n+1, 0);
		vector<vector<int>> con(n+1, vector<int>());

		for (int i = 1; i <= n; ++i)
			cin >> delay[i];

		while (k--) {
			int x, y; // 건물 x를 지은 다음 건물 y를 짓는 것이 가능하다
			cin >> x >> y;
			con[x].push_back(y);
			++indegree[y];
		}

		int e;
		cin >> e;

		cout << bfs(con, delay, indegree, e) << '\n';
	}
}