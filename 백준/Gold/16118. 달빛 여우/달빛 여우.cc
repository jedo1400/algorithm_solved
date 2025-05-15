#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

#define INF 1e9
#define PII pair<int, int>
#define TIII tuple<int, int, int>

vector<vector<PII>> v;

vector<int> dijkstra(int e) {
    priority_queue<PII, vector<PII>, greater<PII>> pq;
    vector<int> dist(v.size(), INF);

    pq.push({0, 1});
    dist[1] = 0;

    while (!pq.empty()) {
        auto [t, c] = pq.top();
        pq.pop();

        if (t > dist[c])
            continue;

        for (auto &i : v[c]) {
            auto [_c, _t] = i;

            int nt = dist[c] + _t * 2;
            if (dist[_c] > nt) {
                dist[_c] = nt;
                pq.push({nt, _c});
            }
        }
    }

    return dist;
}

vector<int> dijkstra_wolf(int e) {
    priority_queue<TIII, vector<TIII>, greater<TIII>> pq;
    vector<vector<int>> dist(v.size(), vector<int>(2, INF));

    pq.push({0, 1, 0});
    dist[1][0] = 0;

    while (!pq.empty()) {
        auto [t, c, w] = pq.top();
        pq.pop();

        if (t > dist[c][w])
            continue;

        for (auto &i : v[c]) {
            auto [_c, _t] = i;

            int nt = t + (w ? _t * 4 : _t)
                , nw = !w;

            if (dist[_c][nw] > nt) {
                dist[_c][nw] = nt;
                pq.push({nt, _c, nw});
            }
        }
    }

    vector<int> _dist(v.size());
    for (int i = 1; i < v.size(); ++i)
        _dist[i] = min(dist[i][0], dist[i][1]);

    return _dist;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    v = vector<vector<PII>>(n+1, vector<PII>());

    while (m--) {
        int a, b, d;
        cin >> a >> b >> d;
        v[a].push_back({b, d});
        v[b].push_back({a, d});
    }

    vector<int> fox = dijkstra(4)
                , wolf = dijkstra_wolf(4);

    int result = 0;
    for (int i = 1; i <= n; ++i)
        if (fox[i] < wolf[i])
            ++result;

    cout << result;
}