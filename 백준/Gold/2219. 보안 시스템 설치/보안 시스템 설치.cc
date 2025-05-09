#include <algorithm>
#include <iostream>
#include <utility>

using namespace std;

#define INF 1e9

int n, m;
vector<vector<int>> dist;

int floyd() {
    for (int m = 1; m <= n; ++m)
        for (int s = 1; s <= n; ++s)
            for (int e = 1; e <= n; ++e)
                dist[s][e] = min(dist[s][e], dist[s][m] + dist[m][e]);
    
    int r, v = INF;
    for (int i = 1; i <= n; ++i) {
        int sum = 0;

        for (int j = 1; j <= n; ++j)
            sum += dist[i][j];
        
        if (v > sum)
            r = i, v = sum;
    }

    return r;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    dist = vector<vector<int>>(n+1, vector<int>(n+1, INF));

    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        dist[a][b] = min(dist[a][b], c);
        dist[b][a] = min(dist[b][a], c); // 문제에 임의의 두 컴퓨터에 직접 연결된 회선이 여러개인지에 대한 언급이 없음
    }

    cout << floyd();
}