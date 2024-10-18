#include <iostream>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

int bfs(vector<short> &ladder, vector<short> &snake) {
	vector<pair<bool, int>> visited(101, make_pair(0, 0));
	queue<short> waitlist;

	waitlist.push(1);
	visited[1] = make_pair(1, 0);

	while (!waitlist.empty()) {
		short top = waitlist.front(), og_count = visited[top].second;
		waitlist.pop();
		
		for (short i = 1; i <= 6; ++i) {
			short sum = top+i;

			if (sum > 100)
				break;

			if (snake[sum])
				sum = snake[sum];

			if (ladder[sum])
				sum = ladder[sum];

			if (!visited[sum].first) {
				visited[sum] = make_pair(1, og_count+1);
				waitlist.push(sum);
			}
		}	
	}

	return visited[100].second;
}

int main() {
	short n, m;
	cin >> n >> m;
	vector<short> ladder(101, 0), snake(101, 0);

	while (n--) {
		short x, y;
		cin >> x >> y;
		ladder[x] = y;
	}

	while (m--) {
		short u, v;
		cin >> u >> v;
		snake[u] = v;
	}

	cout << bfs(ladder, snake);
}