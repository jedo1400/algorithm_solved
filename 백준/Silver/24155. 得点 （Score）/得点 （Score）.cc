#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<pair<int, int>> array(n, {0, 0});
    vector<int> sorted;

    for (auto &i : array) {
        cin >> i.first;
        sorted.push_back(i.first);
    }

    sort(sorted.begin(), sorted.end(), greater<>());

    int cur = 1;
    for (auto &i : sorted) {
        int cnt{};
        for (auto &j : array)
            if (j.first == i && !j.second)
                j.second = cur, ++cnt;
        cur += cnt;
    }

    for (auto &i : array)
        cout << i.second << '\n';
}