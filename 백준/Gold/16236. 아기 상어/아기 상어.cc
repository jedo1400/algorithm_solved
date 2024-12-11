#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
#include <tuple>
#include <deque>
#include <queue>

using namespace std;

int getDistance(vector<vector<int>> &map, int x1, int y1, int x2, int y2, int ate, int size) {
    static int w[][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} }; // x, y

    queue<tuple<int, int, int>> waitlist;
    deque<deque<bool>> visited(map.size(), deque<bool>(map.size(), 0));

    waitlist.push({x1, y1, 0});
    visited[y1][x1] = 1;

    while (!waitlist.empty()) {
        auto top = waitlist.front();
        int x = get<0>(top), y = get<1>(top);

        if (x == x2 && y == y2) // 도착지에 도착하면
            return get<2>(top); // 거리, 아기 상어가 먹은 물고기의 수, 아기 상어의 크기 반환

        waitlist.pop();

        for (int i{}; i < 4; ++i) {
            int moved_x = x+w[i][0], moved_y = y+w[i][1];
            if (moved_x >= 0 && moved_x < map.size() && moved_y >= 0 && moved_y < map.size()
                && !visited[moved_y][moved_x] && map[moved_y][moved_x] <= size) {
                visited[moved_y][moved_x] = 1;

                waitlist.push({moved_x, moved_y, get<2>(top)+1});
            }
        }
    }

    return 0;
}

bool cmp(pair<int, int> &a, pair<int, int> &b) {
    if (a.second < b.second)
        return 1;
    if (a.second == b.second && a.first < b.first)
        return 1;
    return 0;
}

int eat(vector<vector<int>> &map, vector<vector<pair<int, int>>> &fish, int &x, int &y, int &ate, int &size) {
    static int w[][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} }; // x, y
    static deque<deque<bool>> visited(map.size(), deque<bool>(map.size(), 0));

    vector<pair<int, int>> eatable_fish; // x, y
    for (int i = 1; i < (size >= 7 ? 7 : size); ++i)
        for (auto &j : fish[i])
            if (!visited[j.second][j.first] && map[j.second][j.first]) // 아직 먹지않은 물고기라면
                eatable_fish.push_back({j.first, j.second});
    
    sort(eatable_fish.begin(), eatable_fish.end(), cmp); // 먹을 수 있는 물고기들이 위치한 좌표를 조건 4에 맞게 정렬

    tuple<int, int, int> nearest = {999, ate, size};
    int visit_x, visit_y;

    for (auto &i : eatable_fish) {
        int dist = getDistance(map, x, y, i.first, i.second, ate, size);
        if (dist && dist < get<0>(nearest))
            get<0>(nearest) = dist, visit_x = i.first, visit_y = i.second;
    }

    if (get<0>(nearest) != 999) {
        if (++get<1>(nearest) == get<2>(nearest)) // 물고기 먹고 크기 커졌는지 확인
            get<1>(nearest) = 0, ++get<2>(nearest);

        visited[visit_y][visit_x] = 1, map[visit_y][visit_x] = 0
        , x = visit_x, y = visit_y, ate = get<1>(nearest), size = get<2>(nearest);
        return get<0>(nearest);
    }

    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int x, y, ate = 0, size = 2;
    vector<vector<int>> map(n, vector<int>(n));
    vector<vector<pair<int, int>>> fish(7);

    for (int i{}; i < n; ++i)
        for (int j{}; j < n; ++j) {
            cin >> map[i][j];
            if (map[i][j] == 9) // 아기상어 위치
                x = j, y = i, map[i][j] = 0; // 좌표만 저장하고 지도에는 빈 칸으로 기록
            else if (map[i][j]) // 생선들 위치
                fish[map[i][j]].push_back({j, i});
        }

    int result{}, time;
    while (time = eat(map, fish, x, y, ate, size))
        result += time;

    cout << result;
}