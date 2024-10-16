#include <iostream>
#include <vector>
#include <deque>

using namespace std;

void dfs(vector<vector<char>> &array, deque<deque<bool>> &visited, short x, short y, char point) {
	// 1 = RED, 2 = GREEN, 3 = BLUE, 4 = BLIND_REDGREEN(L)
	static short direction[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };

	visited[y][x] = 1;
	
	for (short i = 0; i < 4; ++i) {
		short moved_y = y+direction[i][1], moved_x = x+direction[i][0];
		if (moved_y < array.size() && moved_x < array.size() && !visited[moved_y][moved_x]) {
			if ((point != 'L' && array[moved_y][moved_x] == point)
				|| (point == 'L' && (array[moved_y][moved_x] == 'R' || array[moved_y][moved_x] == 'G')))
				dfs(array, visited, moved_x, moved_y, point);
		}
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
	short n;
	cin >> n;
	vector<vector<char>> array(n, vector<char>(n));
	deque<deque<bool>> visited_normal(n, deque<bool>(n, 0))
					 , visited_blind(n, deque<bool>(n, 0));

	for (auto &i : array)
		for (auto &j : i)
			cin >> j;

	short count_normal{}, count_blind{};
	
	for (short i = 0; i < n; ++i)
		for (short j = 0; j < n; ++j) {
			if (!visited_normal[i][j])
				dfs(array, visited_normal, j, i, array[i][j]), ++count_normal;
			if (!visited_blind[i][j])
				dfs(array, visited_blind, j, i, array[i][j] == 'R' || array[i][j] == 'G' ? 'L' : 'B'), ++count_blind;
		}

	cout << count_normal << '\n' << count_blind;
}