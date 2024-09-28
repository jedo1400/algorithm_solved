#include <algorithm>
#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int dfs(vector<vector<short>> &array, short n = 1) {
    static deque<bool> visited(array.size(), 0);
    static int result{};
    visited[n] = 1;
    
    for (auto &i : array[n])
        if (!visited[i]) {
            dfs(array, i);
            ++result;
        }
    
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    short n, m; // n = 컴퓨터 수, m = 간선 수
    cin >> n >> m;
    vector<vector<short>> array(n+1, vector<short>());
    for (short i = 0; i < m; ++i) {
        short a, b;
        cin >> a >> b;
        array[a].push_back(b);
        array[b].push_back(a);
    }

    for (auto &i : array)
        sort(i.begin(), i.end());

    cout << dfs(array);
}
