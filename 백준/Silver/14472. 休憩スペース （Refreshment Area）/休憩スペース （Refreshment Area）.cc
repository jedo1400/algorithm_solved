#include <algorithm>
#include <iostream>
#include <deque>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, d, result{};
    cin >> n >> m >> d;
    deque<deque<bool>> map(n, deque<bool>(m));

    for (auto &i : map)
        for (auto &j : i) {
            char c;
            cin >> c;
            j = c == '#' ? 1 : 0;
        }
    
    for (int i{}; i < n; ++i)
        for (int j{}; j < m; ++j) {
            if (map[i][j])
                continue;
            
            bool comp_x = 1, comp_y = 1;
            for (int k = 1; k < d; ++k) {
                int x_moved = j+k, y_moved = i+k;
                if (y_moved < 0 || y_moved >= n || map[y_moved][j]) comp_y = 0;
                if (x_moved < 0 || x_moved >= m || map[i][x_moved]) comp_x = 0;
            }
            
            result += comp_y + comp_x;
        }

    cout << result;
}