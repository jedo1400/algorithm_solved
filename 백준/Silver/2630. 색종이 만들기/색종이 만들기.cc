#include <iostream>
#include <utility>
#include <deque>

using namespace std;

bool isCompleted(deque<deque<bool>> &array, short x, short y, short size) {
    bool start = array[y][x];
    for (short i = y; i < y+size; ++i)
        for (short j = x; j < x+size; ++j)
            if (array[i][j] != start)
                return 0;
    return 1;
}

void split(deque<deque<bool>> &array, short x, short y, short size, pair<short, short> &result) {
    if (isCompleted(array, x, y, size)) {
        ++(array[y][x] ? result.second : result.first);
        return;
    }
    
    short w = size/2;
    split(array, x, y, w, result);
    split(array, x+w, y, w, result);
    split(array, x, y+w, w, result);
    split(array, x+w, y+w, w, result);
}

int main() {
    short n;
    pair<short, short> result = make_pair(0, 0);
    cin >> n;
    deque<deque<bool>> array(n, deque<bool>(n));

    for (auto &i : array)
        for (auto &j : i)
            cin >> j;

    split(array, 0, 0, n, result);
    cout << result.first << '\n' << result.second;
}