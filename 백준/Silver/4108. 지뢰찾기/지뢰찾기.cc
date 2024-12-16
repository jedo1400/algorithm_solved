#include <iostream>
#include <deque>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int r, c;

    do {
        cin >> r >> c;
        deque<deque<bool>> array(r, deque<bool>(c));

        for (auto &i : array)
            for (auto &j : i) {
                char tmp;
                cin >> tmp;
                j = (tmp == '*' ? 1 : 0);
            }

        for (int i{}; i < r; ++i) {
            for (int j{}; j < c; ++j) {
                if (!array[i][j]) {
                    static const int surround[][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1} };
                    int cnt{};

                    for (int k{}; k < 8; ++k) {
                        int t_x = j + surround[k][0], t_y = i + surround[k][1];
                        if (t_x >= 0 && t_x < c && t_y >= 0 && t_y < r && array[t_y][t_x])
                            ++cnt;
                    }

                    cout << cnt;
                } else // 지뢰인 경우
                    cout << '*';
            }
            cout << '\n';
        }
    } while (r && c);
}