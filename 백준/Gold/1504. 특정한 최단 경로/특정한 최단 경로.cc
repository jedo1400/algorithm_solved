#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
#include <queue>

#define PAIR pair<int, int>
#define INF (unsigned int)(1 << 31) - 1

using namespace std;

int dajikstra(vector<vector<PAIR>> &w, int s, int e) {
    // {거리, 정점}
    priority_queue<PAIR, vector<PAIR>, greater<PAIR>> pq;
    vector<int> dist(w.size() + 1, INF);

    pq.push({0, s});
    dist[s] = 0;

    while (!pq.empty()) {
        auto [cost, cur] = pq.top();
        pq.pop();

        if (cur == e) // 현재 정점이 도착지인 경우
            return dist[e];
        
        for (auto &i : w[cur]) {
            auto [_cur, _cost] = i;

            if (_cost + cost < dist[_cur]) {
                dist[_cur] = _cost + cost;
                pq.push({dist[_cur], _cur});
            }
        }
    }

    return -1;
}

int solve(vector<vector<PAIR>> &w, initializer_list<int> p) {
    int cost_before{}, s{};

    for (auto &i : p) {
        if (!s) // 초기화 안돼있으면
            s = i;
        else {
            int cost = dajikstra(w, s, i);

            if (cost == -1) // 그런 경로가 없다면
                return -1;

            cost_before += dajikstra(w, s, i)
            , s = i;
        }
    }

    return cost_before;
}

int main() {
    int n, e;
    cin >> n >> e;
    vector<vector<PAIR>> way(n+1);

    while (e--) {
        int a, b, c;
        cin >> a >> b >> c;
        // a번 정점에서 b번 정점까지 양방향 길이 존재
        way[a].push_back({b, c});
        way[b].push_back({a, c});
    }

    int v1, v2;
    cin >> v1 >> v2;

    cout << min(solve(way, {1, v1, v2, n}), solve(way, {1, v2, v1, n}));
}