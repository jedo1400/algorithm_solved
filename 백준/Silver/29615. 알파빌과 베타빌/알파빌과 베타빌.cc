#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    bool friends[1001] = {0,};

    for (int i{}; i < n; ++i) {
        int t;
        cin >> t;
        if (i < m)
            friends[t] = 1;
    }
    
    int result{};
    for (int i{}; i < m; ++i) {
        int f;
        cin >> f;
        result += !friends[f];
    }

    cout << result;
}