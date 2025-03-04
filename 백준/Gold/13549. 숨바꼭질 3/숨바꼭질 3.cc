#include <algorithm>
#include <iostream>
#include <vector>
#include <deque>

#define MAX 100000

using namespace std;

int solve(int n, int k) {
    // 가중치가 0, 1(텔레포트 0초, 앞, 뒤 이동 1초)
    // 시간이 들지않는 (공짜)텔레포트하는 경우 먼저 모두 확인하고 시간이 걸리는 앞 뒤 이동을 나중에 확인하기
    // 덱으로 구현함, 만약에 가중치가 2가지 이상이라면 우선순위 큐를 사용하면 될듯
    deque<pair<int, int>> dq;
    deque<bool> visited(MAX + 1, 0);

    dq.push_front({0, n});
    visited[n] = 1;

    while (!dq.empty()) {
        int pos = dq.front().second
            , cost = dq.front().first;
        dq.pop_front();

        if (pos == k) return cost;

        if (pos*2 <= MAX && !visited[pos*2])  { dq.push_front({cost, pos*2}); visited[pos*2] = 1; }
        if (pos-1 >= 0 && !visited[pos-1])   { dq.push_back({cost+1, pos-1}); visited[pos-1] = 1; }
        if (pos+1 <= MAX && !visited[pos+1]) { dq.push_back({cost+1, pos+1}); visited[pos+1] = 1; }
    }

    return -1;
}

int main() {
    int n, k;
    cin >> n >> k;

    cout << solve(n, k);
}