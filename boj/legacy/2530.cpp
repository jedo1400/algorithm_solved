#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int h, m, s, input;
    cin >> h >> m >> s >> input;
    h += input / 3600, input %= 3600
    , m += input / 60, input %= 60
    , s += input;
    if (s >= 60)
        m += s / 60, s %= 60;
    if (m >= 60)
        h += m / 60, m %= 60;
    cout << h % 24 << ' ' << m << ' ' << s;
}