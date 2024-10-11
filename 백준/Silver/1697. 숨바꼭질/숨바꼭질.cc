#include <iostream>
#include <utility>
#include <bitset>
#include <queue>

using namespace std;

int bfs(const int &n, const int &k) {
    bitset<200000> visited;
    visited[n] = 1;
    queue<pair<int, int>> waitlist; // pos, count

    if (n == k)
        return 0;

    if (n-1 >= 0)
        waitlist.push(make_pair(n-1, 1));

    if (n+1 <= k)
        waitlist.push(make_pair(n+1, 1));

    if (n*2 <= k*2)
        waitlist.push(make_pair(n*2, 1));
    
    while (!waitlist.empty()) {
        auto top = waitlist.front();
        waitlist.pop();

        if (!visited[top.first]) { // 노드가 먼저 방문됐다면 최단경로가 아님
            if (top.first == k)
                return top.second;

            if (top.first-1 >= 0)
                waitlist.push(make_pair(top.first-1, top.second+1));

            if (top.first+1 <= k)
                waitlist.push(make_pair(top.first+1, top.second+1));

            if (top.first*2 <= k*2)
                waitlist.push(make_pair(top.first*2, top.second+1));

            visited[top.first] = 1;
        }
    }
    return -1;
}

int main() {
    int n, k; // 100000, 100000
    cin >> n >> k;
    
    cout << bfs(n, k);
}