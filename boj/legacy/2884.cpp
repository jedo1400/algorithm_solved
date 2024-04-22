#include <iostream>

using namespace std;

int main() {
    short h, m;
    cin >> h >> m;
    m += h*60-45
    , h = m/60
    , m %= 60;
    if (h == 0 && m < 0)
        h += 23, m += 60;
    cout << h << ' ' << m;
}