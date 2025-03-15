#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

bool locate(vector<int> &v, int m, bool* visited, int dist) {
	int cnt = 1, before = v[0], stack{};

	memset(visited, 0, v.size());
	visited[0] = 1;

	for (int i = 1; i < v.size(); ++i) {
		stack += v[i]-before, before = v[i];

		if (stack >= dist) {
			visited[i] = 1
			, ++cnt, stack = 0;

			if (cnt == m)
				return 1;
		} else visited[i] = 0;
		
	}

	return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	int n, m, k;
	cin >> n >> m >> k;
	vector<int> pos(k);

	int l = 0, r = 0;
	for (auto &i : pos) {
		cin >> i;
		r = max(r, i);
	}
	
	// K개의 위치는 N보다 작거나 같은 자연수 또는 0이며, 오름차순으로 주어진다.
	
	bool* visited = new bool[k];

	while (l <= r) {
		int mid = (l + r) / 2;

		if (locate(pos, m, visited, mid))
			l = mid + 1;
		else
			r = mid - 1;
	}

	// 다시 안찾는 경우 경우 반례
	// 20 3 4
	// 0 5 10 15 
	locate(pos, m, visited, r);

	for (int i{}; i < k; ++i)
		cout << visited[i];
}