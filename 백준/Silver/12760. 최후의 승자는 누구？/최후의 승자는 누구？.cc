#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> cards(n, vector<int>(m));
    vector<int> score(n, 0);

    for (auto &i : cards) {
        for (auto &j : i)
            cin >> j;
        sort(i.begin(), i.end());
    }

    for (int i{}; i < m; ++i) { // 행
        vector<int> win;
        int largest{};

        for (int j{}; j < n; ++j) {// 열
            if (cards[j][i] > largest) {
                win.clear();
                largest = cards[j][i];
            }

            if (cards[j][i] == largest)
                win.push_back(j);
        }

        for (auto &i : win)
            ++score[i];
    }

    vector<int> winner;
    int largest{};

    for (int i{}; i < n; ++i) {
        if (score[i] > largest) {
            winner.clear();
            largest = score[i];
        }

        if (score[i] == largest)
            winner.push_back(i);
    }

    for (auto &i : winner)
        cout << i+1 << ' ';
}