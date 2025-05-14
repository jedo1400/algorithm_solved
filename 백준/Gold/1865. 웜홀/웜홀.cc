#include <algorithm>
#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

#define TIII tuple<int, int, int>
#define INF 1e9

int n, m, w;

bool bellman_ford(vector<TIII> &v) {
    vector<int> dist(n+1, INF);

    dist[1] = 0; 

    for (int i = 0; i < n; ++i)
        for (auto &[s, e, t] : v)
            if (dist[e] > dist[s] + t)
                dist[e] = dist[s] + t;

    for (auto &[s, e, t] : v) // 계속해서 최단거리가 갱신되는 곳이 있는지 확인 (음수 사이클 존재 확인)
        if (dist[e] > dist[s] + t)
            return 1;

    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 벨만-포드 알고리즘을 사용하여 그래프에 음수 순환 사이클이 존재하는지 판별할 수 있는가?

    int t;
    cin >> t;
    
    while (t--) {
        cin >> n >> m >> w;
        vector<TIII> con;

        while (m--) { // 도로는 방향이 없으며 웜홀은 방향이 있다
            int s, e, t;
            cin >> s >> e >> t;
            con.emplace_back(s, e, t);
            con.emplace_back(e, s, t);
        }

        while (w--) {
            int s, e, t;
            cin >> s >> e >> t;
            con.emplace_back(s, e, -t);
        }

        cout << (bellman_ford(con) ? "YES" : "NO") << '\n';
    }
}