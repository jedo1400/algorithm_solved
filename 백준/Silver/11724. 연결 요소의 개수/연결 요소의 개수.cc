#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<short>> &arr, vector<short> &visited, short n) {
    visited[n] = 1;
    
    for (auto &i : arr[n])
        if (!visited[i])
            dfs(arr, visited, i);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    short n, cnt{};
    int m;
    cin >> n >> m;

    vector<vector<short>> connection(n+1, vector<short>());
    vector<short> visited(n+1, 0);

    while (m--) {
        short u, v;
        cin >> u >> v;
        connection[u].push_back(v);
        connection[v].push_back(u); // 방향성이 없는 행렬***
    }

    for (short i = 1; i <= n; ++i)
        if (!visited[i]) {
            dfs(connection, visited, i);
            ++cnt;
        }

    cout << cnt;
}