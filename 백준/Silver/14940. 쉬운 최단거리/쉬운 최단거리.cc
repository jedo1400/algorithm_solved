#include <iostream>
#include <utility>
#include <queue>
#include <deque>

using namespace std;

short direction[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };

auto markWall(deque<deque<short>> &array) {
    deque<deque<bool>> result(array.size(), deque<bool>(array[0].size(), 0));

    for (short i = 0; i < array.size(); ++i)
        for (short j = 0; j < array[0].size(); ++j)
            if (!array[i][j])
                result[i][j] = 1;
    
    return result;
}

deque<deque<int>> bfs(deque<deque<short>> &array, short x, short y) {
    deque<deque<int>> result(array.size(), deque<int>(array[0].size(), 0));
    queue<pair<short, short>> waitlist;
    auto visited = markWall(array);

    waitlist.push(make_pair(x, y));
    visited[y][x] = 1;

    while (!waitlist.empty()) {
        pair<short, short> top = waitlist.front();
        waitlist.pop();

        for (short i = 0; i < 4; ++i) {
            short x_moved = top.first + direction[i][0]
                , y_moved = top.second + direction[i][1];
            
            if (x_moved >= 0 && x_moved < array[0].size()
             && y_moved >= 0 && y_moved < array.size()
             && !visited[y_moved][x_moved]) {
                result[y_moved][x_moved] = result[top.second][top.first] + 1;
                visited[y_moved][x_moved] = 1;
                waitlist.push(make_pair(x_moved, y_moved));
            }
        }
    }

    for (short i = 0; i < result.size(); ++i)
        for (short j = 0; j < result[0].size(); ++j)
            if (array[i][j] == 1 && !result[i][j]) // 만약 갈 수 있는 곳인데도 방문하지 않은 경우
                result[i][j] = -1;
    
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    short n, m, x, y; // 출발점
    cin >> n >> m;
    deque<deque<short>> array(n, deque<short>(m));
    
    for (short i = 0; i < n; ++i)
        for (short j = 0; j < m; ++j) {
            cin >> array[i][j];
            if (array[i][j] == 2) // 출발점 지정
                x = j, y = i;
        }
    
    auto result = bfs(array, x, y);
    for (auto &i : result) {
        for (auto &j : i)
            cout << j << ' ';
        cout << '\n';
    }
}