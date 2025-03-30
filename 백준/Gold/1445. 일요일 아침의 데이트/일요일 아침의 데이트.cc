#include <iostream>
#include <utility>
#include <vector>
#include <queue>
#include <tuple>
// #include <cstdlib>
// #include <unistd.h>

using namespace std;

#define MAX 50
#define PII pair<int, int>
#define TIIII tuple<int, int, int, int>

const int weight[][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} };

PII dijkstra(vector<vector<char>> &map, PII s, PII f) {
	priority_queue<TIIII, vector<TIIII>, greater<TIIII>> pq;
	bool visited[MAX + 1][MAX + 1]{0,};
	// [쓰레기로 차있는 칸을 지난 횟수, 쓰레기 옆을 지나간 횟수, x, y]

	pq.push({0, 0, s.first, s.second});
	visited[s.second][s.first] = 1;

	while (!pq.empty()) {
		auto [a, b, x, y] = pq.top();
		pq.pop();

		// 시각화
		// cout << a << ' ' << b << ' ' << x << ' ' << y << '\n';
		// for (int i = 0; i < map.size(); ++i) {
		// 	for (int j = 0; j < map[0].size(); ++j)
		// 		if (i == y && j == x)
		// 			cout << '*' << ' ';
		// 		else
		// 			cout << map[i][j] << ' ';
				
		// 	cout << '\n';
		// }
		// usleep(1000000);
		// system("clear");
 
		if (x == f.first && y == f.second)
			return {a, b};
		

		for (int i{}; i < 4; ++i) {
			int mx = x + weight[i][0], my = y + weight[i][1];

			if (my >= 0 && my < map.size() && mx >= 0 && mx < map[0].size() && !visited[my][mx]) {
				int ma = a, mb = b;

				if (map[my][mx] == 'g') 		++ma; // 쓰레기 칸
				else if (map[my][mx] == 'x')	++mb; // 쓰레기와 인접한 칸

				pq.push({ma, mb, mx, my});
				visited[my][mx] = 1;
			}
		}
	}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	vector<vector<char>> map(n, vector<char>(m, 0));
	// S = 출발점, F = 도착점, g = 쓰레기, x = 쓰레기와 인접한 칸

	PII s, f;
	for (int i{}; i < n; ++i)
		for (int j{}; j < m; ++j) {
			if (map[i][j] == 'x') {
				cin >> map[i][j];

				if (map[i][j] == '.') {
					map[i][j] = 'x';
					continue;
				}
			}
			else
				cin >> map[i][j];

			if (map[i][j] == 'S')
				s = {j, i};
			else if (map[i][j] == 'F')
				f = {j, i};
			else if (map[i][j] == 'g')
				for (int k{}; k < 4; ++k) {
					int mx = j + weight[k][0], my = i + weight[k][1];

					if (mx >= 0 && mx < m && my >= 0 && my < n && (map[my][mx] == '.' || map[my][mx] == 0)) {
						map[my][mx] = 'x';
					}
				}
		}
	
	auto [a, b] = dijkstra(map, s, f);
	cout << a << ' ' << b;
}