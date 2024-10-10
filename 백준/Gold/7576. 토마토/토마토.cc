#include <iostream>
#include <utility>
#include <vector>
#include <deque>
#include <queue>

using namespace std;

int bfs(vector<vector<short>> &tomato, deque<deque<bool>> &visited, queue<pair<short, short>> &waitlist) {
    vector<pair<short, short>> direction(4);
    direction = { make_pair(-1, 0) // 좌
                , make_pair(1, 0) // 우
                , make_pair(0, -1) // 상
                , make_pair(0, 1) }; // 하

    int result{};
    short m = tomato[0].size(), n = tomato.size();
    queue<pair<short, short>> next_waitlist;

    while (1) {
        while (!next_waitlist.empty()) {
            waitlist.push(next_waitlist.front());
            next_waitlist.pop();
        }

        if (waitlist.empty())
            break;
        
        while (!waitlist.empty()) {
            auto top = waitlist.front();
            waitlist.pop();

            for (auto &i : direction) {
                short mx = top.first + i.first, my = top.second + i.second;
                if (mx >= 0 && mx < m && my >= 0 && my < n && !visited[my][mx])
                    tomato[my][mx] = 1, visited[my][mx] = 1, next_waitlist.push(make_pair(mx, my));
            }
        }
        ++result;
    }

    for (auto &i : visited)
        for (auto &j : i) 
            if (!j)
                return -1; 
    return result-1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    short m, n; // 가로, 세로, 높이
    cin >> m >> n;
    vector<vector<short>> tomato(n, vector<short>(m));
    deque<deque<bool>> visited(n, deque<bool>(m, 0));
    queue<pair<short, short>> waitlist;

    for (short i = 0; i < n; ++i)
        for (short j = 0; j < m; ++j) {
            cin >> tomato[i][j];
            if (tomato[i][j] == 1) {
                visited[i][j] = 1;
                waitlist.push(make_pair(j, i));
            }
            if (tomato[i][j] == -1)
                visited[i][j] = 1;
        }

    cout << bfs(tomato, visited, waitlist);
}