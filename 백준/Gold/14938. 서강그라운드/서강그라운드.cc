#include <iostream>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

#define INF (unsigned int)(1 << 31) - 1
#define PII pair<int, int>

vector<int> dijkstra(vector<vector<PII>> &edge, int s, int m) {
	priority_queue<PII, vector<PII>, greater<PII>> pq;
	vector<int> dist(edge.size(), INF);

	pq.push({0, s});
	dist[s] = 0;

	while (!pq.empty()) {
		auto [v, c] = pq.top();
		pq.pop();

		for (auto &i : edge[c]) {
			auto [_c, _v] = i;
			int sum = _v + v;

			if (sum <= m && sum < dist[_c]) {
				pq.push({sum, _c});
				dist[_c] = sum;
			}
		}
	}

	vector<int> result;
	for (int i = 1; i < edge.size(); ++i)
		if (dist[i] != INF)
			result.push_back(i);
	
	return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	int n, m, r;
	cin >> n >> m >> r;
	vector<int> item(n + 1); // 
	vector<vector<PII>> edge(n + 1, vector<PII>());

	for (int i = 1; i <= n; ++i)
		cin >> item[i];

	while (r--) {
		int s, e, l;
		cin >> s >> e >> l;
		edge[s].push_back({e, l});
		edge[e].push_back({s, l});
	}

	int result{};
	for (int i = 1; i <= n; ++i) {
		vector<int> v = dijkstra(edge, i, m);
		int sum{};

		for (auto &i : v)
			sum += item[i];

		result = max(result, sum);
	}

	cout << result;
}