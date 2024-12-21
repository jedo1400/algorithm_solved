#include <iostream>
#include <utility>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> map(n, vector<int>(n));
    pair<int, int> p1 = {-1, -1}, p2 = {-1, -1};
    int cnt{};

    for (int i{}; i < n; ++i)
        for (int j{}; j < n; ++j) {
            cin >> map[i][j];

            if (map[i][j] == 2) // 성규가 앉아있다면
                p1 = {j, i}; // x, y
            else if (map[i][j] == 5) // 교수님이 앉아있다면
                p2 = {j, i};
        }
    
    int dist = sqrt(pow(p1.first-p2.first, 2) + pow(p1.second-p2.second, 2));
    
    if (p2.first < p1.first) {
        int swap = p1.first;
        p1.first = p2.first
        , p2.first = swap;
    }

    if (p2.second < p1.second) {
        int swap = p1.second;
        p1.second = p2.second
        , p2.second = swap;
    }

    for (int i = p1.second; i <= p2.second; ++i)
        for (int j = p1.first; j <= p2.first; ++j)
            if (map[i][j] == 1)
                ++cnt; 

    cout << (cnt >= 3 && dist >= 5 ? 1 : 0);
}