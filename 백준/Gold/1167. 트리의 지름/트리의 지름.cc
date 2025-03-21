#include <iostream>
#include <utility>
#include <cstring>
#include <vector>

using namespace std;

#define PII pair<int, int>

void dfs(vector<vector<PII>> &tree, bool visited[], int n, PII &r, int v = 0) {
	visited[n] = 1;
	
	for (auto &i : tree[n])
		if (!visited[i.first]) {
			visited[i.first] = 1;

			if (v + i.second > r.second)
				r = { i.first, v + i.second };

			dfs(tree, visited, i.first, r, v + i.second);
		}
}

int solve(vector<vector<PII>> &tree) {
	bool visited[100001]{0,};
	PII which = { 0, 0 };

	// 트리에는 간선이 없는 노드는 존재하지 않음, 모든 노드는 연결되어있음
	// 따라서 임의의 노드로부터 가장 먼 노드 -> 가장 먼 노드에서 가장 먼 노드의 길이가 트리의 지름임
	dfs(tree, visited, 1, which);
	memset(visited, 0, sizeof(bool) * 100001);
	dfs(tree, visited, which.first, which);

	return which.second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	int v;
	cin >> v;
	vector<vector<PII>> tree(v+1); // {정점번호, 비용)

	while (v--) {
		int n;
		cin >> n;

		int a, b;
		while (cin >> a && a != -1) {
			cin >> b;
			tree[n].push_back({a, b});
			tree[a].push_back({n, b});
			// 트리는 무방향 그래프, 각 노드는 긴선으로 방향에 관계없이 연결되어있음
		}
	}

	cout << solve(tree);
}