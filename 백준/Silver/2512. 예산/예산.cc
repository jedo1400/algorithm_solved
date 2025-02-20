#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int decision(vector<int> &v, int n, int m) {
    int r{};

    for (auto &i : v)
        r += i > m ? m : i;
    
    return r <= n;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n;
    vector<int> list(n);

    int l = 1, r{};
    for (auto &i : list) {
        cin >> i;
        r = max(r, i);
    }
    
    cin >> m;

    while (l <= r) {
        int mid = (l + r) / 2;

        if (decision(list, m, mid))
            l = mid + 1;
        else
            r = mid - 1;
    }

    cout << r;
}
