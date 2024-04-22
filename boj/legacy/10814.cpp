#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

bool compare(pair<int, string> a, pair<int, string> b) {
    return a.first < b.first;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<pair<int, string>> array(n);

    for (int i = 0; i < n; ++i)
        cin >> array[i].first >> array[i].second;

    stable_sort(array.begin(), array.end(), compare);

    for (int i = 0; i < n; ++i)
        cout << array[i].first << ' ' << array[i].second << '\n';
}