#include <algorithm>
#include <iostream>
#include <utility>

using namespace std;

bool cmp1(pair<int, int> &a, pair<int, int> &b) {
    return a.first > b.first ? 1 : 0;
}

int main() {
    vector<pair<int, int>> array(8);
    short sum{}, cnt{};
    for (auto &i : array) {
        cin >> i.first;
        i.second = cnt++;
    }
    
    sort(array.begin(), array.end(), cmp1);

    vector<int> index(5);
    for (short i{}; i < 5; ++i) {
        sum += array[i].first;
        index[i] = array[i].second;
    }

    sort(index.begin(), index.end());

    cout << sum << '\n';
    for (short i{}; i < 5; ++i)
        cout << index[i]+1 << ' ';
}