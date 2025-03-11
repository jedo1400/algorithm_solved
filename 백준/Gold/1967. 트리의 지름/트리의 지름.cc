#include <algorithm>
#include <iostream>
#include <cstring>
#include <utility>
#include <vector>

#define PII pair<int, int>
#define MAX 10000

using namespace std;

pair<int, int> dfs(vector<vector<PII>> &tree, int dist[], int n, int before = 0) {
    static int which, farthest{};

    for (auto &i : tree[n]) {
        auto [to, weight] = i;
        if (dist[to] == -1) {
            dist[to] = weight + before;

            if (dist[to] > farthest)
                which = to, farthest = dist[to];

            dfs(tree, dist, to, dist[to]);
        }
    }

    return {which, farthest};
}

int solve(vector<vector<PII>> &tree) {
    int dist[MAX+1]; // 루트 노드(1) -> 가장 먼 노드 길이 구하기
    memset(dist, -1, sizeof(int)*(MAX+1)); // 간선의 가중치는 100보다 크지 않은 양의 정수이다.
    dist[1] = 0;
    int start = dfs(tree, dist, 1).first; // 루트 노드 -> 루트 노드에서 가장 먼 노드 구하기

    memset(dist, -1, sizeof(int)*(MAX+1)); // 초기화
    dist[start] = 0;
    return dfs(tree, dist, start).second; // 루트 노드에서 가장 먼 노드 -> 그에서 가장 먼 노드의 거리(트리의 지름) 구하기
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<vector<PII>> tree(MAX+1);

    while (--n) { // 루트 노드 -1
        int a, b, c;
        cin >> a >> b >> c;
        // 사이클이 없는 무방향 그래프이다.
        tree[a].push_back({b, c})
        , tree[b].push_back({a, c});
    }

    cout << solve(tree);
}