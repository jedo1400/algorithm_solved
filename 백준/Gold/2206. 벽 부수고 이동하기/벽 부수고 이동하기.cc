#include <iostream>
#include <deque>
#include <queue>
#include <tuple>

using namespace std;

int bfs(deque<deque<bool>> &map) {
    static int w[][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} }; // x, y

    deque<deque<bool>> visited(map.size(), deque<bool>(map[0].size(), 0))
                    , broken_visited(map.size(), deque<bool>(map[0].size(), 0));
    queue<tuple<int, int, int, bool>> waitlist; // x, y, 이동횟수, 벽 부쉈는지

    if (!(map[0].size()-1) && !(map.size()-1)) // 시작점이 도착점과 같은 경우
        return 1;

    waitlist.push({0, 0, 1, 0});
    visited[0][0] = 1;

    while (!waitlist.empty()) {
        auto top = waitlist.front();
        int x = get<0>(top), y = get<1>(top);
        waitlist.pop();

        for (int i = 0; i < 4; ++i) {
            int moved_x = x + w[i][0], moved_y = y + w[i][1];
            if (moved_x == map[0].size()-1 && moved_y == map.size()-1) // 종료조건
                return get<2>(top)+1;

            if (moved_x >= 0 && moved_x < map[0].size() && moved_y >= 0 && moved_y < map.size()) {
                if (get<3>(top)) {
                    if (!broken_visited[moved_y][moved_x] && !map[moved_y][moved_x]) { // 만약 앞이 벽이고 벽을 부숴본 경우
                        waitlist.push({moved_x, moved_y, get<2>(top)+1, 1});
                        broken_visited[moved_y][moved_x] = 1;
                    }
                }
                else if (!visited[moved_y][moved_x]) {
                    if (!map[moved_y][moved_x]) {
                        waitlist.push({moved_x, moved_y, get<2>(top)+1, 0});
                        visited[moved_y][moved_x] = 1;
                    }
                    else {
                        waitlist.push({moved_x, moved_y, get<2>(top)+1, 1});
                        broken_visited[moved_y][moved_x] = 1;
                    }
                }
            }
        }
    }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    deque<deque<bool> > map(n, deque<bool>(m));

    for (auto &i : map)
        for (auto &j : i) {
            char input;
            cin >> input;
            j = input-48;
        }

    cout << bfs(map);
}