#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;

    vector<vector<int>> map(n, vector<int>(n)), result(n, vector<int>(n, 0));

    for (auto &i : map)
        for (auto &j : i) {
            char c;
            cin >> c;
            j = c == '.' ? 0 : c-48;
        }

    for (int i{}; i < n; ++i)
        for (int j{}; j < n; ++j) {
            static int weight[8][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1} };
            if (map[i][j])
                result[i][j] = -2; // 지뢰
            else // 지뢰 아닌경우
                for (int k{}; k < 8; ++k) {
                    int moved_x = j + weight[k][0], moved_y = i + weight[k][1];
                    if (moved_x >= 0 && moved_x < n && moved_y >= 0 && moved_y < n) {
                        if (result[i][j] + map[moved_y][moved_x] > 9)
                            result[i][j] = -1;
                        else if (result[i][j] >= 0)
                            result[i][j] += map[moved_y][moved_x];
                    }
                }
        }
    
    for (auto &i : result) {
        for (auto &j : i) {
            if (j == -1)
                cout << 'M';
            else if (j == -2)
                cout << '*';
            else
                cout << j;
        }
        cout << '\n';
    }
}