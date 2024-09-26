#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

bool cmp(pair<int, int> &a, pair<int, int> &b) {
    if (a.first > b.first)
        return 1;
    else if (a.first == b.first)
        return (a.second > b.second ? 1 : 0);
    else
        return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    vector<pair<int, int>> array(n);

    for (auto &i : array)
        cin >> i.first >> i.second;
    
    sort(array.begin(), array.end(), cmp);

    int lastest_meeting{}, result{};
    for (auto &i : array) {
        if (lastest_meeting && lastest_meeting < i.second) continue;
        ++result, lastest_meeting = i.first;
    }

    cout << result;
}
