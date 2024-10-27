#include <iostream>
#include <utility>
#include <queue>

using namespace std;

short bfs(int &a, int &b) {
    // 일의 자리가 1인 수는 2의 배수가 될 수 없고 감산하는 경우가 없으므로 방문 확인이 불필요
    queue<pair<long, short>> waitlist; // 1

    waitlist.push(make_pair(a, 1));

    while (!waitlist.empty()) {
        auto top = waitlist.front();
        waitlist.pop();

        if (top.first == b)
            return top.second;

        else if (top.first < b) {
            waitlist.push(make_pair(top.first*10+1, top.second+1));
            waitlist.push(make_pair(top.first*2, top.second+1));
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b;
    cin >> a >> b;
    cout << bfs(a, b);
}