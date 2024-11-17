#include <iostream>
#include <utility>
#include <vector>
#include <deque>

using namespace std;

// 백트래킹
void dfs(vector<vector<char>> &board, vector<pair<int, int>> &O, vector<pair<int, int>> &T, bool &flag, int cnt = 0, int start = 0) {
    static int weight[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
    static deque<bool> visited(O.size(), 0);
    static vector<int> array(3, 0);

    if (cnt == 3) {
        vector<vector<char>> copy = board;
        for (auto &i : array) // i = 좌표
            copy[O[i].first][O[i].second] = 'O';
        
        bool met = 0;
        for (auto &i : T)
            for (int k{}; k < 4; ++k) {
                int moved_x = i.second+weight[k][1], moved_y = i.first+weight[k][0];

                while (moved_x >= 0 && moved_y >= 0 && moved_x < board.size() && moved_y < board.size()) {
                    if (copy[moved_y][moved_x] != 'X') {
                        if (copy[moved_y][moved_x] == 'S')
                            met = 1;
                        break;
                    }
                    moved_x += weight[k][1], moved_y += weight[k][0];
                }
            }

        if (!met) flag = 1;
        return;
    }

    for (int i = start; i < O.size(); ++i)
        if (!visited[i]) {
            visited[i] = 1;
            array[cnt] = i;
            dfs(board, O, T, flag, cnt+1, i+1);
            visited[i] = 0;
        }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<vector<char>> board(n, vector<char>(n));

    int weight[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };

    vector<pair<int, int>> Os, Ts;

    for (auto &i : board)
        for (auto &j : i)
            cin >> j;

    for (int i{}; i < n; ++i) // 미리 조합해야하는 경로들 찾아두기
        for (int j{}; j < n; ++j)
            if (board[i][j] == 'T') {
                Ts.push_back({ i, j });
                for (int k{}; k < 4; ++k) {
                    int moved_x = j+weight[k][1], moved_y = i+weight[k][0];

                    while (moved_x >= 0 && moved_y >= 0 && moved_x < n && moved_y < n) {
                        if (board[moved_y][moved_x] != 'X')
                            break;
                        Os.push_back({ moved_y, moved_x });
                        moved_x += weight[k][1], moved_y += weight[k][0];
                    }
                }
            }

    bool flag{};
    dfs(board, Os, Ts, flag);
    cout << (flag ? "YES" : "NO");
}