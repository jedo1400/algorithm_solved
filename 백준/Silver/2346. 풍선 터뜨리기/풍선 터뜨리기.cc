#include <iostream>
#include <deque>

using namespace std;

int main() {
    short n;
    cin >> n;

    deque<pair<int, short>> dq;
    for (short i = 1; i <= n; ++i) {
        int m;
        cin >> m;
        dq.push_back(make_pair(m, i));
    }

    while (dq.size() != 1) {
        cout << dq.front().second << ' ';
        int m = dq.front().first;
        dq.pop_front();

        if (m > 0)
            while (m != 1) {
                --m;
                dq.push_back(dq.front());
                dq.pop_front();
            }
        
        else
            while (m) {
                ++m;
                dq.push_front(dq.back());
                dq.pop_back();
            }
    }

    cout << dq.front().second;
}