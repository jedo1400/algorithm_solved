#include <iostream>
#include <utility>
#include <deque>
#include <queue>

using namespace std;

int findShortestPath(deque<deque<bool>> &array, short x, short y) {
    static short d[4][2] = { {0, 1}, {0, -1}, {-1, 0}, {1, 0} };
    deque<deque<bool>> visited(array.size(), deque<bool>(array[0].size(), 0));
    deque<deque<short>> distance(array.size(), deque<short>(array[0].size(), 0));
    queue<pair<short, short>> waitlist;

    waitlist.push(make_pair(x, y));
    
    while (!waitlist.empty()) {
        short x = waitlist.front().first
            , y = waitlist.front().second;

        waitlist.pop();

        for (short i = 0; i < 4; ++i) {
            short moved_x = x + d[i][1], moved_y = y + d[i][0];
        
            if (moved_y >= 1 && moved_y < array.size()
            && moved_x >= 1 && moved_x < array[0].size()
            && !visited[moved_y][moved_x] && array[moved_y][moved_x]) {
                distance[moved_y][moved_x] = distance[y][x] + 1
                , visited[moved_y][moved_x] = 1;
                waitlist.push(make_pair(moved_x, moved_y));
            }
        }
    }

    return distance[array.size()-1][array[0].size()-1] + 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    short n, m;
    cin >> n >> m;
    deque<deque<bool>> array(n+1, deque<bool>(m+1, 0));

    for (short i = 1; i <= n; ++i)
        for (short j = 1; j <= m; ++j) {
            char tmp;
            cin >> tmp;
            array[i][j] = tmp-48;
        }
    
    cout << findShortestPath(array, 1, 1);
}