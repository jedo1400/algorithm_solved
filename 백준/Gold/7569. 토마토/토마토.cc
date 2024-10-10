#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <tuple>

using namespace std;

int bfs(vector<vector<vector<short>>> &tomato, deque<deque<deque<bool>>> &visited, queue<tuple<short, short, short>> &waitlist) {
    vector<tuple<short, short, short>> direction(6);
    direction = { make_tuple(0, 0, -1) // 위
                , make_tuple(0, 0, 1) // 아래
                , make_tuple(-1, 0, 0) // 좌
                , make_tuple(1, 0, 0) // 우
                , make_tuple(0, -1, 0) // 상
                , make_tuple(0, 1, 0) }; // 하

    int result{};
    short m = tomato[0][0].size(), n = tomato[0].size(), h = tomato.size();
    queue<tuple<short, short, short>> next_waitlist;

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
                short mx = get<0>(top) + get<0>(i), my = get<1>(top) + get<1>(i), mh = get<2>(top) + get<2>(i);
                if (mx >= 0 && mx < m && my >= 0 && my < n && mh >= 0 && mh < h && !visited[mh][my][mx])
                    tomato[mh][my][mx] = 1, visited[mh][my][mx] = 1, next_waitlist.push(make_tuple(mx, my, mh));
            }
        }
        ++result;
    }

    for (auto &i : visited)
        for (auto &j : i) 
            for (auto &k : j)
                if (!k)
                    return -1; 
    return result-1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    short m, n, h; // 가로, 세로, 높이
    cin >> m >> n >> h;
    vector<vector<vector<short>>> tomato(h, vector<vector<short>>(n, vector<short>(m)));
    deque<deque<deque<bool>>> visited(h, deque<deque<bool>>(n, deque<bool>(m, 0)));
    queue<tuple<short, short, short>> waitlist;

    for (short i = 0; i < h; ++i)
        for (short j = 0; j < n; ++j)
            for (short k = 0; k < m; ++k) {
                cin >> tomato[i][j][k];
                if (tomato[i][j][k] == 1) {
                    visited[i][j][k] = 1;
                    waitlist.push(make_tuple(k, j, i));
                }
                if (tomato[i][j][k] == -1)
                    visited[i][j][k] = 1;
            }

    cout << bfs(tomato, visited, waitlist);
}