#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    short tmp, total = 0;
    for (short i = 0; i < 5; ++i, total += tmp) {
        cin >> tmp;
        if (tmp < 40) tmp = 40;
    }
    cout << total/5;
}