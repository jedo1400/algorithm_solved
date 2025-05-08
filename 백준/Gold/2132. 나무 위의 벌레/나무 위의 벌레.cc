#include <algorithm>
#include <iostream>
#include <utility>
#include <cstring>
#include <vector>

using namespace std;

vector<int> fruit;
vector<vector<int>> tree;

pair<int, int> dfs(int s, int dist = 0, int prev = 0) { // 임의의 정점 s로부터 가장 먼 e 구하기
    pair<int, int> result = {s, dist};

    for (auto &i : tree[s]) {
        if (i == prev)
            continue;

        auto p = dfs(i, dist + fruit[i], s);

        if (p.second > result.second)
            result = p;
        else if (p.second == result.second && p.first < result.first) // 답이 여러 개 있을 경우에는 정점의 번호가 가장 작은 경우를 출력한다.
            result = p;
    }
    
    return result;
}

void solve() {
    int s = dfs(1, fruit[1]).first;
    auto [e, d] = dfs(s, fruit[s]);

    // 답이 여러 개 있을 경우에는 정점의 번호가 가장 작은 경우를 출력한다 2
    cout << d << ' ' << min(s, e); 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    fruit.resize(n+1);
    tree = vector<vector<int>>(n+1, vector<int>());

    for (int i = 1; i <= n; ++i)
        cin >> fruit[i];

    while (--n) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b); 
        tree[b].push_back(a);
    }

    solve();
}