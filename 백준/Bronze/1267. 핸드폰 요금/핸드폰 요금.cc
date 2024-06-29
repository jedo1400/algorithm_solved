#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    short n, call, y = 0, m = 0;
    cin >> n;

    for (short i = 0; i < n; ++i) {
        cin >> call;
        y += ((call/30)+1) * 10
        , m += ((call/60)+1) * 15;
    }

    if (y == m)
        cout << "Y M " << y;
    else
        cout << (y > m ? 'M' : 'Y') << ' ' << (y > m ? m : y);
}