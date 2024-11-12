#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    queue<int> q, rq;
    for (int i = 1; i <= n; ++i)
        q.push(i);

    while (!q.empty()) {
        int top;

        for (int i = 1; i <= k; ++i) {
            top = q.front();
            q.pop();
            if (i != k)
                q.push(top);
        }

        rq.push(top);
    }

    cout << '<';
    while (1) {
        cout << rq.front();
        rq.pop();
        if (!rq.empty())
            cout << ", ";
        else
            break;
    }
    cout << '>';
}