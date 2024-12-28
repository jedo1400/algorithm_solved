#include <iostream>
#include <limits.h>
#include <utility>
#include <vector>
#include <deque>
#include <queue>

using namespace std;

int getDistance(vector<vector<int>> &con, int a, int b) { // a to b
    if (a == b)
        return 0;

    deque<bool> visited(con.size(), 0);
    queue<pair<int, int>> waitlist; // 친구, 거리

    waitlist.push({a, 0});

    while (!waitlist.empty()) {
        auto top = waitlist.front();
        waitlist.pop();

        if (top.first == b)
            return top.second;

        for (auto &i : con[top.first])
            if (!visited[i]) {
                waitlist.push({i, top.second + 1});
                visited[i] = 1;
            }
    }

    return -1; // 친구가 한 명도 없는 경우는 없음
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m;
    cin >> n >> m;

    vector<vector<int>> con(n+1, vector<int>()), bacon(n+1, vector<int>(n+1, 0));

    while (m--) {
        int a, b;
        cin >> a >> b;
        con[a].push_back(b);
        con[b].push_back(a);
    }

    for (int i = 1; i <= n; ++i)
        for (int j = i+1; j <= n; ++j) {
            bacon[i][j] = getDistance(con, i, j)
            , bacon[j][i] = bacon[i][j];
        }

    int result, cnt = INT_MAX;
    for (int i = 1; i <= n; ++i) {
        int sum{};
        
        for (int j = 1; j <= n; ++j)
            sum += bacon[i][j];
        
        if (cnt > sum)
            result = i, cnt = sum;
    }

    cout << result;
}