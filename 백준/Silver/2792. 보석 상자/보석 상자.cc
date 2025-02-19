#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int decision(vector<int> &v, int n, int m) {
    int r{};

    for (auto &i : v)
        r += i / m + (i % m ? 1 : 0);
    
    return r <= n;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<int> jewels(m);

    int l = 1, r{};
    for (auto &i : jewels) {
        cin >> i;
        r = max(r, i);
    }

    while (l <= r) {
        int mid = (l + r) / 2;

        if (decision(jewels, n, mid))
            r = mid - 1;
        else
            l = mid + 1;
    }

    cout << l;
}
