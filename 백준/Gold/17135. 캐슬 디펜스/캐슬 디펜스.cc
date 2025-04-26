#include <iostream>
#include <utility>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

#define MAX 15
#define PII pair<int, int>

int n, m, d;
vector<PII> enemies; // {x, y}

int abs(int n) {
	return n > 0 ? n : -n;
}

int dist(int &sx, int &ex, int &ey) { // 궁수 좌표, 적 x, 적 y
	return abs(sx-ex) + abs(n-ey);
}

int simulate(int s[3]) { // 각 궁수의 좌표
	int visited[MAX * MAX]{0,};

	int ke = 0;
	
	for (int t = 0; t < n; ++t) {
		int target[3] = {-1, -1, -1}; // 같은 적이 여러 궁수에게 공격당할 수 있다

		for (int i = 0; i < 3; ++i) {
			int nv = d+1, ni = -1; // 가장 가까운 거리, 가장 가까운 적  

			for (int j = 0; j < enemies.size(); ++j) {
				auto [x, y] = enemies[j];
				y += t; // 흐른 시간만큼 이동

				int td = dist(s[i], x, y);

                if (!visited[j] && y < n && td <= d)
					// j번째 적과의 거리가 차이 최소이거나 같으면서 같은 경우 현재의 최선보다 왼쪽에 있는 경우
                    if (td < nv || (td == nv && x < (ni == -1 ? 1e9 : enemies[ni].first))) {
                        nv = td;
                        ni = j;
                    }
			}

			target[i] = ni;
		}

		for (int i = 0; i < 3; ++i)
			if (target[i] != -1 && !visited[target[i]])
				++ke, visited[target[i]] = 1;
	}

	return ke;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> d;

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			int k;
			cin >> k;

			if (k)
				enemies.push_back({j, i});
		}

	int s[3], result = 0;

	for (int i = 0; i < m; ++i)
		for (int j = i+1; j < m; ++j)
			for (int k = j+1; k < m; ++k) {
				s[0] = i, s[1] = j, s[2] = k;
				result = max(result, simulate(s));
			}
				
	cout << result;
}