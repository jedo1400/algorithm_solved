#include <iostream>
#include <utility>
#include <vector>
#include <deque>

using namespace std;

vector<pair<short, short>> getDirections() {
    vector<pair<short, short>> direction;
    direction.push_back(make_pair(1, 0)); // 동
    direction.push_back(make_pair(-1, 0)); // 서
    direction.push_back(make_pair(0, -1)); // 남
    direction.push_back(make_pair(0, 1)); // 북
    return direction;
}

bool dfs(deque<deque<bool>> &array, short &w, short x, short y) {
    static vector<pair<short, short>> direction = getDirections();
    if (!array[y][x])
        return 0;

    array[y][x] = 0;
    
    for (auto &i : direction) {
        short x_moved = x+i.first, y_moved = y+i.second;
        if (x_moved >= 0 && x_moved < w && y_moved >= 0 && y_moved < array.size())
            dfs(array, w, x_moved, y_moved);
    }

    return 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    short t;
    cin >> t;
    while (t--) {
        short w, h, k;
        cin >> w >> h >> k;
        deque<deque<bool>> array(h, deque<bool>(w, 0));
        
        for (short i = 0; i < k; ++i) {
            short a, b;
            cin >> a >> b;
            array[b][a] = 1;
        }
        
        int result{};
        
        for (short i = 0; i < h; ++i)
            for (short j = 0; j < w; ++j)
                result += dfs(array, w, j, i);
        
        cout << result << '\n';
    }
}