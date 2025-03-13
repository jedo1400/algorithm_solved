#include <iostream>
#include <utility>
#include <vector>
#include <queue>

#define PII pair<int, int>
#define INF (unsigned int)(1 << 31) - 1

using namespace std;

void dijikstra(vector<vector<PII>> &w, vector<int> &dist, int s) {
	priority_queue<PII, vector<PII>, greater<PII>> pq; // {cost, cur}
	
	pq.push({0, s});
	dist[s] = 0;
	
	while (!pq.empty()) {
		auto [cost, cur] = pq.top();
        pq.pop();
			
		for (auto &i : w[cur]) {
			auto [_cur, _cost] = i;

			if (_cost + cost < dist[_cur]) {
                dist[_cur] = _cost + cost;
                pq.push({dist[_cur], _cur});
            }
		}
	}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	int v, e, k;
	cin >> v >> e >> k;
	vector<vector<PII>> way(v+1);
	
	while (e--) {
		int a, b, c;
		cin >> a >> b >> c;
		way[a].push_back({b, c});
	}

    vector<int> dist(way.size(), INF);
    dijikstra(way, dist, k);
	
	for (int i = 1; i <= v; ++i) {
        if (dist[i] == INF)
            cout << "INF";
        else
            cout << dist[i];
        cout << '\n';
    }
}