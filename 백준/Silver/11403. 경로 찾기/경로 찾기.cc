#include <iostream>
#include <vector>
#include <deque>

using namespace std;

void dfs(vector<vector<short>> &array, deque<bool> &visited, short n) {
	for (auto &i : array[n])
		if (!visited[i]) {
			visited[i] = 1;
			dfs(array, visited, i);
		}
}

void dfs(vector<vector<short>> &array) {
	for (unsigned short i = 0; i < array.size(); ++i) {
		deque<bool> visited(array.size(), 0);
		dfs(array, visited, i);

		for (auto &i : visited)
			cout << i << ' ';
		cout << '\n';
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	short n;
	cin >> n;
	// deque<deque<bool>> board(n, deque<bool>(n, 0));
	vector<vector<short>> array(n);
	
	for (short i = 0; i < n; ++i)
		for (short j = 0; j < n; ++j) {
			bool tmp;
			cin >> tmp;
			if (tmp)
				array[i].push_back(j);
		}

	dfs(array);
}