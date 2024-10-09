#include <iostream>
#include <utility>
#include <vector>
#include <deque>

using namespace std;

void dfs(vector<vector<char>> &array, deque<deque<bool>> &visited, short x, short y) {
    static short direction[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
    
    for (short i = 0; i < 4; ++i) {
        short mx = x + direction[i][0], my = y + direction[i][1];
        if (mx >= 0 && (unsigned short)mx < array[0].size() && my >= 0 && (unsigned short)my < array.size() && !visited[my][mx]) {
            visited[my][mx] = 1;
            dfs(array, visited, mx, my);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    short n, m;
    cin >> n >> m;
    vector<pair<short, short>> person;
    vector<vector<char>> array(n, vector<char>(m));
    deque<deque<bool>> visited(n, deque<bool>(m, 0));

    int result{};
    short x, y;
    for (short i = 0; i < n; ++i)
        for (short j = 0; j < m; ++j) {
            cin >> array[i][j];
            if (array[i][j] == 'I')
                x = j, y = i;
            else if (array[i][j] == 'P')
                person.push_back(make_pair(j, i));
            else if (array[i][j] == 'X')
                visited[i][j] = 1;
        }
    
    dfs(array, visited, x, y);
    
    for (auto &i : person)
        if (visited[i.second][i.first])
            ++result;
    
    if (result) cout << result;
    else cout << "TT";
}