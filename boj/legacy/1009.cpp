#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, a, b;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> a >> b;

        int k = 1;
        for (int j = 0; j < b; ++j)
            k = (k * a) % 10;
        if (k == 0)
            cout << 10;
        else
            cout << k;
        cout << '\n';
    }
}