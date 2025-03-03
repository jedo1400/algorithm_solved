#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
#include <queue>

#define INF 100000000

using namespace std;

vector<int> dajikstra(vector<vector<pair<int, int>>> &weight, int n, int s) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> waitlist;
    // pq<자료형, 컨테이너, 우선순위> 변수명
    vector<int> dist(n+1, INF);
    
    waitlist.push({s, 0}); // 시작 지점의 비용은 0
    dist[s] = 0;

    while (!waitlist.empty()) {
        int cur = waitlist.top().first
            , cost = waitlist.top().second;

        waitlist.pop();

        if (dist[cur] < cost)
            continue;
        
        for (auto &i : weight[cur]) {
            int c_cur = i.first
                , c_cost = cost + i.second;

            // cout << cur << " -> " << c_cur << " : " << c_cost << '\n';
            
            if (c_cost < dist[c_cur]) {
                waitlist.push({c_cur, c_cost});
                dist[c_cur] = c_cost;
            }
        }

        // cout << '\n';
    }

    return dist;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> weight(n+1);
    
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        weight[a].push_back({b, c});
    }

    int s, e;
    cin >> s >> e;

    vector<int> result = dajikstra(weight, n, s);

    cout << result[e];
}