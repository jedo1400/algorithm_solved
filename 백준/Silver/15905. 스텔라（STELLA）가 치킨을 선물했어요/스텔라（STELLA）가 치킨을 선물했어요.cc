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
    vector<pair<int, int>> scoreboard(n);

    for (auto &i : scoreboard)
        cin >> i.first >> i.second;
    
    sort(scoreboard.begin(), scoreboard.end(),
    [](pair<int, int> &a, pair<int, int> &b) -> bool {
        if (a.first != b.first)
            return a.first > b.first;
        return b.second > a.second;
    });

    int i;
    for (i = 5; i < scoreboard.size(); ++i)
        if (scoreboard[i].first != scoreboard[4].first)
            break;
    
    cout << i-5;
}