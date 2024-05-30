#include <iostream>
#include <vector>
#include <deque>

using namespace std;

void backtracking(const short &n, const short &m, short depth = 0) {
    static deque<bool> visited(n+1, 0);
    static vector<short> result(m);

    if (depth == m) {
        for (auto &i : result)
            cout << i << ' ';
        cout << '\n';
        return;
    } // 종료 조건

    for (short i = 1; i <= n; ++i) {
        if (!visited[i]) {
            visited[i] = 1;
            result[depth] = i;
            backtracking(n, m, depth+1);
            visited[i] = 0;
        }
    }
}

int main() {
    short n, m;
    cin >> n >> m;
    backtracking(n, m);
}