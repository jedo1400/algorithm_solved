#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
#include <string>

using namespace std;

int n;
vector<pair<char, char>> v;

int backtrack(int idx = 0) {
    static vector<int> r(n);
    static bool used[10]{0,};

    if (idx == n) {
        int c = 0;
        
        for (int i = 1; i < n; ++i)
            if (v[r[i-1]].second != v[r[i]].first)
                ++c;

        return c;
    }

    int result = 1e9;

    for (int i = 0; i < n; ++i)
        if (!used[i]) {
            r[idx] = i, used[i] = 1;
            result = min(result, backtrack(idx+1));
            used[i] = 0;
        }
    
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    v.resize(n);

    int result = 0;

    for (auto &i : v) {
        string str;
        cin >> str;
        
        int diff = 0;
        char before = str[0];
        for (int j = 1; j < str.length(); ++j)
            if (before != str[j])
                ++diff, before = str[j];

        i = {str.front(), str.back()}
        , result += diff;
    }

    cout << backtrack() + result;
}