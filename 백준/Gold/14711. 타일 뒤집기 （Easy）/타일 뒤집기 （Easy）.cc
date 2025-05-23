#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n;
vector<vector<char>> v;

void flip(int x, int y) {
    static int w[][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

    for (int i = 0; i < 4; ++i) {
        int mx = x + w[i][0], my = y + w[i][1];

        if (mx >= 0 && mx < n && my >= 0 && my < n)
            v[my][mx] = v[my][mx] == '#' ? '.' : '#';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    v = vector<vector<char>>(n, vector<char>(n, '.'));
    vector<vector<char>> result(n, vector<char>(n, '.'));

    for (int i = 0; i < n; ++i) {
        char c;
        cin >> c;
        if (c == '#') {
            flip(i, 0);
            result[0][i] = '#';
        }
    }

    for (int i = 1; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (v[i-1][j] == '#') {
                flip(j, i);
                result[i][j] = '#';
            }

    for (auto &i : result) {
        for (auto &j : i)
            cout << j;
        cout << '\n';
    }
}