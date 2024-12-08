#include <iostream>
#include <vector>
#include <map>

using namespace std;

bool setNextIndex(vector<int> &cur, int size) { // array의 크기 (사용할 수 있는 요소)
    ++cur.back();
    for (int i = cur.size()-1; i; --i) {  // 끝부터 완전탐색
        if (cur[i] >= size) {
            ++cur[i-1];
            if (cur[0] >= size)
                return 1;
            for (int j = i; j < cur.size(); ++j)
                cur[j] = cur[i-1];
        }
        else
            return 0;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    map<int, bool> input;
    vector<int> sorted;

    for (int i = 0; i < n; ++i) {
        int o;
        cin >> o;
        input[o] = 1;
    }

    for (auto &i : input) {
        sorted.push_back(i.first);
        if (m == 1)
            cout << i.first << '\n';
    }
    if (m == 1)
        return 0;

    vector<int> cur(m, 0);
    do {
        for (auto &i : cur)
            cout << sorted[i] << ' ';
        cout << '\n';
    } while (!setNextIndex(cur, sorted.size()));
}