#include <iostream>
#include <utility>
#include <vector>
#include <cmath>

using namespace std;

bool check(vector<pair<int, int>> &queen, int x, int y) {
	for (auto &i : queen)
		if (abs(i.first-x) == abs(i.second-y))
			return 0;

	return 1;
}

int solve(int n, int y = 0) {
	static int result{}, visited[16]{0,}; // 같은 열에 퀸이 있는가
	static vector<pair<int, int>> queen;

	if (y == n)
		++result;

	else
		for (int i = 0; i < n; ++i)
			if (!visited[i] && check(queen, i, y)) {
				visited[i] = 1;
				queen.push_back({i, y});

				solve(n, y + 1);

				visited[i] = 0;
				queen.pop_back();
			}
	
	return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	int n;
	cin >> n;

	cout << solve(n);
}