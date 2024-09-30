#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
#include <deque>

using namespace std;

vector<pair<short, short>> getDirection() {
    vector<pair<short, short>> direction; // (y, x)
    direction.push_back(make_pair(0, 1));
    direction.push_back(make_pair(0, -1));
    direction.push_back(make_pair(1, 0));
    direction.push_back(make_pair(-1, 0));

    return direction;
}

short dfs(deque<deque<bool>> &array, short x, short y, bool reset = 1) {
    static vector<pair<short, short>> direction = getDirection();
    static short result{};
    if (reset)
        result = 0;
    
    if (!array[y][x])
        return 0;

    array[y][x] = 0, ++result;

    for (auto &i : direction) {
        short moved_y = y+i.first, moved_x = x+i.second;
        
        if (moved_y >= 0 && moved_y < array.size() 
        && moved_x >= 0 && moved_x < array.size() 
        && array[moved_y][moved_x])
            dfs(array, moved_x, moved_y, 0);
    }

    return result;
}

int main() {
    short n;
    cin >> n;

    deque<deque<bool>> apart(n, deque<bool>(n, 0));

    for (short i = 0; i < n; ++i)
        for (short j = 0; j < n; ++j) {
            char tmp;
            cin >> tmp;
            apart[i][j] = tmp-48;
        }
    
    vector<short> result;
    for (short i = 0; i < n; ++i)
        for (short j = 0; j < n; ++j) {
            short houses = dfs(apart, j, i);
            if (houses)
                result.push_back(houses);
        }

    sort(result.begin(), result.end());
    
    cout << result.size() << '\n';
    for (auto &i : result)
        cout << i << '\n';
}