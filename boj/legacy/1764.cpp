#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

bool compare(const string &a, const string &b) {
    return a < b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, cnt = 0;
    string tmp;
    cin >> n >> m;
    map<string, bool> dud;
    vector<string> dudbo;
    for (int i = 0; i < n; ++i) {
        cin >> tmp;
        dud[tmp] = 1;
    }

    for (int i = 0; i < m; ++i) {
        cin >> tmp;
        if (dud[tmp]) cnt++, dudbo.push_back(tmp);
    }

    sort(dudbo.begin(), dudbo.end(), compare);

    cout << cnt;
    for (int i = 0; i < cnt; ++i)
        cout << '\n' << dudbo[i];
}