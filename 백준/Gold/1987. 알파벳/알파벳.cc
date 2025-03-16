#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void backtracking(vector<vector<char>> &map, int &result, int x = 0, int y = 0, int len = 1) {
	static int weight[][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
	static bool visited[26] = {0,}; // 알파벳 26자

	visited[map[0][0]-65] = 1;

	for (int i{}; i < 4; ++i) {
		int mx = x + weight[i][0], my = y + weight[i][1];
		
		if (mx >= 0 && mx < map[0].size() && my >= 0 && my < map.size() && !visited[map[my][mx] - 65]) {
			visited[map[my][mx] - 65] = 1;
			result = max(result, len + 1);
			backtracking(map, result, mx, my, len + 1);
			visited[map[my][mx] - 65] = 0;
		}
	}
}

int solve(vector<vector<char>> &map) {
	int result = 1;
	backtracking(map, result);
	return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	int r, c;
	cin >> r >> c;
	vector<vector<char>> map(r, vector<char>(c));

	for (auto &i : map)
		for (auto &j : i)
			cin >> j;

	cout << solve(map);
}