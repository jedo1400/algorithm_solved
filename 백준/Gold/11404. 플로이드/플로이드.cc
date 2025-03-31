#include <iostream>
#include <vector>

using namespace std;

#define INF (unsigned int)((1 << 31) - 1) / 2

void floyd_warshall(vector<vector<int>> &dist) {
	for (int m = 1; m < dist.size(); ++m)
		for (int s = 1; s < dist.size(); ++s)
			for (int e = 1; e < dist.size(); ++e)
				dist[s][e] = min(dist[s][e], dist[s][m] + dist[m][e]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> dist(n+1, vector<int>(n+1, INF));

	for (int i = 0; i <= n; ++i)
		dist[i][i] = 0;

	while (m--) {
		int s, e, d;
		cin >> s >> e >> d;
		dist[s][e] = min(dist[s][e], d);
	}

	floyd_warshall(dist);

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j)
			cout << (dist[i][j] == INF ? 0 : dist[i][j]) << ' ';
		cout << '\n';
	}
}