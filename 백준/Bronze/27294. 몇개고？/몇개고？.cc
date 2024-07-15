#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    short t;
    bool s;
    cin >> t >> s;
    cout << (!s && 12 <= t && t <= 16 ? 320 : 280);
}
