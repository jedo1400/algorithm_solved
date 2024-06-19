#include <iostream>
#define u_int unsigned int

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    u_int n;
    unsigned short c, items;
    cin >> n;

    for (u_int i = 0; i < n; ++i) {
        cin >> c >> items;
        cout << c << ' ' << items << '\n' << (items*c)-(2*(c-1)) << '\n';
    }
}