#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, p, t;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> p >> t;
        cout << (long long)p - t/7 + t/4 << '\n';
    }
}