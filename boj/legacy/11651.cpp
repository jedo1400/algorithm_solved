#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool compare(const pair<int, int>& a, const pair<int, int>& b) {
    if (a.second != b.second)
        return a.second < b.second;
    else
        return a.first < b.first;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<pair<int, int>> array(n);

    for (int i = 0; i < n; ++i)
        cin >> array[i].first >> array[i].second;
    
    sort(array.begin(), array.end(), compare);

    for (int i = 0; i < n; ++i)
        cout << array[i].first << ' ' << array[i].second << '\n';
}