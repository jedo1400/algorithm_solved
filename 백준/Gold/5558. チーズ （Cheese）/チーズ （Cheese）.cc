#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
#include <deque>
#include <queue>
#include <tuple>

using namespace std;

int bfs(vector<vector<char>> &map, int x1, int y1, int x2, int y2) {
    static int weight[][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
    deque<deque<bool>> visited(map.size(), deque<bool>(map[0].size(), 0));
    queue<tuple<int, int, int>> waitlist; // x, y, time

    waitlist.push({x1, y1, 0});
    visited[y1][x1] = 1;

    while (!waitlist.empty()) {
        auto top = waitlist.front();
        waitlist.pop();

        if (get<0>(top) == x2 && get<1>(top) == y2) // 목적지(치즈가 있는 위치)에 도착하면
            return get<2>(top);

        for (int i{}; i < 4; ++i) {
            int moved_x = weight[i][0] + get<0>(top), moved_y = weight[i][1] + get<1>(top);

            if (moved_x >= 0 && moved_x < map[0].size() && moved_y >= 0 && moved_y < map.size()
                && !visited[moved_y][moved_x] && map[moved_y][moved_x] != 'X') {
                waitlist.push({moved_x, moved_y, get<2>(top)+1});
                visited[moved_y][moved_x] = 1;
            }
        }
    }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int h, w, n;
    cin >> h >> w >> n;
    vector<vector<char>> map(h, vector<char>(w));
    vector<tuple<int, int, int>> cheese;

    int sx, sy; // 시작 위치
    for (int i{}; i < h; ++i)
        for (int j{}; j < w; ++j) {
            cin >> map[i][j];
            if (map[i][j] == 'S')
                sx = j, sy = i;
            if (map[i][j] >= '1' && map[i][j] <= '9')
                cheese.push_back({map[i][j]-48, j, i}); // 경도, x, y
        }

    sort(cheese.begin(), cheese.end(),
        [](tuple<int, int, int> &a, tuple<int, int, int> &b) -> bool {
            return get<0>(a) < get<0>(b);
        });

    int result{};
    for (auto &i : cheese) {
        result += bfs(map, sx, sy, get<1>(i), get<2>(i));
        sx = get<1>(i), sy = get<2>(i);
    }

    cout << result;
}