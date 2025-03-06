#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
#include <tuple>
#include <queue>

#define PAIR pair<int, int>
#define TUPLE tuple<int, int, int>
#define INF (unsigned int)(1 << 31) - 1

using namespace std;

// 최소비용, 최소비용 같은 경로의 수
int dajikstra(vector<vector<PAIR>> &w, vector<int> &history, int s, int e) {
    // 가격, 정점
    priority_queue<PAIR, vector<PAIR>, greater<PAIR>> pq;
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
            
            if (_cost + cost < dist[_cur]) {
                dist[_cur] = _cost + cost
                , history[_cur] = cur;
                pq.push({dist[_cur], _cur});
            }
        }
    }

    return -1;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<PAIR>> way(n+1);

    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        way[a].push_back({b, c});
    }

    int s, e;
    cin >> s >> e;

    // 비용, 이전 정점
    vector<int> history(n+1, 0);
    int dist = dajikstra(way, history, s, e);

    cout << dist << '\n';

    vector<int> move;
    
    int ptr = e;
    while (history[ptr])
        move.push_back(ptr = history[ptr]);

    cout << move.size() + 1 << '\n';

    for (int i = move.size() - 1; i >= 0; --i)
        cout << move[i] << ' ';
    cout << e;
}