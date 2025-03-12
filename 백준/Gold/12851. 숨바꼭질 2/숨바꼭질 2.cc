#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
#include <queue>


#define INF (unsigned int)(1 << 31) - 1

using namespace std;

pair<int, int> bfs(int n, int k) {
    queue<pair<int, int>> waitlist;
    int shortest = INF, cnt{}
        , farthest = max(n, k);
    vector<int> visited(farthest*2 + 1, INF);
    // 방문할 수 있는 가장 빠른 시간을 기록
    
    waitlist.push({n, 0});
    visited[n] = 0;

    while (!waitlist.empty()) {
        auto [cur, time] = waitlist.front();
        waitlist.pop();

        if (cur == k) {
            if (shortest > time) // 목적지에 도착했고, shortest가 time보다 짧다면
                shortest = time, cnt = 1;
            else if (shortest == time) // 걸린 시간이 최단 시간과 같다면
                ++cnt;
        }
        if (shortest < time) // 만약 걸린 시간이 최단 시간보다 길다면
            continue;

        if (cur-1 >= 0 && time+1 <= visited[cur-1]) {
            visited[cur-1] = cur-1 == k ? INF : min(visited[cur-1], time+1);
            waitlist.push({cur-1, time+1});
        }

        if (cur+1 <= k*2 && time+1 <= visited[cur+1]) {
            visited[cur+1] = cur+1 == k ? INF : min(visited[cur+1], time+1);
            waitlist.push({cur+1, time+1});
        } 

        if (2*cur <= 2*farthest && time+1 <= visited[2*cur]) {
            visited[2*cur] = 2*cur == k ? INF : min(visited[2*cur], time+1);
            waitlist.push({2*cur, time+1});
        }
    }

    return {shortest, cnt};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    auto result = bfs(n, k);
    cout << result.first << '\n' << result.second;
}