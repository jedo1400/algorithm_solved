#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define LL long long

int solve(vector<vector<LL>> &map, vector<vector<LL>> &dp, int x, int y) {
	static int w[][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

	// 목적지에 도달한 경우
	if (x == map[0].size()-1 && y == map.size() - 1) return 1;
	// 먼저 와봤었던 경우 기록해둔 해당 좌표 -> 목적지까지 갈 수 있는 경우의 수 반환
	if (dp[y][x] != -1) return dp[y][x];

	dp[y][x] = 0; // -1은 초기화 안된 상태를 나타내는 플래그일 뿐이므로 다시 초기화해주기

	for (int i = 0; i < 4; ++i) {
		int mx = x + w[i][0], my = y + w[i][1];
		if (mx >= 0 && mx < map[0].size() && my >= 0 && my < map.size() && map[my][mx] < map[y][x] )
			dp[y][x] = dp[y][x] + solve(map, dp, mx, my);
	}
	
	return dp[y][x];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int m, n;
	cin >> m >> n;
	vector<vector<LL>> map(m, vector<LL>(n));

	for (auto &i : map)
		for (auto &j : i)
			cin >> j;

	vector<vector<LL>> dp(m, vector<LL>(n, -1));

	cout << solve(map, dp, 0, 0);
}