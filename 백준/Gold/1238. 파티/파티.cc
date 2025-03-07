#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
#include <queue>

#define PII pair<int, int>
#define INF (unsigned int)(1 << 31) - 1

using namespace std;

int dijkstra(vector<vector<PII>> &w, int s, int e) { // dajikstra가 아니라 dijkstra였음(..)
    priority_queue<PII, vector<PII>, greater<PII>> pq;
    vector<int> dist(w.size(), INF);

    pq.push({0, s});
    dist[s] = 0;

    while (!pq.empty()) {
        auto [cost, cur] = pq.top();
        pq.pop();

        if (cur == e)
            return cost;

        for (auto &i : w[cur]) {
            auto [_cur, _cost] = i;

            if (dist[_cur] > _cost + cost) {
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

    int n, m, x; // x = 도착지이자 출발지
    cin >> n >> m >> x;
    vector<vector<PII>> way(n + 1);
    
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        way[a].push_back({b, c}); // 총 M개의 단방향 도로들이 있고..
    }

    int result{};
    for (int i = 1; i <= n; ++i)
        result = max(result, dijkstra(way, i, x) + dijkstra(way, x, i));

    cout << result;
}