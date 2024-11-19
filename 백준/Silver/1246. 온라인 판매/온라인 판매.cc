#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<int> price(m);

    for (auto &i : price)
        cin >> i;

    sort(price.begin(), price.end());    

    int best{}, idx;
    for (int i = 0; i < m; ++i) {
        int multi = price[i] * (m-i > n ? n : m-i);
        if (multi > best)
            best = multi, idx = price[i];
    }

    cout << idx << ' ' << best;
}