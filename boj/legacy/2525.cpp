#include <iostream>

using namespace std;

int main() {
    short h, m, t;
    cin >> h >> m >> t;
    m += h*60+t
    , h = m/60
    , m %= 60;
    if (h >= 24)
        h %= 24;
    cout << h << ' ' << m;
}