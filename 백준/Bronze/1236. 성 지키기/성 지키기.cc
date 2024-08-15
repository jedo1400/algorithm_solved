#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    short n, m, count{};
    cin >> n >> m;
    bool* h_guard = new bool[m]{};

    for (short i = 0; i < n; ++i) {
        bool flag{};
        for (short j = 0; j < m; ++j) {
            char c;
            cin >> c;

            if (c == 'X')
                h_guard[j] = 1, flag = 1;
        }
        count += flag ? 0 : 1;
    }

    short h_empty{};
    for (short i = 0; i < m; ++i)
        h_empty += h_guard[i] ? 0 : 1;

    cout << (count > h_empty ? count : h_empty);
}