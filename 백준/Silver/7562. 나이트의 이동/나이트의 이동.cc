#include <iostream>
#include <utility>
#include <tuple>
#include <deque>
#include <queue>

using namespace std;

int bfs(int &l, pair<int, int> &s, pair<int, int> &e) {
    static int array[8][2] = { {2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2} };
    deque<deque<bool>> visited(l, deque<bool>(l, 0));
    queue<tuple<int, int, int>> waitlist; // y, x, cnt

    visited[s.first][s.second] = 1;
    waitlist.push({s.first, s.second, 0});

    while (1) { // (l이 4 이상인 경우) 언젠가는 무조건 도착할 수 있음
        tuple<int, int, int> top = waitlist.front();
        waitlist.pop();

        if (get<0>(top) == e.first && get<1>(top) == e.second)
            return get<2>(top);

        for (int i{}; i < 8; ++i) {
            int moved_x = get<1>(top) + array[i][1]
                , moved_y = get<0>(top) + array[i][0];
            if (moved_x >= 0 && moved_y >= 0 && moved_x < l && moved_y < l && !visited[moved_y][moved_x]) {
                visited[moved_y][moved_x] = 1;
                waitlist.push({moved_y, moved_x, get<2>(top)+1});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int l;
        cin >> l;

        pair<int, int> s, e;
        cin >> s.first >> s.second >> e.first >> e.second;
        
        cout << bfs(l, s, e) << '\n';
    }
}