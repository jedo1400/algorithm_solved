
#include <algorithm>
#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;

int calc(vector<int> &v, vector<char> &combi) {
    int r = v[0];

    for (int i = 1; i < v.size(); ++i) {
        if      (combi[i-1] == '+') r += v[i];
        else if (combi[i-1] == '-') r -= v[i];
        else if (combi[i-1] == '*') r *= v[i];
        else                        r /= v[i];
    }

    return r;
}

void backtracking(vector<int> &v, vector<int> &w, int n, int &big, int &small) {
    static const char set[4] = { '+', '-', '*', '/' };
    static vector<char> combi;
    
    if (combi.size() == n-1) {
        int r = calc(v, combi);
        big = max(big, r), small = min(small, r);
        return;
    }

    for (int i{}; i < 4; ++i)
        if (w[i]) { // 남아있다면
            --w[i];
            combi.push_back(set[i]);

            backtracking(v, w, n, big, small);

            ++w[i];
            combi.pop_back();
        }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, big = INT_MIN, small = INT_MAX;
    cin >> n;
    vector<int> v(n), w(4);

    for (auto &i : v)
        cin >> i;

    for (auto &i : w)
        cin >> i;

    backtracking(v, w, n, big, small);
    cout << big << '\n' << small;
}