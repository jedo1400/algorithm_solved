#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<pair<int, int>> lines(n);

    for (auto &i : lines)
        cin >> i.first >> i.second;
    
    if (n == 1) {
        cout << 1;
        return 0;
    }

    sort(lines.begin(), lines.end(),
    [](pair<int, int> &a, pair<int, int> &b) -> bool {
        if (a.first == b.first)
            return a.second < b.second;
        return a.first < b.first;
    });

    priority_queue<int, vector<int>, greater<int>> pq;
    int result{};

    pq.push(lines[0].second);

    for (int i = 1; i < n; ++i) {
        // 만약 선분의 끝점이 담긴 우선순위 큐의 가장 작은 값보다 다음 선분의 시작점이 뒤에 있는 경우
        while (!pq.empty() && pq.top() <= lines[i].first)
            pq.pop(); // 그렇지 않게 될 때까지 비우기

        pq.push(lines[i].second);
        result = max(result, (int)pq.size());
    }

    cout << result;
}