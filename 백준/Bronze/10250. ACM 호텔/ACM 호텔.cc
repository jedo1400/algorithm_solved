#include <iostream>

using namespace std;

int main() {
    short t, h, w, n;
    cin >> t;
    for (short i = 0; i < t; ++i) {
        cin >> h >> w >> n;
        if (!(n % h))
            cout << h*100 + (n/h);
        else
            cout << n%h*100 + n/h+1;
        cout << '\n';
    }
}