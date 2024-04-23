#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, cur = 1, count = 0;
    cin >> n;
    for (int i = 3; cur <= n; i += 2)
        cur += i, ++count;
    cout << count;
}

// 1, 4, 9, 16 - 24
// 1, 4, 9, 16, 25, 36 - 42
// 3, 5, 7, 9, 11