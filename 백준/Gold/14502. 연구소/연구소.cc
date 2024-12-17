#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
#include <deque>
#include <queue>

using namespace std;

int safe(vector<vector<int>> &map, vector<pair<int, int>> &virus, int wall_count) {
    static const int weight[][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
    deque<deque<bool>> visited(map.size(), deque<bool>(map[0].size(), 0));
    queue<pair<int, int>> waitlist;
    int virus_count{};

    for (auto &i : virus) { // 확산될 바이러스들 좌표 큐에 넣기
        waitlist.push({ i.first, i.second });
        visited[i.second][i.first] = 1, ++virus_count;
    }

    while (!waitlist.empty()) {
        auto top = waitlist.front();
        waitlist.pop();

        for (int i{}; i < 4; ++i) {
            int moved_x = top.first + weight[i][0], moved_y = top.second + weight[i][1];
            if (moved_x >= 0 && moved_x < map[0].size() && moved_y >= 0 && moved_y < map.size()&& !visited[moved_y][moved_x]) {
                visited[moved_y][moved_x] = 1;
                
                if (map[moved_y][moved_x]) // 만약 벽이라면
                    continue;
                
                ++virus_count, visited[moved_y][moved_x] = 1;
                waitlist.push({ moved_x, moved_y });
            }
        }
    }

    return (map.size() * map[0].size()) - virus_count - wall_count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> map(n, vector<int>(m));
    vector<pair<int, int>> virus, empty;
    int wall_count{};

    for (int i{}; i < n; ++i)
        for (int j{}; j < m; ++j) {
            cin >> map[i][j];
            if (!map[i][j])
                empty.push_back({ j, i });
            else if (map[i][j] == 1)
                ++wall_count;
            else
                virus.push_back({ j, i }); // x, y
        }

    int largest{};
    for (int i{}; i < empty.size(); ++i)
        for (int j = i+1; j < empty.size(); ++j)
            for (int k = j+1; k < empty.size(); ++k) { // 벽 3개 조합
                vector<vector<int>> shadow_map = map;
                
                shadow_map[empty[i].second][empty[i].first] = 1
                , shadow_map[empty[j].second][empty[j].first] = 1
                , shadow_map[empty[k].second][empty[k].first] = 1; // 벽은 무조건 3개

                largest = max(largest, safe(shadow_map, virus, wall_count+3));
            }

    cout << largest;
}