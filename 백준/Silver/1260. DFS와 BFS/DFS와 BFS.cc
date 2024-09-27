#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void dfs(vector<vector<short>> &array, int n) {
    static bool visited[1001]{0,};
    visited[n] = 1;
    cout << n << ' ';

    for (auto &i : array[n])
        if (!visited[i])
            dfs(array, i);
}

void bfs(vector<vector<short>> &array, int n) {
    static bool visited[1001]{0,};
    queue<short> waitlist;
    visited[n] = 1;
    waitlist.push(n);

    while (!waitlist.empty()) {
        short cur = waitlist.front();
        waitlist.pop();
        cout << cur << ' ';
        for (auto &i : array[cur]) {
            if (!visited[i]) {
                waitlist.push(i);
                visited[i] = 1;
            } 
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    short n, m, v;
    cin >> n >> m >> v;
    vector<vector<short>> array(n+1, vector<short>());
    
    for (short i = 0; i < m; ++i) {
        short a, b;
        cin >> a >> b;
        array[a].push_back(b);
        array[b].push_back(a);
    }
    
    for (auto &i : array)
        sort(i.begin(), i.end());

    dfs(array, v);
    cout << '\n';
    bfs(array, v);
}
