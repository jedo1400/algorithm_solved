#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define MAX 1000
#define PII pair<int, int>

vector<vector<vector<int>>> dp(3, vector<vector<int>>(MAX, vector<int>(MAX, -1)));
// dp[i][j][k] -> i - 먹어야하는 우유, j - y, k - x

int sol(vector<vector<int>> &map, int x = 0, int y = 0, int need = 0) {
	if (x == map.size() - 1 && y == map.size() - 1) // 목적지 예외처리
		return map[y][x] == need;

	if (dp[need][y][x] != -1)
		return dp[need][y][x]; // 종료조건

	int mn = (need + 1) % 3
		, mx = x + 1, my = y + 1;
	
	if (map[y][x] == need) {
		// 우유를 먹지 않고 지나치는 경우가 이득인 경우도 있음
		if (mx < map.size())
			dp[need][y][x] = max(dp[need][y][x], max(sol(map, mx, y, mn) + 1, sol(map, mx, y, need)));
		
		if (my < map.size())
			dp[need][y][x] = max(dp[need][y][x], max(sol(map, x, my, mn) + 1, sol(map, x, my, need)));
	}

	else {
		if (mx < map.size())
			dp[need][y][x] = max(dp[need][y][x], sol(map, mx, y, need));
		
		if (my < map.size())
			dp[need][y][x] = max(dp[need][y][x], sol(map, x, my, need));
	}

	return dp[need][y][x];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<vector<int>> map(n, vector<int>(n));

	for (auto &i : map)
		for (auto &j : i)
			cin >> j;	
	
	cout << sol(map);
}