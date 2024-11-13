#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

bool cmp(pair<int, int> &a, pair<int, int> &b) {
    return a.first < b.first;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, l;
    cin >> n >> l;

    vector<pair<int, int>> hole(n);
    for (auto &i : hole)
        cin >> i.first >> i.second;
    
    sort(hole.begin(), hole.end(), cmp);

    int start = hole[0].first, result{};
    for (auto &i : hole) {
        if (start < i.first) start = i.first;
        
        while (start < i.second)
            start += l, ++result;
    }

    cout << result;
}