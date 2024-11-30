#include <iostream>
#include <vector>
#include <deque>

using namespace std;

void pipe(vector<vector<int>> &map, int &result, int x = 1, int y = 0, int direction = 2) {
    // static deque<deque<bool>> visited(map.size(), deque<bool>(map.size(), 0));
    // 가로일땐 가로(2) 또는 대각선(4), 세로일땐 세로(3) 또는 대각선(4), 대각선일땐 2, 3, 4
    // 1은 장애물
    if (y < 0 || y >= map.size() || x < 0 || x >= map.size()) // 좌표가 크기를 초과한 경우
        return;

   if (map[y][x] || (direction == 4 && (map[y][x-1] || map[y-1][x]))) // 장애물 위치거나 대각선 조건 만족하지 못하는 경우
        return;

    if (y == map.size()-1 && x == map.size()-1) { // 종점에 도달한 경우 (n, n)
        ++result;
        return;
    }

    // 종료 조건 끝----

    switch(direction) {
        case 2:
            pipe(map, result, x+1, y, 2); // 가로
            pipe(map, result, x+1, y+1, 4); // 대각선
            break;
        case 3:
            pipe(map, result, x, y+1, 3); // 세로
            pipe(map, result, x+1, y+1, 4); // 대각선
            break;
        case 4:
            pipe(map, result, x+1, y, 2); // 가로
            pipe(map, result, x, y+1, 3); // 세로
            pipe(map, result, x+1, y+1, 4); // 대각선
    }
}

int main() {
    int n; // n <= 16
    cin >> n;

    vector<vector<int>> map(n, vector<int>(n)); // 방해물 1, 가로 2, 대각선 3, 세로 4

    for (auto &i : map)
        for (auto &j : i)
            cin >> j;

    int result{};
    pipe(map, result);
    cout << result;
}