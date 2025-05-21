#include <iostream>
#include <vector>

using namespace std;

#define PII pair<int, int>

vector<vector<char>> v(5, vector<char>(9));
int rp, rm;

void backtrack(int pin, int move = 0) {
    static int w[][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} }; 
    bool moved = 0;

    for (int y = 0; y < 5; ++y)
        for (int x = 0; x < 9; ++x) {
            if (v[y][x] != 'o')
                continue;

            for (int j = 0; j < 4; ++j) {
                int nx = x + w[j][0]
                    , ny = y + w[j][1]
                    , mx = x + w[j][0] * 2
                    , my = y + w[j][1] * 2;

                if (mx < 0 || mx >= 9 || my < 0 || my >= 5)
                    continue;
                
                if (v[ny][nx] == 'o' && v[my][mx] == '.') {
                    v[y][x] = '.'
                    , v[ny][nx] = '.'
                    , v[my][mx] = 'o';

                    backtrack(pin-1, move+1);

                    v[y][x] = 'o'
                    , v[ny][nx] = 'o'
                    , v[my][mx] = '.';

                    moved = 1;
                }
            }
        }

    if (!moved) // 더 이상 움직일 수 있는 핀이 없다면
        if (rp > pin || (rp == pin && rm > move))
            rp = pin, rm = move;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int cnt = 0;
        rp = 1e9, rm = 1e9;

        for (auto &i : v)
            for (auto &j : i) {
                cin >> j;

                if (j == 'o')
                    ++cnt;
            }

        backtrack(cnt);

        cout << rp << ' ' << rm << '\n';
    }
}