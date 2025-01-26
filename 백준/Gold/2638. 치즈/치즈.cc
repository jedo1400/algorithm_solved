#include <iostream>
#include <utility>
#include <vector>
#include <deque>
#include <queue>

using namespace std;

deque<deque<bool>> markAir(vector<vector<int>> &map) {
    static int weight[][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
    deque<deque<bool>> visited(map.size(), deque<bool>(map[0].size(), 0));
    queue<pair<int, int>> waitlist;

    waitlist.push({0, 0});
    visited[0][0] = 1;

    while (!waitlist.empty()) {
        auto [x, y] = waitlist.front();
        waitlist.pop();

        for (int i{}; i < 4; ++i) {
            int mx = x + weight[i][0], my = y + weight[i][1];
            if (mx >= 0 && mx < map[0].size() && my >= 0 && my < map.size() && !visited[my][mx] && !map[my][mx]) {
                waitlist.push({mx, my});
                visited[my][mx] = 1;
            }
        }
    }

    return visited;
}

int simulation(vector<vector<int>> &map, int cheese_count) {
    static int weight[][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
    int time{};
    queue<pair<int, int>> melt;
    deque<deque<bool>> air;

    while (cheese_count) {
        // 0 = 실내공기, 1 = 치즈
        air = markAir(map);

        for (int i = 1; i < map.size()-1; ++i)
            for (int j = 1; j < map[0].size()-1; ++j)
                if (map[i][j]) {
                    int air_side{};
                    
                    for (int k{}; k < 4; ++k)
                        if (air[i + weight[k][1]][j + weight[k][0]])
                            ++air_side;
                    
                    if (air_side >= 2)
                        melt.push({j, i});
                }

        while (!melt.empty()) {
            auto top = melt.front();
            map[top.second][top.first] = 0, --cheese_count;
            melt.pop();
        }

        ++time;
    }

    return time;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> map(n, vector<int>(m));
    int cheese_count{};

    for (auto &i : map)
        for (auto &j : i) {
            cin >> j;
            if (j) ++cheese_count;
        }

    cout << simulation(map, cheese_count);
}