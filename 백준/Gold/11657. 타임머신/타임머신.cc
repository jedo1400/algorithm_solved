#include <algorithm>
#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

#define INF 1e11
#define LL long long
#define TLLL tuple<LL, LL, LL>

int n, m;
vector<TLLL> v;

void bellman_ford() {
    vector<LL> dist(n+1, INF);

    dist[1] = 0;

    for (int i = 0; i < n; ++i)
        for (auto &[s, e, t] : v)
            if (dist[s] != INF && dist[e] > dist[s] + t)
                dist[e] = dist[s] + t;
    
    for (auto &[s, e, t] : v)
        if (dist[e] != INF && dist[e] > dist[s] + t) {
            cout << -1;
            return;
        }
    
    for (int i = 2; i <= n; ++i)
        cout << (dist[i] == INF ? -1 : dist[i]) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    v.resize(m);

    for (auto &[a, b, c] : v)
        cin >> a >> b >> c;

    bellman_ford();
}